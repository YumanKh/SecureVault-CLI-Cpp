#include "PasswordGenerator.h"

void PasswordGenerator::handlePasswordGenerator(AppState& appState) {
	int input;
	std::string generatedPassword;
	std::cin.ignore(10000, '\n');

	std::cout << "\n Password-Generator" << std::endl;
	std::cout << "====Secure-Vault====" << std::endl;
	std::cout << "[1] Generate Password" << std::endl;
	std::cout << "[0] Return to menu\n" << std::endl;

	if (!(std::cin >> input)) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid input.\n" << std::endl;
		return;
	}

	switch (input) {
		case 0:
			appState = AppState::MAIN_MENU;
			return;
		case 1:
			int length;
			std::cout << "Enter desired password length: ";

			if (!(std::cin >> length)) {}
			else if (length < 6) {
				std::cout << "Length must be at least 6.\n" << std::endl;
				return;
			}

			generatedPassword = passwordGenerator(length);
			std::cout << "Generated Password: " << generatedPassword << "\n" << std::endl;
			return;
	}
}

std::string PasswordGenerator::passwordGenerator(int length) {
	std::string password;
	const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<> distribution(0, (int)(chars.size() - 1));

	for (int i = 0; i < length; ++i) {
		password += chars[distribution(generator)];
	}

	return password;
}