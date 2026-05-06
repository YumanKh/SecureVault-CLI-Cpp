#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "AppState.h"

struct NoteEntry {
	std::string title;
	std::string content;
};

class SecureNotes {
public:
	void handleSecureNotes(AppState& state, int& key);
	void addNote(int& key);
	void getNote(std::string& title, int& key);
	void deleteNote(std::string& title, int& key);

private:
	std::vector<NoteEntry> notes;
	void listNotes(int& key);
	std::string xorEncryptDecrypt(std::string& input, int key);
};