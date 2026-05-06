using System;
using System.Security.Cryptography;
using System.Collections.Generic;
using System.Text;
using System.ComponentModel.DataAnnotations;

namespace SecureVault
{
    public class EncryptionService
    {
        private byte[] key;
        private byte[] iv;

        public EncryptionService(string text)
        {
            using (SHA256 sha256 = SHA256.Create())
            {
                key = sha256.ComputeHash(Encoding.UTF8.GetBytes(text));
                iv = sha256.ComputeHash(key).Take(16).ToArray();
            }

            
        }

        public string Encrypt(string text)
        {
            string encrypted_text = "";
            using (Aes aes = Aes.Create())
            {
                aes.Key = key;
                aes.IV = iv;
                byte[] byte_text = aes.EncryptCbc(Encoding.UTF8.GetBytes(text), iv);
                encrypted_text = Convert.ToBase64String(byte_text);
            }
            return encrypted_text;
        }

        public string Decrypt(string text)
        {
            string decrypted_text = "";
            using (Aes aes = Aes.Create())
            {
                aes.Key = key;
                aes.IV = iv;
                byte[] byte_text = Convert.FromBase64String(text);
                decrypted_text = Encoding.UTF8.GetString(aes.DecryptCbc(byte_text, iv));
            }
            return decrypted_text;
        }
    }
}