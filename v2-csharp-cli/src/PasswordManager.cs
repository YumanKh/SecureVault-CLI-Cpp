using System;
using System.Collections.Generic;
using System.Text;

namespace SecureVault
{
    public struct PasswordEntry
    {
        public string Website { get; set; }
        public string Username { get; set; }
        public string Password { get; set; }
    }

    public class PasswordManager
    {
        public void handlePasswordManager()
        {
            int input = -1;
            Console.WriteLine("\n Password Manager");
            Console.WriteLine("===Secure-Vault===");
            Console.WriteLine("[1] Add Password");
            Console.WriteLine("[2] Get Password");
            Console.WriteLine("[3] List Passwords");
            Console.WriteLine("[4] Delete Password");
            Console.WriteLine("[0] Return to menu\n");

            try { input = int.Parse(Console.ReadLine()); }
            catch (Exception) { Console.WriteLine("Invalid input.\n"); }

            switch (input)
            {
                case 0:
                    App.state = AppState.MAIN_MENU;
                    break;
                case 1:
                    addPassword();
                    break;
                case 2:
                    getPassword();
                    break;
                case 3:
                    listPassword();
                    break;
                case 4:
                    deletePassword();
                    break;
            }
        }
        public void addPassword()
        {
            string website, username, password, encrypted_password;

            Console.WriteLine("\n Password Manager");
            Console.WriteLine("===Add Password===");
            Console.Write("Enter site: ");
            website = Console.ReadLine();
            Console.Write("Enter username: ");
            username = Console.ReadLine();
            Console.Write("Enter password: ");
            password = Console.ReadLine();

            encrypted_password = Login.encryption.Encrypt(password);

            try
            {
                using (StreamWriter writer = new StreamWriter("passwords.txt", true))
                {
                    writer.WriteLine($"{website}|{username}|{encrypted_password}");
                }
            }
            catch (Exception) { Console.WriteLine("Error saving password: could not open file.\n"); }
        }
        public void getPassword()
        {
            string website, username, encrypted_password, decrypted_password;

            Console.WriteLine("\n Password Manager");
            Console.WriteLine("===Get Password===");
            Console.Write("Enter site: ");
            website = Console.ReadLine();
            Console.Write("Enter username: ");
            username = Console.ReadLine();

            try
            {
                using (StreamReader reader = new StreamReader("passwords.txt"))
                {
                    string line;
                    bool found = false;

                    while ((line = reader.ReadLine()) != null)
                    {
                        string[] parts = line.Split('|');
                        if (parts.Length == 3 && parts[0] == website && parts[1] == username)
                        {
                            found = true;
                            encrypted_password = parts[2];
                            decrypted_password = Login.encryption.Decrypt(encrypted_password);
                            Console.WriteLine($"Password for {website} ({username}): {decrypted_password}\n");
                            break;
                        }
                    }
                    if (!found) { Console.WriteLine("No password found for that site and username.\n"); }
                }
            } catch(Exception) { Console.WriteLine("Error: file not found.\n"); }
        }
        public void listPassword()
        {
            string website, username, password;
            List<PasswordEntry> entries = new List<PasswordEntry>();

            try
            {
                using (StreamReader reader = new StreamReader("passwords.txt"))
                {
                    string line;
                    while ((line = reader.ReadLine()) != null)
                    {
                        string[] parts = line.Split('|');
                        if (parts.Length == 3)
                        {
                            website = parts[0];
                            username = parts[1];
                            password = Login.encryption.Decrypt(parts[2]);

                            entries.Add(new PasswordEntry
                            {
                                Website = website,
                                Username = username,
                                Password = password
                            });
                        }
                    }
                    foreach (PasswordEntry entry in entries) { Console.WriteLine($"Password for {entry.Website} ({entry.Username}): {entry.Password}");}
                }
            } catch (Exception) { Console.WriteLine("Error: file not found.\n"); }
        }
        public void deletePassword() 
        { 
            string website, username, password;
            List<PasswordEntry> entries = new List<PasswordEntry>();

            Console.WriteLine("Enter website and username to delete the password.");
            Console.Write("Enter website: ");
            website = Console.ReadLine();
            Console.Write("Enter username: ");
            username = Console.ReadLine();

            try
            {
                using (StreamReader reader = new StreamReader("passwords.txt"))
                {
                    string line;
                    bool found = false;
                    while ((line = reader.ReadLine()) != null)
                    {
                        string[] parts = line.Split('|');
                        if (parts.Length == 3)
                        {
                            if (parts[0] != website || parts[1] != username)
                            {
                                string fileWebsite = parts[0];
                                string fileUsername = parts[1];
                                string filePassword = parts[2];

                                entries.Add(new PasswordEntry
                                {
                                    Website = fileWebsite,
                                    Username = fileUsername,
                                    Password = filePassword
                                });
                                found = true;
                            }
                        }
                    }
                    if (found) { Console.WriteLine("\nPassword deleted successfully."); }
                    else { Console.WriteLine("\nCannot find entry."); }
                }
            }
            catch (Exception) { Console.WriteLine("Error: file not found.\n"); }

            try
            {
                using (StreamWriter writer = new StreamWriter("passwords.txt"))
                {
                    foreach (PasswordEntry entry in entries) { writer.WriteLine($"{entry.Website}|{entry.Username}|{entry.Password}"); }
                }
            }
            catch (Exception) { Console.WriteLine("Error: file not found.\n"); }
        }
    }
}