#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "AppState.h"

struct PasswordEntry {
	std::string site;
	std::string username;
	std::string password;
};

class PasswordManager {
public:
	void handlePasswordManager(AppState& state, int& key);
	void addPassword(int& key);
	void getPassword(std::string username, int key);
	void deletePassword(std::string username, int key);
	

private:
	std::vector<PasswordEntry> entries;
	void listPasswords(int& key);
	std::string xorEncryptDecrypt(std::string& input, int key);
};