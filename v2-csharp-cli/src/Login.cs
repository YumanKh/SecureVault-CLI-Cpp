using System;
using System.Collections.Generic;
using System.Text;

namespace SecureVault
{
    public struct Account
    {
        string username, password;
        int key;
    }

    public class Login
    {
        private List<Account> accounts;
    }
}
