 #include <bits/stdc++.h>
 //#include "calculate.cpp"
 #include <vector>
using namespace std;

struct User{
    string username;
    string password;
    int points;
};

void login(vector<User> &,int ,string ,User &);
void signup(vector<User> &,int ,string ,User &);
void forgot(vector<User> &,int ,string ,User &);
void exit(vector<User> &);
void displaymem(vector<User>& U,int ,string ,User &);




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


void login(vector<User> &U, int point,string path, User &temp){
    
    system("cls");
    string userID, password;
    
    cout << "--------- LOGIN ---------\n" << endl;
    cout << "USERNAME: ";
    cin >> userID;
    cout << "PASSWORD: ";
    cin >> password;

    // Load users from file into vector before searching
    loadUsersFromFile(path,U);

    for (auto& user : U) {
        if (user.username == userID && user.password == password ) {
            cout << "\nLogin successful! Welcome, " << user.username << "!\n";
            user.points += point;
            cout << "Your current points: " << user.points << " points.\n\n";
            saveUsersToFile(path,U);
            temp.username = user.username;
            temp.password = user.password;
            temp.points = user.points;
            system("pause");
            exit(U); // Exit the function once a match is found
            
            return; // Return to avoid continuing to the "Login failed" message
        }
    }
        system("cls");
        cout << "Login failed. Incorrect username or password.\n";
        system("pause");
        displaymem(U,point,path,temp);
        

}

    

void signup(vector<User> &U,int point,string path,User &temp){
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
            signup(U,point,path,temp);
        }
    
        // Load users from file into vector before searching
        loadUsersFromFile(path,U);
        addUser(U,ruserID,rpassword,point);
        saveUsersToFile(path,U);

            cout << "Your signup is COMPLETED! Welcome, " << ruserID << "\n";
            cout << "Please login again. ";
            system("pause");
            login(U, point, path, temp);
        
            
    }else{
        cout << "!! Usernames can only contain letters !!\n" << endl;
        system("pause");
        signup(U,point,path,temp);
            
    }
}


void forgot(vector<User> &U,int point,string path,User &temp){
    string suserID,spass;
    system("cls");
    cout << "-- Trouble logging in? --" <<endl;
    cout << "Please Enter your username \n" <<endl;
    cout << "Username : ";
    cin >> suserID;

    loadUsersFromFile(path,U);

    for(const auto& user : U){
        if(user.username == suserID){
            cout << "Your account is found!" << endl;
            cout << "Your password is : " << user.password << endl << endl;
            system("pause");
            displaymem(U,point,path,temp);
        }
    }
        cout << "Sorry! Your account is not found.\n" << endl;
        system("pause");
        forgot(U,point,path,temp);
        
}



void displaymem(vector<User> &U,int point,string path,User &temp){
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
        login(U,point,path,temp);
    }
    if(ch == '2'){ // sign up
        signup(U,point,path,temp);   
    }
    if(ch == '3'){ // forgot pass
        forgot(U,point,path,temp);   
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
            login(U,point,path,temp);
            break;
        }
        if(ch == '2'){ // sign up
            signup(U,point,path,temp);
            break;
        }
        if(ch == '3'){ // forgot pass
            forgot(U,point,path,temp);
            break;
        }
        if(ch == '4'){ // exit
            system("cls");
            cout << "Thank You for using our service.\n";
            break;
        }
    }
   
}

// int main(){
//     vector<User> U;
//     int point = 20;
//     displaymem(U,point);
// }