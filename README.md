# Social Networking

Social Networking is a smart social networking system that aims to compete with Facebook. It allows users to create profiles, add friends, search for other users, and get recommendations for new friends.

## Features

- User manager: This program keeps track of all user information (profile, friends, etc.) and allows quick access to any user through search. It uses a linked list to store all users and a balanced binary search tree (Treap) to store each user's friends list. The user manager can perform the following operations:
  - Add a new user: This operation creates a new user object with a unique username, name, and email, and adds it to the linked list of all users.
  - Delete a user: This operation removes a user object from the linked list of all users and deletes all its references from other users' friends lists.
  - Update a user: This operation modifies the name or email of an existing user object in the linked list of all users.
  - Find a user: This operation searches for a user object by its username in the linked list of all users and returns it if found, or null otherwise.
- Friend list: This program allows users to add or remove friends from their friend list. It also provides suggestions for people they may know based on their existing friends. The friend list uses a Treap data structure to store each user's friends in alphabetical order by username. The friend list can perform the following operations:
  - Add a friend: This operation inserts a new friend object with a username and a pointer to the user object in the Treap of the current user and the Treap of the friend user.
  - Remove a friend: This operation deletes a friend object by its username from the Treap of the current user and the Treap of the friend user.
  - Find a friend: This operation searches for a friend object by its username in the Treap of the current user and returns it if found, or null otherwise.
  - List all friends: This operation traverses the Treap of the current user and prints all the friend objects' usernames and names in alphabetical order.
  - People you may know: This operation generates five suggestions for new friends based on the current user's existing friends. It selects five random users that are not in the current user's friend list but are friends with some of their friends. It prints their usernames and names in alphabetical order.
- Login/logout: This program allows users to log in or log out of the system using their username. The login/logout feature can perform the following operations:
  - Login: This operation prompts the user to enter their username and checks if it exists in the linked list of all users. If yes, it sets the current user to that user object and displays a welcome message and a menu of options. If no, it displays an error message and asks the user to try again or exit.
  - Logout: This operation resets the current user to null and displays a goodbye message and a prompt to enter another username or exit.

## Installation

To install this project, you need to have a C++ compiler and a text editor. You can download the source code from this GitHub repository and compile it using the following command:

`g++ projectDS.cpp -o social`

## Usage

To run this project, you need to have two input files: `all-users.in` and `all-users-relations.in`. These files contain the information of all users and their relations in the system. You can use the sample files provided in this repository or create your own files following the format specified in the problem statement.

To start the program, run the following command:

`./social`

You will see a welcome message and a prompt to enter your username. You can type any username that exists in the `all-users.in` file to log in. If you type an invalid username, you will see an error message and be asked to try again.

Once you are logged in, you will see a menu with the following options:

- List all friends: This option will display all your friends’ usernames and names in alphabetical order.
- Search by username: This option will allow you to search for any user by their username. If the user is your friend, you will see their name and email. If the user is not your friend or does not exist, you will see a not found message.
- Add friend: This option will allow you to add a new friend by their username. If the user exists and is not already your friend, you will see a confirmation message. If the user does not exist or is already your friend, you will see an error message.
- Remove friend: This option will allow you to remove a friend by their username. If the user is your friend, you will see a confirmation message. If the user is not your friend or does not exist, you will see an error message.
- People you may know: This option will display five users that are not in your friend list but are friends with some of your friends. You will see their usernames and names in alphabetical order.
- Logout: This option will log you out of the system and return you to the login prompt.

You can type `exit` at any time to quit the program.

## License

This project is licensed under [MIT License].
