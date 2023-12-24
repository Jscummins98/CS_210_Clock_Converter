#include <iostream>
#include <string>
using namespace std;

// Function to convert any number 0 - 59 into two digit format
string twoDigitString(unsigned int n) {
	string twoDigitStr = to_string(n);
	if (n <= 9) {
		twoDigitStr = "0" + twoDigitStr;
	}
	return twoDigitStr;
}

// Function to create a string of all one character
string nCharString(int n, char c) {
	string str;
	for (int i = 0; i < n; ++i) {
		str.push_back(c);
	}
	return str;
}

// Function to convert user input into 24 hour clock string
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
	string clock24 = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
	return clock24;
}

// Function to convert user input into 12 hour clock string
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
	string meridiem = " A M";
	string clock12;

	if (h >= 12) {
		meridiem = " P M";
		if (h > 12) {
			h -= 12;
		}
	}

	if (h == 0) {
		h = 12;
	}

	clock12 = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);

	return clock12 + meridiem;
}

// Function to print the menu. Call after every clock modification
void printMenu() {
	cout << nCharString(26, '*') << endl;
	cout << "* 1- Add One Hour" << nCharString(8, ' ') << "*" << endl << endl;
	cout << "* 2- Add One Minute" << nCharString(6, ' ') << "*" << endl << endl;
	cout << "* 3- Add One Second" << nCharString(6, ' ') << "*" << endl << endl;
	cout << "* 4- Exit Program" << nCharString(8, ' ') << "*" << endl;
	cout << nCharString(26, '*') << endl;
}

// Function to get the user's menu selection
unsigned int getMenuChoice(unsigned int maxChoice) {
	int userChoice;
	cin >> userChoice;

	while (userChoice > maxChoice || userChoice < 1) {
		cin >> userChoice;
	}

	return userChoice;
}

// Function to display both clocks
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
	cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << nCharString(3, ' ');
	cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;
	cout << endl;
	cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*" << nCharString(3, ' ');
	cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;
	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}

// Function to add 1 hour
void addHour(int& hour) {
	if (hour == 23) {
		hour = 0;
	}
	else {
		hour += 1;
	}
}

// Function to add 1 minute
void addMinute(int& minute, int& hour) {
	if (minute == 59) {
		minute = 0;
		addHour(hour);
	}
	else {
		minute += 1;
	}
}

// Function to add 1 second
void addSecond(int& second, int& minute, int& hour) {
	if (second == 59) {
		second = 0;
		addMinute(minute, hour);
	}
	else {
		second += 1;
	}
}

int main() {
	int hours;
	int minutes;
	int seconds;
	int userMenuChoice;

	// Get the initial time from the user
	cout << "Enter initial hours: (0 - 23)" << endl;
	cin >> hours;
	while (hours > 23 || hours < 0) {
		cout << "Invalid entry. Enter initial hours: (0 - 23)" << endl;
		cin >> hours;
	}
	cout << "Enter initial minutes: (0 - 59)" << endl;
	cin >> minutes;
	while (minutes > 59 || minutes < 0) {
		cout << "Invalid entry. Enter initial minutes: (0 - 59)" << endl;
		cin >> minutes;
	}
	cout << "Enter initial seconds: (0 - 59)" << endl;
	cin >> seconds;
	while (seconds > 59 || seconds < 0) {
		cout << "Invalid entry. Enter initial seconds: (0 - 59)" << endl;
		cin >> seconds;
	}

	// Display the clocks and menu and allow the user to interact with the menu
	displayClocks(hours, minutes, seconds);
	printMenu();
	userMenuChoice = getMenuChoice(4);
	while (userMenuChoice != 4) {
		if (userMenuChoice == 1) {
			addHour(hours);
		}
		else if (userMenuChoice == 2) {
			addMinute(minutes, hours);
		}
		else {
			addSecond(seconds, minutes, hours);
		}
		displayClocks(hours, minutes, seconds);
		printMenu();
		cin >> userMenuChoice;
	}

	return 0;
}