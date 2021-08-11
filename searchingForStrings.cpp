#include "bits/stdc++.h"
#define int long long
#define first f
#define second s
using namespace std;
const int MM = 2e5 + 5, mod = 1e9 + 7;
vector<int>freqN(26), freqH(26);
string needle, haystack;
int n, h, base = 131, base2 = 149, hsh[MM], hsh2[MM], pwr[MM], pwr2[MM];
unordered_set<int>st;
int getHash(int l, int r){//l is start of str, r is finish str
    if(l == 0){
        int v1 = hsh[r];
        int v2 = hsh2[r];
        v1 = ((v1%mod) + mod)%mod;
        v2 = ((v2%mod)+ mod)%mod;
        return v1 << 31 | v2;
    }
    // cout << hsh[r] << ' ' << hsh[l-1] << ' ' << pwr[r-l+1] << endl;
    int x = (((hsh[r]- hsh[l-1]*pwr[r-l+1])%mod)+mod)%mod;
    int y = (((hsh2[r] - hsh2[l-1]*pwr2[r-l+1])%mod)+mod)%mod;
    return x << 31 | y;
}
signed main(){
    cin.tie();  
    cin.sync_with_stdio();
    cin >> needle >> haystack;
    n = needle.size(), h = haystack.size();
    for(int i = 0; i < n; i ++)freqN[needle[i]-'a']++;
    hsh[0] = haystack[0], pwr[0] = 1, hsh2[0] = haystack[0], pwr2[0] = 1;
    for(int i = 1; i < h; i ++){
        pwr[i] = (pwr[i-1] * base)%mod;
        hsh[i] = (hsh[i-1] * base + haystack[i])%mod;
        pwr2[i] = (pwr2[i-1] * base2)%mod;
        hsh2[i] = (hsh2[i-1] * base2 + haystack[i])%mod;
    }
    for(int i = 0; i < h; i ++){
        freqH[haystack[i]-'a']++;
        if(i + 1 >= n){
            if(freqH == freqN){
                // cout << haystack.substr(i-n+1, n) << ' ' << getHash(i-n+1, i) << endl;
                st.insert(getHash(i - n + 1, i));
            }
            freqH[haystack[i-n+1]-'a']--;
        }
    }
    cout << st.size();
}