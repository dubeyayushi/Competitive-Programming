#include<iostream>
#include<vector>
using namespace std;
#define ll long long int

vector<ll>dp;

ll f(string& str, int i){
    if (i<=0){
        return 1;
    }
    if (dp[i]!=-1){
        return dp[i];
    }
    ll ans = 0;
    if (str[i]-'0'>0){
        ans += f(str, i-1);
    }
    if (str[i-1]-'0'>0 && ((str[i-1]-'0')*10 + str[i]-'0')<=26){
        ans += f(str, i-2);
    }
    return dp[i] = ans;
}

int main(){
    string s;
    cin >> s;
    while(s[0]!='0'){
        dp.clear();
        dp.resize(5005, -1);
        cout << f(s, s.size()-1) << endl;
        cin >> s;
    }
}

// string decode(string &input){
//     string result = "";
//     if (input.size()==1){
//         result += (char)(64 + input[0] - '0');
//     }
//     else{
//         int num = (input[0] - '0')*10 + (input[1] - '0');
//         result += (char)(64+num);
//     }
//     return result;
// }