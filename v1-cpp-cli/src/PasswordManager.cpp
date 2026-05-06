#include "PasswordManager.h"

void PasswordManager::handlePasswordManager(AppState& state, int& key) {
	int input;
	std::string username;
	std::cout << "\n Password-Manager" << std::endl;
	std::cout << "===Secure-Vault===" << std::endl;
	std::cout << "[1] Add Password" << std::endl;
	std::cout << "[2] Get Password" << std::endl;
	std::cout << "[3] Delete Password" << std::endl;
	std::cout << "[4] List Passwords" << std::endl;
	std::cout << "[0] Return to menu\n" << std::endl;

	if (!(std::cin >> input)) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid input.\n" << std::endl;
		return;
	}

	switch (input) {
	case 0:
		state = AppState::MAIN_MENU;
		return;
	case 1:
		addPassword(key);
		return;
	case 2:
		std::cin.ignore(10000, '\n');
		std::cout << "Enter username to retrieve password: ";
		std::getline(std::cin, username);
		getPassword(username, key);
		return;
	case 3:
		std::cin.ignore(10000, '\n');
		std::cout << "Enter username to delete password: ";
		std::getline(std::cin, username);
		deletePassword(username, key);
		return;
	case 4:
		listPasswords(key);
		return;	
	}
}

std::string PasswordManager::xorEncryptDecrypt(std::string& input, int key) {
	std::string output = input;
	for (int i = 0; i < input.size(); ++i) {
		output[i] = input[i] ^ key;
	}
	return output;
}

void PasswordManager::addPassword(int& key) {
	std::string site, username, password;
	std::cin.ignore(10000, '\n');
	std::cout << "===Add Password===\n" << std::endl;
	std::cout << "Enter site: ";
	std::getline(std::cin, site);
	std::cout << "Enter username: ";
	std::getline(std::cin, username);
	std::cout << "Enter password: ";
	std::getline(std::cin, password);
	std::cin.ignore(10000, '\n');

	PasswordEntry newEntry = { site, username, password };
	entries.push_back(newEntry);

	std::ofstream outFile("passwords.dat", std::ios::app);
	if (!outFile) {
		std::cout << "Error opening file.\n" << std::endl;
		return;
	}

	outFile << site << "|" << username << "|" << xorEncryptDecrypt(password, key) << "\n";
	outFile.close();
}

void PasswordManager::getPassword(std::string username, int key) {
	std::string site, checkUsername, checkPassword;
	std::ifstream inFile("passwords.dat");
	if (!inFile) {
		std::cout << "Error opening file.\n" << std::endl;
		return;
	}
	while (inFile) {
		std::getline(inFile, site, '|');
		std::getline(inFile, checkUsername, '|');
		std::getline(inFile, checkPassword);

		if (checkUsername == username) {
			std::string decryptedPW = xorEncryptDecrypt(checkPassword, key);
			std::cout << "\nSite: " << site << "\nUsername: " << checkUsername << "\nPassword: " << decryptedPW << "\n" << std::endl;
			return;
		}
	}
	std::cout << "\nNo entry found for that username.\n" << std::endl;
}

void PasswordManager::deletePassword(std::string username, int key) {
	std::string site, checkUsername, checkPassword;
	std::vector<PasswordEntry> tempEntries;

	std::ifstream inFile("passwords.dat");
	if (!inFile) {
		std::cout << "Error opening file.\n" << std::endl;
		return;
	}
	while (inFile) {
		std::getline(inFile, site, '|');
		std::getline(inFile, checkUsername, '|');
		std::getline(inFile, checkPassword);

		if (checkUsername == username) {
			std::string decryptedPW = xorEncryptDecrypt(checkPassword, key);
			std::cout << "\nDeleted entry for site: " << site << "\nUsername: " << checkUsername << "\nPassword: " << decryptedPW << "\n" << std::endl;
			continue;
		}
		else {
			tempEntries.push_back({site, checkUsername, checkPassword});
		}
	}
	inFile.close();

	std::ofstream outFile("passwords.dat");
	if (!outFile) {
		std::cout << "Error opening file.\n" << std::endl;
		return;
	}
	for (const auto& entry : tempEntries) {
		outFile << entry.site << "|" << entry.username << "|" << entry.password << "\n";
	}
	outFile.close();
}

void PasswordManager::listPasswords(int& key) {
	std::string site, username, password;
	std::ifstream inFile("passwords.dat");

	if (!inFile) {
		std::cout << "Error opening file.\n" << std::endl;
		return;
	}

	std::cout << "===Saved Passwords===\n" << std::endl;
	while (inFile) {
		std::getline(inFile, site, '|');
		std::getline(inFile, username, '|');
		std::getline(inFile, password);
		if (!site.empty() && !username.empty() && !password.empty()) {
			std::cout << "Site: " << site << "\nUsername: " << username << "\nPassword: " << xorEncryptDecrypt(password, key) << "\n" << std::endl;
		}
	}
	inFile.close();
}