#pragma once
#include <iostream>
#include <string>
#include "AppState.h"

class PasswordStrengthAnalyzer {
public:
	void handlePasswordStrengthAnalyzer(AppState& state);
	int analyzePasswordStrength(std::string& password);

private:
	int getLengthLevel(std::string& password);
	int getCapLettersLevel(std::string& password);
	int getLowLettersLevel(std::string& password);
	int getDigitsLevel(std::string& password);
	int getSpecialCharsLevel(std::string& password);
};