#include "bits/stdc++.h"
#define pb push_back
using namespace std;
#define int long long
int sour[11], bitter[11], ans = 1e18, n;
signed main(){
    sour[0] = 1;
    cin >> n;
    for(int i = 1;i <=n; i ++)
        cin >> sour[i] >> bitter[i];
    for(int i = 1; i < (1 << n); i++){
        int tempSour = 1, tempBitter = 0;
        for(int j = 0; j < n; j++){
            if(i >> j & 1){
                tempSour *= sour[j+1];
                tempBitter += bitter[j+1];
            }
        }
        ans = min(ans, abs(tempSour - tempBitter));
    }
    cout << ans << endl;
}