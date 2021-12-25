#pragma once
#include "friendsBST.h"
#include <string>
class User
{
public:
	string UserName, Name, Email;
	friendsBST<string> friends;
	User* next;
	User() {
		UserName = Name = Email = "";
		next = NULL;
	}

	void displayUser() {
		cout << this->UserName << ", " << this->Name << endl;
	}
	string userReturn() {
		return this->UserName + ", " + this->Name + ", " + this->Email;
	}

	~User() {
		delete next;
	}
};