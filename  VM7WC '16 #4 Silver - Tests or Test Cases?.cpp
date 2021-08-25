#include "bits/stdc++.h"
#define pb push_back
using namespace std;
#define int long long
vector<string>ans;
int arr[26];
int n, l;
vector<string> start;
char c;
void solve(string s, int order){
    if(s.size() >= l)return;
    for(int i = 0; i < 26; i++){
        if(arr[i] > order){
            ans.pb(s + char(i + 'a'));
            solve(s + char(i+'a'), arr[i]);
        }
    }
}
signed main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> l;
    for(int i = 1, t;i <= n; i ++){
        cin >> t;
        while(t--){
            cin >> c;
            arr[c-'a'] = i;
            if(i == 1)start.pb(string(1, c));
        }
    }
    for(string x : start){
        // cout << x;
        ans.pb(x);
        solve(x, 1);
    }
    sort(ans.begin(), ans.end());
    for(string x : ans)cout << x << endl;
}