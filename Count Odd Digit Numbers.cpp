#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define int unsigned long long
using namespace std; 
signed main(){
    int n, ans = 0;
    cin >> n;
    int start = 1, end = 9;
    while(start <=  n){
        ans += min(n, end) - start + 1;
        start = 100 * start;
        end = 100*end + 99;
    }
    cout << ans;
}
