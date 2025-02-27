 #include <bits/stdc++.h>
 //#include "promotions.cpp"
 #include <vector>
using namespace std;

struct User{
    string username;
    string password;
    int point;
};

//vector<User> U;

void login(vector<User>);
void signup(vector<User>);
void forgot(vector<User>);
void rewrite(string, vector<User>);

bool isValidPassword(const string& password) {
    return all_of(password.begin(), password.end(), ::isdigit);
}


// int main(){
//     system("cls");
//     char ch;
//     cout << "-------------------------" <<endl;
//     cout << "        MEMBERSHIP       " << endl;
//     cout << "-------------------------" <<endl;
//     cout << " [1] LOGIN " << endl;
//     cout << " [2] SIGN UP" << endl;
//     cout << " [3] Forgot password? " << endl;
//     cout << " [4] EXIT " << endl;
//     cout << "Please enter your choice : ";
//     cin >> ch;
//     cout << "\n";

//     if(ch == '1'){ // login
//         login();
//     }
//     if(ch == '2'){ // sign up
//         signup();   
//     }
//     if(ch == '3'){ // forgot pass
//         forgot();   
//     }
//     if(ch == '4'){ // exit
//         system("cls");
//         cout << "Thank You for using our service.";   
//     }



//     while(ch != '1' && ch != '2' && ch != '3' && ch != '4'){
//         system("cls");
//         cout << "---Plese select from the options ---" << endl;
//         cout << " [1] LOGIN " << endl;
//         cout << " [1] SIGN UP" << endl;
//         cout << " [3] Forgot password?" << endl;
//         cout << " [4] EXIT " << endl;
//         cout << "Please enter your choice : ";
//         cin >> ch;
//         if(ch == '1'){ // login
//             login();
//             break;
//         }
//         if(ch == '2'){ // sign up
//             signup();
//             break;
//         }
//         if(ch == '3'){ // forgot pass
//             forgot();
//             break;
//         }
//         if(ch == '4'){ // exit
//             system("cls");
//             cout << "Thank You for using our service.";
//             break;
//         }
//     }
   
// }

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
        if (getline(ss, user, ',') && getline(ss, pass, ',') && getline(ss, po, ',')) {
            U.push_back({user, pass, atoi(po.c_str())});  // Store the username and password in the vector
        } else {
            cout << "Error: Invalid line format: " << line << endl;
        }
    }

    input.close();
}

void login(vector<User> U){
    
    system("cls");
    string userID, password;
    
    cout << "--------- LOGIN ---------" << endl;
    cout << "USERNAME: ";
    cin >> userID;
    cout << "PASSWORD: ";
    cin >> password;

    // Load users from file into vector before searching
    //loadUsersFromFile();

    // Find user in vector
    // auto it = find_if(U.begin(), U.end(), [&](const User& user) { 
    //     return user.username == userID && user.password == password; 
    // });

    // if (it != U.end()) {
    //     cout << "Login successful! Welcome, " << userID << "!\n";

    // } else {

    for (auto& user : U) {
        if (user.username == userID && user.password == password) {
            cout << "Login successful! Welcome, " << userID << "!\n";
            cout << "You have " << user.point << " point \n"; 
            system("pause");
            return;  // Exit the function once a match is found
        }
    }
        system("cls");
        cout << "Login failed. Incorrect username or password.\n";
        system("pause");
        //login();

}

    

void signup(vector<User> U){
    int count;
    int c,op;
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
            cout << "Press 1 to try again" << endl;
            cin >> op;
            if (op == 1); //signup();  // Restart signup if password is invalid
        }
    
    

        ifstream input("..\\data\\membersN.txt");

        while(input>>rid){
            if(rid == ruserID){
                count = 1;
                system("cls");
            }
        }
        if(count == 1){
            cout << "The username already exists" << endl << "[1] Try again" 
                 << endl << "[2] Back to menu" <<endl;
            cin >> c;
            if(c == 1); //signup();
            //if(c == 2) main();
        }else{
            U.push_back({ruserID, rpassword, 0});
            ofstream f1("..\\data\\membersN.txt", ios::app);
            f1 << ruserID <<","<< rpassword << "," << 0 << endl;
            cout << "Your SIGN UP is completed!" << endl;
            //loadUsersFromFile();
            cout << "[1] Back to menu" << endl;
            cin >> op;
            if(op == 1); //main();
        }
    }else{
        cout <<  "!! Usernames can only contain letters !!" << endl;
        cout << "Press 1 to sign in again" <<endl;
        cin >> op;
        if(op == 1); //signup();
    
    }
}

void forgot(vector<User> U){
    int option,op;
    system("cls");
    cout << "-- Trouble logging in? --" <<endl;
    cout << "[1] Enter your username " << endl;
    cout << "[2] Back to menu" <<endl;
    cout << "Please enter your choice : ";
    cin >> option;

    if(option == 1){
        int count;
        string suserID,sid,spass;
        system("cls");
        cout << "-- Enter your username --" <<endl;
        cout << "Username : ";
        cin >> suserID;

        ifstream f2("..\\data\\membersN.txt");
        while(f2 >> sid >> spass){
            if(sid == suserID){
                count = 1;
            }
        }
        f2.close();
        if(count == 1){
            cout << "Your account is found!" << endl;
            cout << "Your password is : " << spass << endl;
            cout << "[1] Back to menu" << endl;
            cin >> op;
            //if(op == 1) main();
        }else {
            cout << "Sorry! Your account is not found" << endl;
            cout << "[1] Back to menu" << endl;
            cin >> op;
            if(op == 1); //main();
        }//if(option == 2) main();
        
    }//if(option == 2) main();
}

void rewrite(string filepath, vector<User> u) {
    ofstream mem(filepath);
    if (!mem.is_open()) {
        cerr << "Failed to open the file." << endl;
    }
    for (const auto user: u) {
        mem << user.username << "," << user.password << "," << user.point << endl;
    }
}