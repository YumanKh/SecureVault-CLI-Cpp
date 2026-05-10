using System;
using System.Collections.Generic;
using System.Linq.Expressions;
using System.Text;
using static System.Net.Mime.MediaTypeNames;

namespace SecureVault
{
    public class SecureNotes
    {
        public struct NoteEntry
        {
            public string Title {  get; set; }
            public string Content { get; set; }
        }

        public void handleSecureNotes()
        {
            int input = -1;
            Console.WriteLine("\n Secure Notes");
            Console.WriteLine("===Secure-Vault===");
            Console.WriteLine("[1] Add Note");
            Console.WriteLine("[2] Get Note");
            Console.WriteLine("[3] List Note");
            Console.WriteLine("[4] Delete Note");
            Console.WriteLine("[0] Return to menu\n");

            try { input = int.Parse(Console.ReadLine() ); } 
            catch (Exception) { Console.WriteLine("Invalid input.\n");}

            switch (input)
            {
                case 0:
                    App.state = AppState.MAIN_MENU;
                    break;
                case 1:
                    addNote();
                    break;
                case 2:
                    getNote();
                    break;
                case 3:
                    listNotes();
                    break;
                case 4:
                    deleteNote();
                    break;
            }

        }
        public void addNote()
        {
            string title, content, encrypted_content;

            Console.WriteLine("===Add Note===\n");
            Console.Write("Enter note title: ");
            title = Console.ReadLine();
            Console.Write("Enter note content: ");
            content = Console.ReadLine();

            encrypted_content = Login.encryption.Encrypt(content);

            try
            {
                using (StreamWriter writer = new StreamWriter("notes.txt", true))
                {
                    writer.WriteLine($"{title}|{encrypted_content}");
                }
            }
            catch (Exception) { Console.WriteLine("Error: file not found.\n"); }
        }
        public void getNote()
        {
            string title, crypted_content, decrypted_content;

            Console.WriteLine("\n  Secure Notes");
            Console.WriteLine("====Get Note====");
            Console.Write("Enter title: ");
            title = Console.ReadLine();

            try
            {
                using (StreamReader reader = new StreamReader("notes.txt"))
                {
                    string line;
                    bool found = false;

                    while ((line = reader.ReadLine()) != null)
                    {
                        string[] parts = line.Split('|');
                        if (parts.Length == 2 && parts[0] == title)
                        {
                            found = true;
                            crypted_content = parts[1];
                            decrypted_content = Login.encryption.Decrypt(crypted_content);
                            Console.WriteLine($"Note for {title}: {decrypted_content}\n");
                            break;
                        }
                    }
                    if (!found)
                    {
                        Console.WriteLine("No note found for that title.\n");
                    }
                }
            } catch(Exception) { Console.WriteLine("Error reading file.\n"); }
        }
        public void listNotes()
        {
            Console.WriteLine("\n  Secure Notes");
            Console.WriteLine("===List Notes===");

            try
            {
                using (StreamReader reader = new StreamReader("notes.txt"))
                {
                    string line;
                    int count = 0;
                    while ((line = reader.ReadLine()) != null)
                    {
                        string[] parts = line.Split('|');
                        if (parts.Length == 2)
                        {
                            count++;
                            Console.WriteLine($"[{count}] {parts[0]}");
                        }
                    }
                }
            } catch (Exception) { Console.WriteLine("Error: file not found.\n"); }
        }
        public void deleteNote()
        {
            string title, content;
            List<NoteEntry> Notes = new List<NoteEntry>();

            Console.WriteLine("\n  Secure Notes");
            Console.WriteLine("===Delete Note===");
            Console.Write("Enter title: ");
            title = Console.ReadLine();

            try
            {
                using (StreamReader reader = new StreamReader("notes.txt"))
                {
                    string line;
                    bool found = false;

                    while ((line = reader.ReadLine()) != null)
                    {
                        string[] parts = line.Split('|');
                        if (parts.Length == 2 && parts[0] != title)
                        {
                            Notes.Add(new NoteEntry
                            {
                                Title = parts[0],
                                Content = parts[1]
                            });
                        }
                        else if (parts.Length == 2 && parts[0] == title) found = true;
                    }
                    if (!found)
                    {
                        Console.WriteLine("No note found for that title.\n");
                    }

                }
            }
            catch (Exception) { Console.WriteLine("Error: file not found.\n"); }

            try
            {
                using (StreamWriter writer = new StreamWriter("notes.txt"))
                {
                    foreach (NoteEntry entry in Notes) { writer.WriteLine($"{entry.Title}|{entry.Content}"); }
                }
            }
            catch (Exception) { Console.WriteLine("Error: file not found.\n"); }
        }
    }
}
