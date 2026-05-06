#include "SecureNotes.h"

void SecureNotes::handleSecureNotes(AppState& state, int& key) {
	int input;
	std::string title;
	std::cout << "\n Secure Notes" << std::endl;
	std::cout << "===Secure-Vault===" << std::endl;
	std::cout << "[1] Add Note" << std::endl;
	std::cout << "[2] Get Note" << std::endl;
	std::cout << "[3] Delete Note" << std::endl;
	std::cout << "[4] List Notes" << std::endl;
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
		addNote(key);
		return;
	case 2:
		std::cin.ignore(10000, '\n');
		std::cout << "Enter note title to retrieve: ";
		std::getline(std::cin, title);
		getNote(title, key);
		return;
	case 3:
		std::cin.ignore(10000, '\n');
		std::cout << "Enter note title to delete: ";
		std::getline(std::cin, title);
		deleteNote(title, key);
		return;
	case 4:
		listNotes(key);
		return;
	}
}

std::string SecureNotes::xorEncryptDecrypt(std::string& input, int key) {
	std::string output = input;
	for (int i = 0; i < input.size(); ++i) {
		output[i] = input[i] ^ key;
	}
	return output;
}

void SecureNotes::addNote(int& key) {
	std::string title, content;

	std::cin.ignore(10000, '\n');
	std::cout << "===Add Note===\n" << std::endl;
	std::cout << "Enter note title: ";
	std::getline(std::cin, title);
	std::cout << "Enter note content: ";
	std::getline(std::cin, content);

	NoteEntry newEntry = { title, content };
	notes.push_back(newEntry);

	std::ofstream outFile("notes.dat", std::ios::app);
	if (!outFile) {
		std::cout << "Error opening file.\n" << std::endl;
		return;
	}

	outFile << title << "|" << xorEncryptDecrypt(content, key) << "\n";
	outFile.close();
}

void SecureNotes::getNote(std::string& title, int& key) {
	std::string checkTitle, checkContent;
	std::ifstream inFile("notes.dat");

	if (!inFile) {
		std::cout << "Error opening file.\n" << std::endl;
		return;
	}

	while (inFile) {
		std::getline(inFile, checkTitle, '|');
		std::getline(inFile, checkContent);
		if (checkTitle == title) {
			std::string decryptedContent = xorEncryptDecrypt(checkContent, key);
			std::cout << "\nTitle: " << checkTitle << "\nContent: " << decryptedContent << "\n" << std::endl;
			return;
		}
	}

	std::cout << "\nNo entry found for that title.\n" << std::endl;
}

void SecureNotes::deleteNote(std::string& title, int& key) {
	std::string checkTitle, checkContent;
	std::vector<NoteEntry> tempNotes;
	bool found = false;

	std::ifstream inFile("notes.dat");
	if (!inFile) {
		std::cout << "Error opening file.\n" << std::endl;
		return;
	}

	while (inFile) {
		std::getline(inFile, checkTitle, '|');
		std::getline(inFile, checkContent);

		if (checkTitle != title) {
			std::string decrypted = xorEncryptDecrypt(checkContent, key);
			tempNotes.push_back({ checkTitle, decrypted });
		}
		else found = true;
	}
	inFile.close();
	
	std::ofstream outFile("notes.dat");
	if (!outFile) {
		std::cout << "Error opening file.\n" << std::endl;
		return;
	}

	for (const auto& note : tempNotes) {
		std::string content = note.content;
		outFile << note.title << "|" << xorEncryptDecrypt(content, key) << "\n";
	}

	if (found) std::cout << "\nNote deleted successfully.\n" << std::endl;
	else std::cout << "\nNo entry found for that title.\n" << std::endl;
}

void SecureNotes::listNotes(int& key) {
	std::string title, content;
	std::ifstream inFile("notes.dat");
	int counter = 0;

	if (!inFile) {
		std::cout << "Error opening file.\n" << std::endl;
		return;
	}
	std::cout << "\nYour Notes:\n" << std::endl;

	while (inFile) {
		std::getline(inFile, title, '|');
		std::getline(inFile, content);

		if (!title.empty()) {
			counter++;
			std::cout << "Title " << "[" << counter << "]: " << title << std::endl;
		}
	}
}