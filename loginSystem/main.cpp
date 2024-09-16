
#include <iostream>
#include <cctype>
#include <fstream>

using namespace std;

void registerUser(string username, string password){
    //attempt to find file.
    string userDetails;
    ifstream userFile("DB/"+username+".txt");

    //check if user file already exists
    if (getline (userFile, userDetails))
    {
        //if it does then cancel login process
        cout << "This user is already registered";
        userFile.close();
        return;
    }

    //if it doesn't then create a file, with the username as the name of the file, and store the password
    ofstream MyFile("DB/"+username+".txt");

    MyFile << password;
    
    MyFile.close();
    cout << "Successfully registered user";
    return;
}

void loginUser(string username, string password) {
    //atempt to find file
    string userDetails;
    ifstream userFile("DB/"+username+".txt");

    //check if user file exists
    getline (userFile, userDetails);
    if (!userFile)
    {
        // if it doesn't, cancel login
        cout << "This user does not exist, please register";
        userFile.close();
        return;
    }

    //check if password is correct
    if (userDetails != password) {
        //if not, then cancel login
        cout << "Incorrect password";
        userFile.close();
        return;
    }
    
    userFile.close();
    cout << "You have successfully logged in";
    return;
}

string lowerString(string text){
    //Iterate through each char and change to lowercase
    for (int i = 0; i < text.size(); i++)
    {
        text[i] = tolower(text[i]);
    }
    return text;
}

int main(){
    //Usage type
    bool awaitingInstruction = true;
    string type;
    //Type redirection
    string lType;
    do {
        cout << "Would you like to login or register?" << endl;
        cin >> type;
        lType = lowerString(type);
        if (lType == "register" || lType == "login") {
            awaitingInstruction = false;
        }
    }
    while(awaitingInstruction);
    //Username
    string username;
    cout << "Please enter your username" << endl;
    cin >> username;
    //Password
    string password;
    cout << "Please enter your password" << endl;
    cin >> password;

    if (lType == "register")
    {
        registerUser(username, password);
    }
    else if (lType == "login")
    {
        loginUser(username, password);
    }
    return 0;
}
