#include "bits/stdc++.h"
#include <cstring>
// #define int long long
#define fastio cin.sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int MM = 5e5+5;
int n,q, psa[11][MM]; //the number, idx
void solve(){
    int a, b;
    cin >> a >> b;
    //exclude a to b inclusive
    for(int i = 10; i >=1; i --){
        if(psa[i][n] - psa[i][b] + psa[i][a-1] >= 1){
            cout << i << ' ' << psa [i][n] - psa[i][b] + psa[i][a-1] << endl;
            return;
        }
    }
}
signed main(){
    fastio;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        psa[x][i]++;
    }
    for(int i = 1; i <= 10; i ++)
        for(int j = 1; j <=n; j++)
            psa[i][j] = psa[i][j] + psa[i][j-1];
    while(q--)solve();
   
}