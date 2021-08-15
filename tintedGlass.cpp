#include "bits/stdc++.h"
#define int long long
#define fastio cin.sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int psa[1002*2][1002*2];
signed main(){
    fastio;
    int n, t, cnt = 0;
    cin >> n >> t;
    vector<vector<int>>queries(n, vector<int>(5));
    vector<int>x,y;
    map<int, int> mapx, mapy;
    for(int i = 0; i < n; i ++){
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        x.push_back(a);
        x.push_back(c);
        y.push_back(b);
        y.push_back(d);
        queries[i][0] = a;
        queries[i][1] = b;
        queries[i][2] = c;
        queries[i][3] = d;
        queries[i][4] = e;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    y.resize(unique(y.begin(), y.end()) - y.begin());   
    for(int i = 0; i < x.size(); i ++)mapx[x[i]]=i;
    for(int i = 0; i < y.size(); i++)mapy[y[i]]=i;
    for(int i = 0; i < n; i ++){
        int a = mapx[queries[i][0]]+1, b = mapy[queries[i][1]]+1, c = mapx[queries[i][2]]+1, d = mapy[queries[i][3]] + 1, e = queries[i][4];
        // printf("%d %d %d %d %d\n",a, b, c, d, e) ;
        //i have the compressed coordinates now
        psa[a][b] += e;
        psa[c][d] += e;
        psa[a][d] -=e;
        psa[c][b] -=e;
    }
    

    for(int i = 1; i < 2*n; i ++){
        for(int j = 1; j < 2*n; j ++){
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
            if(psa[i][j] >= t){
                cnt += abs(x[i] -x[i-1]) * abs(y[j] - y[j-1]);
            }
        }
    }
    cout << cnt;
    
}