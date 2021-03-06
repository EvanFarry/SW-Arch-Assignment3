#include <string.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#include "Functions.h"
#include "Items.h"
#include "Cart.h"
#include "DatabaseManager.h"
#include "User.h"

int main() {
	// Generate the database from the text file.
	Database db("Files");

	char input[100];

	cout << "Hello, welcome to the Online Shopping Center!" << endl;
	cout << "Enter (exit) if you would like to quit the program." << endl;

	while (strcmp(input, "exit") != 0) {
		cout << "Please enter your pre-registered username: ";
		cin.getline(input, sizeof(input));
		cout << endl;

		if (db.search_user(input)) {
			User user(input);
			user.Login(db);
		}
		else {
			cout << "Invalid Account" << endl;
		}
	}

	return 0;
}

