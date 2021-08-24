#include "bits/stdc++.h"
#define pb push_back
using namespace std;
#define int long long
signed main(){
    cin.tie(0); cin.sync_with_stdio(0);
    string s, temp;
    int n; cin >> n;
    while(n--){
        string t = "";
        int ans = 1;
        cin >> s;
        for(int i = 1; i <= s.size(); i ++){
            t = "";
            if(s.size() % i != 0)continue;
            temp = s.substr(0, i);
            while(t.size() < s.size())t+=temp;
            if(t == s){
                ans = s.size()/temp.size(); 
                break;
            }
        }
        cout << ans << endl;
    }

}