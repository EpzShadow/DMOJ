#include "bits/stdc++.h"
#define fastio cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
using namespace std;

int main(){
    fastio;
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<int>rows(n), cols(m);
    map<int, int>rowSt;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        if(x == -1)
            continue;
        else{
            rowSt[i-x]++;
        }
    }
    for(int i = 0, x; i < m; i++){
        cin >> x;
        if(x == -1)
            continue;
        else{
            if(rowSt[i-x]){
                cnt++;
                rowSt[i-x]--;
            }
        }
    }
    
    cout << cnt << endl;
}