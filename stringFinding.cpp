#include "bits/stdc++.h"
#define first f
#define second s
#define fastio cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
using namespace std;


string str, sub;
const ll MM = 1e6 + 5, mod = 1e9 + 7;
ll hsh1 = 0, hsh[MM], base = 131, pwr = 1;
int main(){
    fastio;
    cin >> str >> sub;
    hsh[0] = 0;
    for(int i = 0; i < sub.size(); i ++){
        hsh1 = (((hsh1*base + sub[i])%mod) + mod) % mod;
        pwr = ((pwr*base %mod) + mod) % mod;
    }
    for(int i = 1; i <= str.size(); i ++)
        hsh[i] = (((hsh[i-1]*base + str[i-1])%mod) + mod) % mod;
    
    for(int i = sub.size(); i <= str.size(); i ++){
        ll x = (((hsh[i] - pwr*hsh[i-sub.size()])%mod) + mod) % mod;
        if(x == hsh1){
            cout << i-sub.size();
            return 0;
        }
    }
    cout << -1;
    return 0;
}