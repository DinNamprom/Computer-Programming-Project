#include <bits/stdc++.h>
using namespace std;

void login();
void signup();
void forgot();


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

void login(){
    int count,op;
    string userID, password, id ,pass;
    system("cls");
    cout << "--------- LOGIN ---------" << endl;
    cout << "USERNAME : ";
    cin >> userID;
    cout << "PASSWORD : ";
    cin >> password;

    ifstream input("..\\data\\membersN.txt");

    while(input>>id>>pass){
        if(id == userID && pass == password){
            count = 1;
            system("cls");
        }
    }
    input.close();

    if(count == 1){
        cout << userID << "\nYour LOGIN is successful\n";
        
    }else{
        cout << "LOGIN failed."<< endl << "Please try again." <<endl;
        cout << "[1] Try again" << endl << "[2] Back to menu" <<endl;
        cin >> op;
        if(op == 1) login();
        if(op == 2) main();
    }
}

void signup(){
    int count;
    int c,op;
    string ruserID, rpassword, rid ,rpass;
    system("cls");
    cout << "--------- SIGN UP ---------" << endl;
    cout << "USERNAME : ";
    cin >> ruserID;
    cout << "PASSWORD : ";
    cin >> rpassword;

    ifstream input("..\\data\\membersN.txt");
    while(input>>rid){
        if(rid == ruserID){
            count = 1;
            system("cls");
        }
    }
    if(count == 1){
        cout << "The username already exists" << endl << "[1] Try again" << endl << "[2] Back to menu" <<endl;
        cin >> c;
        if(c == 1) signup();
        if(c == 2) main();
    }else{
        ofstream f1("..\\data\\membersN.txt", ios::app);
        f1 << ruserID <<' '<< rpassword << endl;
        cout << "Your SIGN UP is completed!" << endl;
        cout << "[1] Back to menu" << endl;
        cin >> op;
        if(op == 1) main();
    }
}

void forgot(){
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
            if(op == 1) main();
        }else {
            cout << "Sorry! Your account is not found" << endl;
            cout << "[1] Back to menu" << endl;
            cin >> op;
            if(op == 1) main();
        }if(option == 2) main();
        
    }if(option == 2) main();
}
