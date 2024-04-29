#include<iostream>
#include<vector>
using namespace std;

bool isIsomorphic(string s, string t) {
        if (s.length()!=t.length()){
            return false;
        }
        vector<int>v(150, 1000);

        for (int i =0; i<s.length(); i++){
            int idx = (int)s[i];
            if (v[idx] == 1000){
                v[idx] = (int)(s[i] - t[i]);
            }
            else{
                if (v[idx] == (int)(s[i] - t[i])){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        //resetting the vector
        for (int i = 0; i<150; i++){
            v[i] = 1000;
        }
        for (int i =0; i<s.length(); i++){
            int idx = (int)t[i];
            if (v[idx] == 1000){
                v[idx] = (int)(t[i] - s[i]);
            }
            else{
                if (v[idx] == (int)(t[i] - s[i])){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }

int main(){
    string s = "badc";
    string t = "baba";

    cout << isIsomorphic(s, t) << endl;
}