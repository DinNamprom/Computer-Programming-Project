 #include <bits/stdc++.h>
 #include "promotions.cpp"
 #include <vector>
using namespace std;

struct User{
    string username;
    string password;
    int points;
};

vector<User> U;

void login();
void signup();
void forgot();
void exit();


bool isValidPassword(const string& password) {
    return all_of(password.begin(), password.end(), ::isdigit);
}


int main(){
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
        login();
    }
    if(ch == '2'){ // sign up
        signup();   
    }
    if(ch == '3'){ // forgot pass
        forgot();   
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
            login();
            break;
        }
        if(ch == '2'){ // sign up
            signup();
            break;
        }
        if(ch == '3'){ // forgot pass
            forgot();
            break;
        }
        if(ch == '4'){ // exit
            system("cls");
            cout << "Thank You for using our service.";
            break;
        }
    }
   
}

void loadUsersFromFile() {
    U.clear(); // Clear existing data before loading
    ifstream input("..\\data\\membersN.txt");
    string line;

    if (!input.is_open()) {
        cout << "Error: Unable to open file.\n";
        return;
    }

    while (getline(input, line)) {
        stringstream ss(line);
        string user, pass;
        int point;

        // Read username and password, which are separated by a comma
        if (getline(ss, user, ',') && getline(ss, pass, ',') && ss >> point) {
            U.push_back({user, pass, point});  // Store the username and password in the vector
        } else {
            cout << "Error: Invalid line format: " << line << endl;
            
        }
    }

    input.close();
}

// Load new points from `getPoints.txt`
void updatePointsFromFile(string username) {
    ifstream pointsFile("getPoints.txt");
    string line;
    int code, earnedPoints;

    if (!pointsFile) {
        cout << "Error: Cannot open getPoints.txt!\n";
        return;
    }

    while (getline(pointsFile, line)) {
        stringstream ss(line);
        if (ss >> code && ss.ignore() && ss >> earnedPoints) {
            // Find user and update points
            for (auto& user : U) {
                if (user.username == username) {
                    user.points += earnedPoints;
                    cout << earnedPoints << " points added to " << user.username << endl;
                    break;
                }
            }
        }
    }
    pointsFile.close();
}

// Save updated user data back to `membersN.txt`
void saveUsersToFile() {
    ofstream output("membersN.txt");

    for (const auto& user : U) {
        output << user.username << "," << user.password << "," << user.points << endl;
    }

    output.close();
}

void login(){
    
    system("cls");
    string userID, password;
    
    cout << "--------- LOGIN ---------\n" << endl;
    cout << "USERNAME: ";
    cin >> userID;
    cout << "PASSWORD: ";
    cin >> password;

    // Load users from file into vector before searching
    loadUsersFromFile();

    for (const auto& user : U) {
        if (user.username == userID && user.password == password ) {
            cout << "\nLogin successful! Welcome, " << user.username << "!\n";

            updatePointsFromFile(user.username);
            saveUsersToFile();

            cout << "Your current points: " << user.points << " points.\n\n";
            
            system("pause");
            exit();  // Exit the function once a match is found
        }
    }
        system("cls");
        cout << "Login failed. Incorrect username or password.\n";
        system("pause");
        login();

}

    

void signup(){
    int initialPoints = 0;
    string ruserID, rpassword, rid ,rpass;
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
            signup();
        }
    
        // Load users from file into vector before searching
        loadUsersFromFile();
            
        for(const auto& user : U){
            if(user.username == ruserID){
                cout << "The username already exists" << endl ;
                system("pause");
                signup();
            
            }
        }
            U.push_back({ruserID, rpassword, initialPoints});
            saveUsersToFile();
            cout << "Your signup is COMPLETED! Welcome, " << ruserID << "\n\n";
            system("pause");
            exit();
        
            
    }else{
        cout <<  "!! Usernames can only contain letters !!\n" << endl;
        system("pause");
        signup();
            
    }
}


void forgot(){
    string suserID,spass;
    system("cls");
    cout << "-- Trouble logging in? --" <<endl;
    cout << "Please Enter your username \n" <<endl;
    cout << "Username : ";
    cin >> suserID;

    loadUsersFromFile();

    for(const auto& user : U){
        if(user.username == suserID){
            cout << "Your account is found!" << endl;
            cout << "Your password is : " << user.password << endl << endl;
            system("pause");
            main();
        }
    }
        cout << "Sorry! Your account is not found.\n" << endl;
        system("pause");
        forgot();
        
}

void exit(){
    system("cls");
    cout << "Thank You for using our service.";
}
