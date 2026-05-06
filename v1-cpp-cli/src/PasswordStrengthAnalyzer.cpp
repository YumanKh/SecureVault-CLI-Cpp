#include "PasswordStrengthAnalyzer.h"

void PasswordStrengthAnalyzer::handlePasswordStrengthAnalyzer(AppState& state) {
	int input;
	std::string password;
	std::cin.ignore(10000, '\n');

	std::cout << "\nPassword-Strength-Analyzer" << std::endl;
	std::cout << "=======Secure-Vault=======" << std::endl;
	std::cout << "[1] Analyze Password Strength" << std::endl;
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
		std::cin.ignore(10000, '\n');
		std::cout << "Enter password to analyze: ";
		std::getline(std::cin, password);
		int strength = analyzePasswordStrength(password);
		std::cout << "Password strength: " << strength << "/100\n" << std::endl;
		return;
	}
	
}

int PasswordStrengthAnalyzer::analyzePasswordStrength(std::string& password) {
	int totalLevel = 0;
	int lengthLevel = getLengthLevel(password);
	int capLettersLevel = getCapLettersLevel(password);
	int lowLettersLevel = getLowLettersLevel(password);
	int digitsLevel = getDigitsLevel(password);
	int specialCharsLevel = getSpecialCharsLevel(password);

	totalLevel = (lengthLevel + capLettersLevel + lowLettersLevel + digitsLevel + specialCharsLevel) * 4; //Multiplied by 4 to get a score out of 100
	return totalLevel;
}

int PasswordStrengthAnalyzer::getLengthLevel(std::string& password) {
	int value = password.size();

	if (value < 4) return 0;
	else if (value < 6) return 2;
	else if (value > 6 && value < 10) return 3;
	else if (value > 10 && value < 15) return 4;
	else return 5;
}

int PasswordStrengthAnalyzer::getLowLettersLevel(std::string& password) {
	int value = 0;
	for (char c : password) {
		if (std::islower(c)) {
			value++;
		}
	}

	if (value == 0) return 0;
	else if (value < 2) return 2;
	else if (value > 2 && value < 4) return 3;
	else if (value > 4 && value < 6) return 4;
	else return 5;
}

int PasswordStrengthAnalyzer::getCapLettersLevel(std::string& password) {
	int value = 0;
	for (char c : password) {
		if (std::isupper(c)) {
			value++;
		}
	}

	if (value == 0) return 0;
	else if (value < 2) return 2;
	else if (value > 2 && value < 4) return 3;
	else if (value > 4 && value < 6) return 4;
	else return 5;
}

int PasswordStrengthAnalyzer::getDigitsLevel(std::string& password) {
	int value = 0;
	for (char c : password) {
		if (std::isdigit(c)) {
			value++;
		}
	}

	if (value == 0) return 0;
	else if (value < 2) return 2;
	else if (value > 2 && value < 4) return 3;
	else if (value > 4 && value < 6) return 4;
	else return 5;
}

int PasswordStrengthAnalyzer::getSpecialCharsLevel(std::string& password) {	
	int value = 0;
	for (char c : password) {
		if (std::ispunct(c)) {
			value++;
		}
	}

	if (value == 0) return 0;
	else if (value < 2) return 2;
	else if (value > 2 && value < 4) return 3;
	else if (value > 4 && value < 6) return 4;
	else return 5;
}