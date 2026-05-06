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
        private AppState state;

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
                
            }
            
        }
        public void Run()
        {
            while (isRunning)
            {
                if (state == AppState.QUIT) { isRunning = false;}

            }
        }
    }
}