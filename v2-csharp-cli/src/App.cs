using SecureVault;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;

namespace SecureVault
{
    public class App
    {
        private bool isRunning = false;

        public static AppState state;
        public App()
        { 
            isRunning = true;
            state = AppState.LOGIN_SCREEN;
        }
        public void handleMainMenu()
        {
            int input = -1;
            Console.WriteLine("\n    Main Menu");
            Console.WriteLine("===Secure-Vault===");
            Console.WriteLine("[1] Password Manager");
            Console.WriteLine("[2] Password Strength Analyzer");
            Console.WriteLine("[3] Password Generator");
            Console.WriteLine("[4] Secure Notes");
            Console.WriteLine("[0] Logout\n");

            try
            {
                input = int.Parse(Console.ReadLine());
            } catch (Exception) { Console.WriteLine("Invalid input.\n"); }

            switch (input)
            {
                case 0:
                    state = AppState.LOGIN_SCREEN;
                    break;
                case 1:
                    state = AppState.PASSWORD_MANAGER;
                    break;
                case 2:
                    state = AppState.PASSWORD_STRENGTH_ANALYZER;
                    break;
                case 3:
                    state = AppState.PASSWORD_GENERATOR;
                    break;
                case 4:
                    state = AppState.SECURE_NOTES;
                    break;
            }
        }
        public void Run()
        {
            while (isRunning)
            {
                if (state == AppState.QUIT) { isRunning = false; }
                else if (state == AppState.LOGIN_SCREEN) { new Login().handleLogin(); }
                else if (state == AppState.MAIN_MENU) { handleMainMenu(); }
                else if (state == AppState.PASSWORD_MANAGER) { new PasswordManager().handlePasswordManager(); }
                else if (state == AppState.PASSWORD_STRENGTH_ANALYZER) { new PasswordStrengthAnalyzer().handlePasswordStrengthAnalyzer(); }
                else if (state == AppState.PASSWORD_GENERATOR) { new PasswordGenerator().handlePasswordGenerator(); }
                else if (state == AppState.SECURE_NOTES) { new SecureNotes().handleSecureNotes(); }
            }
        }
    }
}