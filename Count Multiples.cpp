#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define int long long
using namespace std; 
int x, y, a, b;
signed main(){
    cin >> x >> y >> a >> b;
    int q,w,e,r,t,u, lcm;
    lcm = (a*b)/gcd(a,b);
    q = y/b;
    w = y/a;
    e = y/lcm;
    r = (x-1)/b;
    t = (x-1)/a;
    u = (x-1)/lcm;
    int ans = q + w - e - (r + t - u);
    cout << ans;
}
