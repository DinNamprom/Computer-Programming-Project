#include <bits/stdc++.h>
using namespace std;

struct member{
        int tel;
        string name;
        int point; 
};


void login(vector<member> x){
    int tel;
    int i = 0;
    cin >> tel;
    while(tel == x[i].tel){
        i++;
        if(i > x.size()){
            cout << "Not found";
            break;
        }
    }
    cout << x[i].name;
}

void input_member(string filename,vector<member> &list) {
    member d;
    ifstream source;
    string text;
    source.open(filename);
    cout << "reading file..." << endl;
    while (getline(source, text)) {
        char tempn[99];
		sscanf(text.c_str(),"%d,%99[^,],%d",&d.tel,tempn,&d.point);
        d.name = tempn;
        list.push_back(d);
    }
    cout << "reading succesfull..." << endl;
    source.close();
}


void signin(vector<member> x){
    member d;
    cout << "Enter your phone number : " << endl;
    cin >> d.tel;
    cout << "Enter your name : " << endl;
    cin >> d.name;

    x.push_back(d);
}



int main(){
    string ans;
    vector<member> x ;
    input_member("..\\data\\membersN.txt",x);

        cout << "Do you have membership ?" << endl;
        cin >> ans;

    if(ans != "Yes" && ans != "No" && ans != "yes" && ans != "no"){
        cout << "Wrong , Please try again" << endl;
        cin >> ans;
    }

    if(ans == "Yes" || ans == "yes"){

        
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

    for (unsigned int i = 0;i < x.size();i++) {
        cout << left << i+1 << setw(2) << ".";
        cout << left << setw(15) << x[i].tel;
        cout << left << setw(15) << x[i].name;
        cout << left << setw(15)  << x[i].point << endl;
    }
}
