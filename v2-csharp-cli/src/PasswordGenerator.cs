using System;
using System.Collections.Generic;
using System.Text;

namespace SecureVault
{
    public class PasswordGenerator
    {
        private string passwordGenerator(int length)
        {
            string password = "";
            const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";

            Random random = new Random();
            for (int i = 0; i < length; i++)
            {
                int index = random.Next(0, chars.Length);
                password += chars[index];
            }

            return password;
        }

        public void handlePasswordGenerator()
        {
            int input = -1;

            Console.WriteLine("\n Password-Generator");
            Console.WriteLine("====Secure-Vault====");
            Console.WriteLine("[1] Generate Password");
            Console.WriteLine("[0] Return to menu\n");

            switch (input)
            {
                case 0:
                    App.state = AppState.MAIN_MENU;
                    break;
                case 1:
                    int length = 0;
                    string password;

                    Console.WriteLine("Enter desired password length: ");
                    try
                    {
                        length = int.Parse(Console.ReadLine());
                    }
                    catch (Exception) { Console.WriteLine("You can only enter a number.\n"); }

                    password = passwordGenerator(length);
                    Console.WriteLine($"Generated password: {password}\n");
                    break;
            }
        }
    }
}
