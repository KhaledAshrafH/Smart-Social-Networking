#include "userLL.h"

ofstream ofile;
ifstream infile;

//to check user exist or not
bool userLL::checkUserNameUniqe(string username)
{
    User *newUser= new User;
    newUser = head;
    while (newUser!=NULL)
    {
        if(newUser->UserName == username)
        {
            cout<<"this userName already taken\n";
            return false;
        }
        newUser = newUser->next;
    }
    return true;
}

//to add user in linked list
void userLL::AddUser(string UserName,string Name,string Email)
{
    if(checkUserNameUniqe(UserName))
    {
        User* NewUser = new User;
        NewUser->UserName =UserName;
        NewUser->Name =Name;
        NewUser->Email =Email;
        if(NewUser->friends.root) NewUser->friends.root->data = UserName;


        ofile.open("all-users.in",ios::app);
        ofile<< UserName<<", "<<Name<<", "<<Email<<"\n";
        ofile.close();

        if(head==NULL)
        {
            head = tail = NewUser;
            NewUser-> next = NULL;
        }
        else
        {
            tail->next = NewUser;
            tail = NewUser;
            tail->next = NULL;
        }
    }
}

//to search user in linked list
User* userLL::searchByUsername(string username)
{
    User* Current;

    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        Current = head;

        while(Current!=NULL)
        {

            if(Current->UserName == username)
            {
                return Current;
            }
            else
            {
                Current = Current->next;
            }
        }
        return NULL;
    }
}

//to display all users in linked list
void userLL::display()
{
    if (head == NULL)
    {
        cout << "linked list is empty\n";
    }
    else
    {
        User* newUser = new User;
        newUser = head;
        while (newUser != NULL)
        {
            cout << newUser->UserName << " ";
            cout << newUser->Name << " ";
            cout << newUser->Email << " ";
            cout << "\n";
            newUser = newUser->next;
        }
    }
}


