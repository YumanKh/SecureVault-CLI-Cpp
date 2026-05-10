# SecureVault — V2 | C# .NET CLI

> A complete CLI vault application rebuilt from the ground up in C# .NET — featuring AES-256 encryption, a modular OOP architecture, and a multi-account login system. This is the second iteration of SecureVault, and the foundation for a future Windows GUI release.

---

## Why a Monorepo?

This project is part of a **multi-version monorepo** designed to track the full evolution of SecureVault across languages, architectures, and complexity levels.

> **Note:** The git history for V1 (C++ CLI) was lost during the monorepo restructuring. The V1 source code is intact under `v1-cpp-cli/`. This was an unfortunate git incident — not a lack of version control discipline.

After completing V1 in C++, I chose to rebuild SecureVault in C# before moving to a GUI implementation. The goal was to train my C# and .NET skills on a real project with real constraints — not toy examples — before tackling cross-language interoperability in V3.

---

## Planned Versions

| Version | Stack | Status |
|---|---|---|
| V1 — C++ CLI | C++17, XOR encryption, fstream | ✅ Complete |
| V2 — C# CLI | C# .NET 10, AES-256, StreamReader/Writer | ✅ Complete |
| V3 — Windows GUI | C# WPF front-end + C++ backend DLL | 🔄 In progress |
| V4 — Networked | SQL data layer + client/server architecture | 📋 Planned |

---

## What's New in V2

V2 is a significant upgrade over V1 — same feature set, but rebuilt with professional-grade tools and a cleaner architecture:

- **AES-256 encryption** replaces the custom XOR cipher — industry-standard security used in banking, government, and commercial software
- **Deterministic key derivation** via SHA-256 — the master password generates a consistent 256-bit key at every session, no key storage required
- **C# .NET 10** — managed runtime, garbage collection, and a richer standard library
- **LINQ-powered** password strength analysis — concise, expressive, and readable
- **Structured file persistence** — human-readable `|`-delimited format with encrypted payloads

---

## Features

- 🔐 **Login System** — account creation and authentication with AES-256 encrypted credentials
- 🗂️ **Password Manager** — add, retrieve, list, and delete encrypted passwords linked to sites and usernames
- 🔍 **Password Strength Analyzer** — scores passwords out of 100 based on length, uppercase, lowercase, digits, and special characters
- 🎲 **Password Generator** — generates cryptographically varied random passwords with full character set control
- 📝 **Secure Notes** — store and retrieve personal notes encrypted with your master key

---

## How It Works

- The **master password** is hashed via SHA-256 to derive a 256-bit AES key — deterministic and session-consistent
- The **IV** (Initialization Vector) is derived from the key itself — ensuring consistency across sessions without storage
- All sensitive data is encrypted before being written to disk — passwords, notes, and credentials
- Data is persisted in structured `.txt` files using a `field|encrypted_payload` format
- The entire application is driven by a centralized **App Loop** with an `AppState` enum managing navigation

---

## 🔒 Security Model

| Component | V1 (C++) | V2 (C#) |
|---|---|---|
| Encryption | Custom XOR cipher | AES-256 CBC |
| Key derivation | User-defined integer key | SHA-256 from master password |
| IV | None | Derived from key via SHA-256 |
| Persistence | `.dat` files | `.txt` files with encrypted payloads |

---

## Built With

- **C# .NET 10**
- **AES-256 CBC** — `System.Security.Cryptography`
- **SHA-256** — deterministic key derivation
- **LINQ** — password strength analysis
- **StreamReader / StreamWriter** — file persistence
- **OOP** — classes, structs, properties, enums
- **Visual Studio Community 2022**

---

## Project Structure

```
v2-csharp-cli/
└── src/
    ├── main.cs
    ├── App.cs
    ├── AppState.cs
    ├── Login.cs
    ├── EncryptionService.cs
    ├── PasswordManager.cs
    ├── PasswordStrengthAnalyzer.cs
    ├── PasswordGenerator.cs
    └── SecureNotes.cs
```

---

## How to Use

1. Clone the repository and open the `.sln` file in Visual Studio
2. Build and run the project (`Ctrl+F5`)
3. Create an account with a username and master password
4. Log in — your master password generates the AES key for the session
5. Navigate the menu to access all modules
6. **Important** — your master password is the only key to your data. It is never stored. Without it, all encrypted data is unrecoverable.

---

## What's Next — V3

V3 will be a full **Windows desktop application** built with:
- **C# WPF** — front-end GUI with a professional interface
- **C++ DLL** — the encryption and core logic compiled as a native backend
- **P/Invoke** — cross-language interoperability between C# and C++

The goal is to build a complete, polished desktop application that demonstrates cross-language architecture — and to raise the professional score significantly above V2.

---

## Author

**Yuman Khoufache** — First-year Computer Science student, self-directed learner, and aspiring multi-domain developer.

Beyond coursework, I build real projects to explore OOP architecture, cryptography, file I/O, and software design. SecureVault V2 is part of a long-term portfolio strategy targeting software development, game development, and AI — across C++, C#, and Python.

> *"I don't just want to know how to program — I want a future as a professional developer."*

---

## Special Thanks

- **Claude (Anthropic)** — technical guidance and C# instruction
- **GitHub Copilot** — occasional syntax suggestions

---

## License

© 2026 Yuman Khoufache — No copyright restrictions. Free to use, modify, and distribute.

---

🔗 [GitHub](https://github.com/YumanKh) | [V1 — C++ CLI](../v1-cpp-cli/) | V3 — Coming Soon
