#pragma once
#include <iostream>
#include <random>
#include <string>
#include "AppState.h"

class PasswordGenerator {
public:
	void handlePasswordGenerator(AppState& appState);
	std::string passwordGenerator(int length);

private:
	int makeLength(int length);
};