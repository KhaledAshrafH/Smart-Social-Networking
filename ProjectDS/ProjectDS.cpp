#include<iostream>
#include<queue>
#include <fstream>
#include"userLL.h"
#include"friendsBST.h"
using namespace std;
//to store all users in this object pointer linked list
userLL* userll = new userLL;


void displayMenu(User* loginUser); //to display menu for user after login
void removeLine(string line); //to remove friend from file relations

int main()
{
    while (true)
    {
        cout << "1- Register\n" << "2- Login\n"<<"3- Exit\n";
        int choice;
        cin >> choice;

        //to register
        if (choice == 1) 
        {
            string username, name, email;
            cout << "Username : ";
            cin >> username;
            cout << "Name : ";
            cin.ignore(256, '\n');
            getline(cin, name);
            cout << "Email : ";
            cin >> email;
            userll->AddUser(username, name, email);
            choice = 2;
        }

        //to login
        else if (choice == 2) 
        {
            User* user;
            cout << "Please enter your user name\n";
            string username;
            cin >> username;
            if (userll->searchByUsername(username)) //user in userll
            {
                user = userll->searchByUsername(username);
                cout << "Hello " << user->Name << endl;
                displayMenu(user);
            }
            else
            {
                cout << "Please register first\n";
                continue;
            }
        }

        //to exit from program
        else if(choice==3)
        {
            exit(0);
        }

        //if entered any number not in menu
        else {
            continue;
        }
    }

    return 0;
}

void displayMenu(User* loginUser)
{
    while (true)
    {
        cout << "1- List all friends\n" << "2- Search by User name\n" << "3- Add friend\n" << "4- Remove friend\n" <<
            "5- People you may know\n" << "6- logout\n";
        int choise;
        cin >> choise;

        //to list all friends
        if (choise == 1)
        {
            cout << "Your Friends" << endl << "-------------" << endl;
            loginUser->friends.printFriends(); ///root is with us!
            cout << endl;
        }

        //to search by username
        else if (choise == 2)
        {
            cout << "Please enter the user name you are searching for\n";
            string username;
            cin >> username;
            User* foundUser;
            if (loginUser->friends.findUser(username) != NULL)
            {
                foundUser = loginUser->friends.findUser(username)->userRef;
            }

            else
            {
                foundUser = NULL;
            }

            if (foundUser != NULL)
            {
                cout << foundUser->UserName << ", " << foundUser->Name << ", " << foundUser->Email << endl;
            }
            else
            {
                cout << "NOT Found\n";
            }
        }

        //to add friend
        else if (choise == 3)
        {
            cout << "Please enter the user name of the new friend\n";
            string username;
            cin >> username;

            if (userll->searchByUsername(username) == NULL) {
                cout << "this user is not in the system\n";
                continue;
            }
            if (loginUser->friends.addFriend(username, userll->searchByUsername(username), userll) != NULL)
            {
                cout << "You are now friends!!\n";
            }
            else
            {
                cout << "You are already friends!\n";
            }

        }

        //to delete friend
        else if (choise == 4)
        {

            cout << "Please enter the user What you want to delete\n";
            string username;
            cin >> username;

            if (loginUser->friends.remove(username)) {
                userll->searchByUsername(username)->friends.remove(loginUser->UserName);
                string line1 = username + ", " + loginUser->UserName;
                string line2 = loginUser->UserName + ", " + username;
                removeLine(line1);
                removeLine(line2);
                cout << "Deleted friend Successfull!" << endl;
            }
            else cout << "This friend's not in your friends." << endl;
        }

        //to display people you may know
        else if (choise == 5)
        {
            cout << "People you may know" << endl << "--------------------" << endl;
            loginUser->friends.peopleYouMayKnow(userll);
            cout << endl;
        }

        //to logout
        else if (choise == 6)
        {
            break;
        }
    }
}

void removeLine(string line)
{
    string key = line;
    ifstream read("all-users-relations.in");
    ofstream write("tmp.in");
    if (read.is_open()) {
        string line;
        while (getline(read, line)) {
            if (line.find(key) == string::npos)
                write << line << endl;
        }
    }

    read.close();
    write.close();
    remove("all-users-relations.in");
    rename("tmp.in", "all-users-relations.in");
}
