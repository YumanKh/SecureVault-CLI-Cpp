#pragma once
#include <iostream>
#include "AppState.h"
#include "Login.h"
#include "PasswordManager.h"
#include "PasswordStrengthAnalyzer.h"
#include "PasswordGenerator.h"
#include "SecureNotes.h"

class App {
public:
	App();
	void handleMainMenu();
	void run();

private:
	bool isRunning;
	AppState state;
	int key;

	std::unique_ptr<Login> login;
	std::unique_ptr<PasswordManager> passwordManager;
	std::unique_ptr<PasswordStrengthAnalyzer> passwordStrengthAnalyzer;
	std::unique_ptr<PasswordGenerator> passwordGenerator;
	std::unique_ptr<SecureNotes> secureNotes;
};