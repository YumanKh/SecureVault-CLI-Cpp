#include "Login.h"

void Login::handleLogin(AppState& state, int& key) {
	int input;
	std::cout << "\n    Login Menu" << std::endl;
	std::cout << "===Secure-Vault===" << std::endl;
	std::cout << "[1] Login" << std::endl;
	std::cout << "[2] Create Account" << std::endl;
	std::cout << "[0] Exit\n" << std::endl;

	if (!(std::cin >> input)) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid input.\n" << std::endl;
		return;
	}

	switch (input) {
	case 0:
		state = AppState::QUIT;
		return;
	case 1:
		login(state, key);
		return;
	case 2:
		createAccount();
		return;
	}
}

std::string Login::xorEncryptDecrypt(std::string& input, int key) {
	std::string output = input;
	for (int i = 0; i < input.size(); ++i) {
		output[i] = input[i] ^ key;
	}
	return output;
}

void Login::login(AppState& state, int& key) {
	std::string inputUsername, inputPassword, checkUsername, checkPassword;
	int inputKey, checkKey;
	bool found = false;

	std::cin.ignore(10000, '\n');
	std::cout << "===Login===\n" << std::endl;
	std::cout << "Enter username: ";
	std::getline(std::cin, inputUsername);
	std::cout << "Enter password: ";
	std::getline(std::cin, inputPassword);
	std::cout << "Enter encryption key: ";

	if (!(std::cin >> inputKey)) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "\nInvalid input.\n" << std::endl;
		return;
	}

	std::ifstream inFile("users.dat");
	if (!inFile) {
		std::cout << "Error opening file.\n" << std::endl;
		return;
	}

	while (inFile) {
		std::getline(inFile, checkUsername, '|');
		std::getline(inFile, checkPassword, '|');
		inFile >> checkKey;
		inFile.ignore(10000, '\n');

		if (checkUsername == inputUsername) {
			found = true;
			std::string decryptedPW = xorEncryptDecrypt(checkPassword, checkKey);
			if (decryptedPW == inputPassword && checkKey == inputKey) {
				std::cout << "\nLogin successful!\n" << std::endl;
				key = inputKey;
				state = AppState::MAIN_MENU;
			}
			else std::cout << "\nIncorrect password or key.\n" << std::endl;
			return;
		}
	}
	if (!found) std::cout << "\nUsername not found.\n" << std::endl;

	return;
}

void Login::createAccount() {
	std::ofstream outFile("users.dat", std::ios::app);
	if (!outFile) {
		std::cout << "Error opening file.\n" << std::endl;
		return;
	}

	Account newAccount;
	std::cin.ignore(10000, '\n');
	std::cout << "Enter username: ";
	std::getline(std::cin, newAccount.username);
	std::cout << "Enter password: ";
	std::getline(std::cin, newAccount.password);
	std::cout << "Enter encryption key: ";
	std::cin >> newAccount.key;
	std::cin.ignore(10000, '\n');

	std::string encryptedPW = xorEncryptDecrypt(newAccount.password, newAccount.key);
	outFile << newAccount.username << "|" << encryptedPW << "|" << newAccount.key << "\n";
	outFile.close();
}