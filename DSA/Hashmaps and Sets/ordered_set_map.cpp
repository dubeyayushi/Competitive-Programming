#include<iostream>
#include<set>
#include<map>

using namespace std;
 
int main(){
    set<int>s;
    s.insert(5);
    s.insert(3);
    s.insert(7);
    s.insert(2);
    //elements sort hoke print honge
    for (int ele : s){
        cout << ele << " ";
    }
    cout << endl;

    map<int, int>m;
    m[2] = 30;
    m[3] = 10;
    m[1] = 20;
    //key ke hisaab se sorting hogi
    for (auto x : m){
        cout << x.first << " ";
    }
    cout << endl;
    for (auto x : m){
        cout << x.second << " ";
    }
    cout << endl;

    map<string, int>m2;
    m2["Manasvi"] = 11;
    m2["Monya"] = 3;
    m2["Advika"] = 42;
    m2["Ayushi"] = 49;
    for (auto x : m2){
        cout << x.first << " ";
    }
    cout << endl;
    for (auto x : m2){
        cout << x.second << " ";
    }
    cout << endl;
}