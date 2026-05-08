using System;
using System.Collections.Generic;
using System.Text;

namespace SecureVault
{
    public class PasswordStrengthAnalyzer
    {
        private int getLengthLevel(string password)
        {
            int value = password.Length;

            if (value <= 4) return 0;
            else if (value > 4 && value <= 6) return 2;
            else if (value > 6 && value <= 10) return 3;
            else if (value > 10 && value <= 15) return 4;
            else return 5;
        }
        private int getLowLettersLevel(string password)
        {
            int value = password.Count(c => char.IsLower(c));
            
            if (value < 4) return 0;
            else if (value < 6) return 2;
            else if (value > 6 && value < 10) return 3;
            else if (value > 10 && value < 15) return 4;
            else return 5;
        }
        private int getCapLettersLevel(string password)
        {
            int value = password.Count(c => char.IsUpper(c));

            if (value < 4) return 0;
            else if (value < 6) return 2;
            else if (value > 6 && value < 10) return 3;
            else if (value > 10 && value < 15) return 4;
            else return 5;
        }
        private int getDigitsLevel(string password)
        {
            int value = password.Count(c => char.IsDigit(c));

            if (value == 0) return 0;
            else if (value <= 2) return 2;
            else if (value > 2 && value <= 4) return 3;
            else if (value > 4 && value <= 6) return 4;
            else return 5;
        }
        private int getSpecialCharsLevel(string password)
        {
            int value = password.Count(c => char.IsPunctuation(c));

            if (value == 0) return 0;
            else if (value <= 2) return 2;
            else if (value > 2 && value <= 4) return 3;
            else if (value > 4 && value <= 6) return 4;
            else return 5;
        }
        private int analyzePasswordStrength(string password)
        {
            int totalLevel = 0;

            int lengthLevel = getLengthLevel(password);
            int capLettersLevel = getCapLettersLevel(password);
            int lowLettersLevel = getLowLettersLevel(password);
            int digitsLevel = getDigitsLevel(password);
            int specialCharsLevel = getSpecialCharsLevel(password);

            totalLevel = (lengthLevel + capLettersLevel + lowLettersLevel + digitsLevel + specialCharsLevel) * 4; //Multiplied by 4 to get a score out of 100
            return totalLevel;
        }

        public void handlePasswordStrengthAnalyzer()
        {
            int input = -1;
            int passwordStrength = 0;
            string password;

            Console.WriteLine("\nPassword-Strength-Analyzer");
            Console.WriteLine("=======Secure-Vault=======");
            Console.WriteLine("[1] Analyze Password Strength");
            Console.WriteLine("[0] Return to menu\n");

            try { input = int.Parse(Console.ReadLine()); }
            catch (Exception) { Console.WriteLine("Invalid input.\n"); }

            switch (input)
            {
                case 0:
                    App.state = AppState.MAIN_MENU;
                    break;
                case 1:
                    password = Console.ReadLine();
                    passwordStrength = analyzePasswordStrength(password);
                    Console.WriteLine($"Password Strength: {passwordStrength}");
                    break;
            }
        }
    }
}
