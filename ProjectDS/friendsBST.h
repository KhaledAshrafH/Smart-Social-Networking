#ifndef FRIENDSBST_H
#define FRIENDSBST_H
#include<queue>
#include<iostream>
#include <fstream>
using namespace std;

//forward declarations
class userLL;
class User;

template <typename T>
class friendsBST {
public:
    class nodeBST
    {
    public:
        T data; //store data in AVL
        int priority = 0; //to add priority for every node
        User* userRef; //to point to every user in tree
        nodeBST* left; //point to left nodeBST
        nodeBST* right; //point to right nodeBST
        nodeBST() {
            left = right = NULL;
            userRef = NULL;
            priority = rand() % 100;
        }
    };
public:
    nodeBST* root;//in the first time before adding in AVL Tree
    userLL* users;
    User* userr;
    //function to calculate the maximum value from specified nodeBST
    int maxUtility(nodeBST* current)
    {
        if (current->right == NULL) return current->data;
        else return maxUtility(current->right);
    }

    //constructor
    friendsBST() {
        root = new nodeBST;
    }

    //right rotation if not balanced in the left
    nodeBST* rightRotation(nodeBST* current)
    {
            nodeBST* leftNode = current->left;
            nodeBST* newNode = current->left->right;       
            leftNode->right = current;
            current->left = newNode;
            return leftNode;
    }

    //left rotation if not balanced in the right
    nodeBST* leftRotation(nodeBST* current)
    {
            nodeBST* rightNode = current->right;
            nodeBST* newNode = current->right->left;
            rightNode->left = current;
            current->right = newNode;
            return rightNode;
    }

    //if not balnce in any node
    void rebalance(nodeBST* current,T value) {
        if (value < current->data) {

            if (current->left->priority > current->priority && current->left != NULL && current->data != root->data)
                current = rightRotation(current);
        }
        else if (value > current->data) {

            if (current->right->priority > current->priority && current->right != NULL && current->data != root->data)
                current = leftRotation(current);
        }
    }

private:
    nodeBST* addFriendUtility(nodeBST* current, T value, User* user, userLL* userll)
    {
        //this declarations beacause of farward declaration
        users = new userLL; 
        users = userll;
        userr = new User;
        userr = user;
        //to check exist user in friends and linked list
        if ((this->findUser(value) != NULL && users->searchByUsername(value) == NULL) || userr == NULL)///the user not a friend of me
        {
            return NULL;
        }

        nodeBST* new_nodeBST = new nodeBST;
        //the right position achieved.
        if (current == NULL)
        {
            fstream relations;
            new_nodeBST->data = value;
            new_nodeBST->right = NULL;
            new_nodeBST->left = NULL;
            current = new_nodeBST;
            //store user in the file
            relations.open("all-users-relations.in", ios::out | ios::in | ios::app);
            if (!relations)
            {
                cout << "failure!\n";
            }
            else
            {
                if (root != NULL && userr->UserName != root->data)
                {

                    relations << root->data << ", " << value << endl;
                }
            }
            relations.close();
            //to add me in this friend's tree
            current->userRef = userr;
            if (userr->friends.findUser(this->root->data)==NULL) {
                addFriendUtility(userr->friends.root, this->root->data, users->searchByUsername(this->root->data), users);
            }
        
            return new_nodeBST;
        }
        
        if (value < current->data){ 
            current->left = addFriendUtility(current->left, value, userr, users); //go to the last left
        
        }
        else if (value > current->data){ 
            current->right = addFriendUtility(current->right, value, userr, users); //go to the last right
       
        }
        userr->friends.rebalance(userr->friends.root, this->root->data);
        return current;
        }

    //to remove nodeBST from the Tree with balanced result
    nodeBST* removeUtility(nodeBST* current, T value)
    {
        //base case
        if (current == NULL)
        {
            return NULL;
        }
        //if AVL Tree is exist
        if (value < current->data) current->left = removeUtility(current->left, value); //go to the last left
        else if (value > current->data) current->right = removeUtility(current->right, value); //go to the last right
        //After finding the value
        else
        {
            //if the is leaf
            if (current->left == NULL && current->right == NULL)
            {
                delete current;
                current = NULL;
            }
            //if the nodeBST has 2 childs
            else if (current->left != NULL && current->right != NULL)
            {
                if (current->left->priority > current->right->priority) {
                    leftRotation(current);
                    removeUtility(current->left, value);
                }
                else {
                    rightRotation(current);
                    removeUtility(current->right, value);
                }
            }
            //if the nodeBST has only child
            else
            {
                nodeBST* child = current;
                if (current->right != NULL)
                {
                    current = current->right;
                }
                else
                {
                    current = current->left;
                }
                child->left = NULL;
                child->right = NULL;
                delete child;
                child = NULL;
            }
        }
        return current;
    }

    
    //to print friends of user
    void printTreap(nodeBST* current) {
        if (current == NULL)
            return;
        printTreap(current->left);
        if (current != root) current->userRef->displayUser();
        printTreap(current->right);
    }
    //to find user in friends tree
    nodeBST* findUserUtility(nodeBST* current, T value)
    {   //not found (yet).
        if (current == NULL)
            return NULL;
        if (value < current->data)
            return findUserUtility(current->left, value);
        else if (value > current->data)
            return findUserUtility(current->right, value);
        else
            return current;
    }

public:
    //to display users not in friends
    void peopleYouMayKnow(userLL* &users) {
        this->users = new userLL;
        this->users = users;
        userr= this->users->head;
        int i = 0;
        ENDINGPOINT:
        while (userr != NULL) {
            if (findUser(userr->UserName)==NULL) {
                cout << userr->UserName << ", " << userr->Name << endl;
                userr = userr->next;
                i++;
                if (i == 5) break;
                goto ENDINGPOINT;
            }
            else { 
                userr = userr->next; 
            }
        }
    }

    nodeBST* addFriend(T value, User* user, userLL* userll)
    {
        if (addFriendUtility(root, value, user, userll) != NULL) 
        {
            root = addFriendUtility(root, value, user, userll);
            rebalance(root, value);
            return root;
        }
        return NULL;
    }

    nodeBST* findUser(T value)
    {
        return findUserUtility(root, value);
    }

    void printFriends() {
        printTreap(root);
    }

    bool remove(T value) {
        if (removeUtility(root, value)!=NULL)
        {
            root = removeUtility(root, value);
            return true;
        }
        else return false;
    }
    
};


#endif // FRIENDSBST_H
