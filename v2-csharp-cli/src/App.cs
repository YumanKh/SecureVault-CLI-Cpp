using SecureVault;
using System;
using System.Collections.Generic;
using System.Text;

namespace SecureVault
{
    public class App
    {
        private bool isRunning = false;
        private AppState state;
        private int Key;

        public App()
        { 
            isRunning = true;
            state = AppState.LOGIN_SCREEN;
            Key = 0;
        }
        public void handleMainMenu()
        {

        }
        public void Run()
        {
            while (isRunning)
            {

            }
        }
    }
}