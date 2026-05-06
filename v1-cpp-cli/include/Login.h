#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "AppState.h"

struct Account {
	std::string username;
	std::string password;
	int key;
};

class Login {
public:
	void handleLogin(AppState& state, int& key);
	void login(AppState& state, int& key);
	void createAccount();

private:
	std::vector<Account> accounts;
	std::string xorEncryptDecrypt(std::string& input, int key);
};