# 🔐 SecureVault CLI

A console-based security suite built in C++ as a self-directed learning project.
SecureVault combines four modules — password management, strength analysis, 
password generation, and secure notes — all protected by a custom XOR encryption 
system and a user-defined master key.

---

## ✨ Features

- **Password Manager** — add, view, and delete encrypted passwords linked to sites and usernames
- **Password Strength Analyzer** — scores passwords based on length, character variety, and complexity
- **Password Generator** — generates secure random passwords using Mersenne Twister (mt19937)
- **Secure Notes** — store and retrieve personal notes encrypted with your master key
- **Login System** — account creation and authentication with encrypted credentials

---

## 🔒 How It Works

- All sensitive data is encrypted using a custom XOR cipher with a user-defined master key
- Credentials and data are persisted in structured `.dat` files
- The master key is set at account creation and required at every login — without it, all data is unreadable
- Multi-module CLI architecture driven by a centralized App Loop

---

## 🛠️ Built With

- C++17
- OOP — classes, structs, smart pointers (`unique_ptr`)
- File I/O — `fstream`, custom `.dat` format
- `std::mt19937` — Mersenne Twister for secure random generation
- Custom XOR encryption system
- Visual Studio 2026 Community

---

## 📁 Project Structure

SecureVault-CLI/
├── src/
│   ├── main.cpp
│   ├── App.cpp
│   ├── Login.cpp
│   ├── PasswordManager.cpp
│   ├── PasswordStrengthAnalyzer.cpp
│   ├── PasswordGenerator.cpp
│   └── SecureNotes.cpp
├── include/
│   ├── App.h
│   ├── AppState.h
│   ├── Login.h
│   ├── PasswordManager.h
│   ├── PasswordStrengthAnalyzer.h
│   ├── PasswordGenerator.h
│   └── SecureNotes.h
└── README.md

---

## 🚀 How to Use

1. Clone the repository and open the project in Visual Studio
2. Build and run the project
3. Create an account with a username, password, and encryption key
4. Use your credentials to log in and access all modules
5. **Important** — you must remember what your encryption key is. Without it, your data cannot be recovered.

---

## 👤 Author

**Yuman Khoufache** — First-year Computer Science student at Austin Community College.  
Beyond coursework, I actively pursue self-directed learning to strengthen my programming 
fundamentals and build real-world projects. SecureVault CLI is my second C++ project, 
built entirely outside of class to explore OOP architecture, file I/O, and basic cryptography concepts.

The next planned step for this project is a full software remake featuring a Windows GUI — 
using C# and .NET for the front-end interface, with this C++ codebase compiled as a 
backend DLL. The goal will be to build a complete, professional-grade desktop application 
while learning cross-language interoperability.

🔗 [GitHub](https://github.com/YumanKh)

---

## 🙏 Special Thanks

- **Claude (Anthropic)** — technical debugging assistance
- **GitHub Copilot** — occasional code suggestions

---

## 📄 License

© 2026 Yuman Khoufache — Released with no copyright restrictions. Free to use, modify, and distribute.