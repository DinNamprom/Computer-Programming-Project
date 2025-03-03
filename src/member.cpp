 #include <bits/stdc++.h>
 #include "calculate.cpp"
 #include <vector>
using namespace std;

struct User{
    string username;
    string password;
    int points;
};

void login(vector<User> &,int );
void signup(vector<User> &,int );
void forgot(vector<User> &,int );
void exit(vector<User> &,int );
void displaymem(vector<User>& U,int );




void exit(vector<User> &U){
    system("cls");
    cout << "Thank You for using our service.";
}

bool isValidPassword(const string& password) {
    return all_of(password.begin(), password.end(), ::isdigit);
}



void loadUsersFromFile(string path,vector<User> &U) {
    U.clear(); // Clear existing data before loading
    ifstream input(path);
    string line;

    if (!input.is_open()) {
        cout << "Error: Unable to open file.\n";
        return;
    }

    while (getline(input, line)) {
        stringstream ss(line);
        string user, pass, po;

        // Read username and password, which are separated by a comma
        if (getline(ss, user, ',') && getline(ss, pass, ',') && getline(ss,po,',')) {
            int point = stoi(po);  // Convert pointStr to an integer
            U.push_back({user, pass, point});  // Store the username and password in the vector
        } else {
            cout << "Error: Invalid line format: " << line << endl;
            system("cls");
        }
    }

    input.close();
}

// Save updated user data back to `membersN.txt`
void saveUsersToFile(string path,vector<User> &u) {
    ofstream output(path);

    for(auto& user : u) {
        output << user.username << "," << user.password << "," << user.points << endl;
    }

    output.close();
}

// Function to add a new user
void addUser(vector<User>& U, const string& username, const string& password, int points) {
    // Check if user already exists
    for (const auto &user : U) {
        if (user.username == username) {
            cout << "User already exists!" << endl;
            return;
        }
    }

    U.push_back({username,password,points});

}


void login(vector<User> &U, int point){
    
    system("cls");
    string userID, password;
    
    cout << "--------- LOGIN ---------\n" << endl;
    cout << "USERNAME: ";
    cin >> userID;
    cout << "PASSWORD: ";
    cin >> password;

    // Load users from file into vector before searching
    loadUsersFromFile("..\\data\\membersN.txt",U);

    for (auto& user : U) {
        if (user.username == userID && user.password == password ) {
            cout << "\nLogin successful! Welcome, " << user.username << "!\n";
            user.points += point;
            cout << "Your current points: " << user.points << " points.\n\n";
            saveUsersToFile("..\\data\\membersN.txt",U);
            system("pause");
            exit(U); // Exit the function once a match is found
            
            return; // Return to avoid continuing to the "Login failed" message
        }
    }
        system("cls");
        cout << "Login failed. Incorrect username or password.\n";
        system("pause");
        displaymem(U,point);
        

}

    

void signup(vector<User> &U,int point){
    string ruserID, rpassword;
    string l = "01234567890";
   
    system("cls");

    cout << "------------- SIGN UP --------------" << endl;
    cout << "!! Usernames can only use letters !!" << endl 
         << "!! Passwords can only use numbers !!" << endl;
    cout << "------------------------------------" << endl << endl;
    cout << "USERNAME : ";
    cin >> ruserID;
    cout << "PASSWORD : ";
    cin >> rpassword;
    int z = ruserID.find_first_of(l);

    if (z == string::npos){  // Username is valid if no digits are found


        // Validate password (only digits allowed)
        if (!isValidPassword(rpassword)) {
            system("cls");
            cout << "!! Password can only contain numbers !!" << endl;
            system("pause");
            signup(U,point);
        }
    
        // Load users from file into vector before searching
        loadUsersFromFile("..\\data\\membersN.txt",U);
        addUser(U,ruserID,rpassword,point);
        saveUsersToFile("..\\data\\membersN.txt",U);

            cout << "Your signup is COMPLETED! Welcome, " << ruserID << "\n\n";
            system("pause");
            exit(U);
        
            
    }else{
        cout << "!! Usernames can only contain letters !!\n" << endl;
        system("pause");
        signup(U,point);
            
    }
}


void forgot(vector<User> &U,int point){
    string suserID,spass;
    system("cls");
    cout << "-- Trouble logging in? --" <<endl;
    cout << "Please Enter your username \n" <<endl;
    cout << "Username : ";
    cin >> suserID;

    loadUsersFromFile("..\\data\\membersN.txt",U);

    for(const auto& user : U){
        if(user.username == suserID){
            cout << "Your account is found!" << endl;
            cout << "Your password is : " << user.password << endl << endl;
            system("pause");
            displaymem(U,point);
        }
    }
        cout << "Sorry! Your account is not found.\n" << endl;
        system("pause");
        forgot(U,point);
        
}



void displaymem(vector<User> &U,int point){
    system("cls");
    char ch;
    cout << "-------------------------" <<endl;
    cout << "        MEMBERSHIP       " << endl;
    cout << "-------------------------" <<endl;
    cout << " [1] LOGIN " << endl;
    cout << " [2] SIGN UP" << endl;
    cout << " [3] Forgot password? " << endl;
    cout << " [4] EXIT " << endl;
    cout << "Please enter your choice : ";
    cin >> ch;
    cout << "\n";

    if(ch == '1'){ // login
        login(U,point);
    }
    if(ch == '2'){ // sign up
        signup(U,point);   
    }
    if(ch == '3'){ // forgot pass
        forgot(U,point);   
    }
    if(ch == '4'){ // exit
        system("cls");
        cout << "Thank You for using our service.";   
    }



    while(ch != '1' && ch != '2' && ch != '3' && ch != '4'){
        system("cls");
        cout << "---Plese select from the options ---" << endl;
        cout << " [1] LOGIN " << endl;
        cout << " [1] SIGN UP" << endl;
        cout << " [3] Forgot password?" << endl;
        cout << " [4] EXIT " << endl;
        cout << "Please enter your choice : ";
        cin >> ch;
        if(ch == '1'){ // login
            login(U,point);
            break;
        }
        if(ch == '2'){ // sign up
            signup(U,point);
            break;
        }
        if(ch == '3'){ // forgot pass
            forgot(U,point);
            break;
        }
        if(ch == '4'){ // exit
            system("cls");
            cout << "Thank You for using our service.";
            break;
        }
    }
   
}

int main(){
    vector<User> U;
    int point = 20;
    displaymem(U,point);
}