#include "App.h"

App::App() : isRunning(true), state(AppState::LOGIN_SCREEN), key(0) {
	login = std::make_unique<Login>();
	passwordManager = std::make_unique<PasswordManager>();
	passwordStrengthAnalyzer = std::make_unique<PasswordStrengthAnalyzer>();
	passwordGenerator = std::make_unique<PasswordGenerator>();
	secureNotes = std::make_unique<SecureNotes>();
}

void App::handleMainMenu() {
	int input;
	std::cout << "\n    Main Menu" << std::endl;
	std::cout << "===Secure-Vault===" << std::endl;
	std::cout << "[1] Password Manager" << std::endl;
	std::cout << "[2] Password Strength Analyzer" << std::endl;
	std::cout << "[3] Password Generator" << std::endl;
	std::cout << "[4] Secure Notes" << std::endl;
	std::cout << "[0] Logout\n" << std::endl;

	if (!(std::cin >> input)) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid input.\n" << std::endl;
		return;
	}

	switch (input) {
	case 0:
		state = AppState::LOGIN_SCREEN;
		return;
	case 1:
		state = AppState::PASSWORD_MANAGER;
		return;
	case 2:
		state = AppState::PASSWORD_STRENGTH_ANALYZER;
		return;
	case 3:
		state = AppState::PASSWORD_GENERATOR;
		return;
	case 4:
		state = AppState::SECURE_NOTES;
		return;
	}
}

void App::run() {
	while (isRunning) {
		if (state == AppState::QUIT) isRunning = false;
		else if (state == AppState::LOGIN_SCREEN) login->handleLogin(state, key);
		else if (state == AppState::MAIN_MENU) handleMainMenu();
		else if (state == AppState::PASSWORD_MANAGER) passwordManager->handlePasswordManager(state, key);
		else if (state == AppState::PASSWORD_STRENGTH_ANALYZER) passwordStrengthAnalyzer->handlePasswordStrengthAnalyzer(state);
		else if (state == AppState::PASSWORD_GENERATOR) passwordGenerator->handlePasswordGenerator(state);
		else if (state == AppState::SECURE_NOTES) secureNotes->handleSecureNotes(state, key);
	}
}