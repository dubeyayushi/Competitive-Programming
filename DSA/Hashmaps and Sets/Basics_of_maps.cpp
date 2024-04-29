#include<iostream>
#include<unordered_map>

using namespace std;
 
int main(){
    unordered_map<string, int>m;
    pair<string, int>p1;
    p1.first = "Ayushi";
    p1.second = 16;
    m.insert(p1);
    
    m["Monya"] = 34;
    m["Advika"] = 3;
    m["Manasvi"] = 31;

    for (pair<string, int> p : m){
        cout << p.first << " " << p.second << endl;
    }
    cout << m.size() << endl;
    cout << endl;

    m.erase("Ayushi");

    for (auto p : m){
        cout << p.first << " " << p.second << endl;
    }
    cout << m.size() << endl;
    cout << endl;
}