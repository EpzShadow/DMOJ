#include "bits/stdc++.h"
// #define int long long
#define fastio cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int psa[100005];
signed main(){
    fastio;
    int i,n,j,cnt = 0;
    cin >> i >> n >> j;
    for(int k = 0,a,b,c ; k < j; k++){
        cin >> a >> b >> c;
        psa[a]+= c;
        psa[b+1]-=c;
    }
    for(int k = 1; k <= i; k++){
        psa[k] += psa[k-1];
        if(psa[k] < n)cnt++;
    }
    cout << cnt;
}