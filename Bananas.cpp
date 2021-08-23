#include "bits/stdc++.h"
#define pb push_back
using namespace std;
#define int long long
bool isAWord(string s);
bool isMonkeyLanguageWord(string s);
bool isAWord(string s){
    if(s == "A")
        return true;
    // if(s.size() <=2)
    //     return false;
    if(s[0] == 'B' && s.back() == 'S' && isMonkeyLanguageWord(s.substr(1, max(1UL, s.size()-2))))
        return true;
    return false;
}
bool isMonkeyLanguageWord(string s){
    if(isAWord(s))
        return true;
    //deal with the other case
    for(int i = 1; i < s.size()-1; i ++){
        if(isAWord(s.substr(0,i)) && s[i] == 'N' && isMonkeyLanguageWord(s.substr(i+1,s.size())))
            return true;
    }
    return false;
}

signed main(){
    string s ="";
    cin.sync_with_stdio(0); 
    cin.tie(0);
    while (s != "X"){
        cin >> s;
        bool flg = isMonkeyLanguageWord(s);
        if(s!="X")
        flg ? cout << "YES"<< endl : cout << "NO" << endl;
    }
}