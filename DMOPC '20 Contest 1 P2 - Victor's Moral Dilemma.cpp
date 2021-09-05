#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std; 
const int MM = 1e6+5;
int arr[MM], d, n, m, start, endNode;
void solve(){
    cin >> m;
    m+= start;
    int f = arr[m] - arr[start];
    int s = arr[endNode] - arr[m];
    if(f >= s){
        start = m;
        cout << f << endl;
    }
    else{
        endNode = m;
        cout << s << endl;
    }
    // cout << start << ' ' << endNode;
}
signed main(){
    cin >> n >> d;
    start = 0;
    endNode = n;
    for(int i = 1; i <= n; i ++){
       cin >> arr[i];
       arr[i] += arr[i-1];
    }
    while(d--)solve();
}
