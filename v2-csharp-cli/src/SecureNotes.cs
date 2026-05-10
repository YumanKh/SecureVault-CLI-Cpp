using System;
using System.Collections.Generic;
using System.Text;

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
    }
}
