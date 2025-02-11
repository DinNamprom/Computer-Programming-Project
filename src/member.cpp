#include <bits/stdc++.h>
using namespace std;

struct member{
        int tel;
        string name;
        int point; 
};


void login(vector<member> x){

}

// void sign_in(int tel, string name){
//     cout << "Enter your phone number : " << endl;
//     cin >> tel;
//     cout << "Emter your name : " << endl;
//     cin >> name;
// }

void signin(vector<member> x){
    member d;
    cout << "Enter your phone number : " << endl;
    cin >> d.tel;
    cout << "Emter your name : " << endl;
    cin >> d.name;

    x.push_back(d);
}



int main(){
    string ans;
    member y;
    vector<member> x;

        cout << "Do you have membership ?" << endl;
        cin >> ans;

    if(ans != "Yes" && ans != "No" && ans != "yes" && ans != "no"){
        cout << "Wrong , Please try again" << endl;
        cin >> ans;
    }

    if(ans == "Yes" || ans == "yes"){
        cout << "Enter your phone number : " << endl;
        cin >> y.tel;
        cout << "Enter your name : " << endl;
        cin >> y.name;
        //----------- แสดงแต้มหลังจากบรรทัดนี้ ------------




        
    }if(ans == "No" || ans == "no"){
        cout << "Would you like to apply for membership ?" << endl;
        cin >> ans;
        if(ans == "Yes" || ans == "yes"){
            cout << "Please sign in " << endl; // ระบบ signin
            signin(x);
        }if(ans == "No" || ans == "no"){
            cout << "OK"; // cancelled
        }
    
    }
}