#include "bits/stdc++.h"
using namespace std;
int main(){
    int n, m, j;
    cin >> n >> m >> j;
    vector<pair<int,int>>a;
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i = 0; i < m; i ++){
        int p, t;
        cin >> p >>t;
        a.push_back({t,p});
    }
    sort(a.begin(), a.end());

    if(j > n){
        cout << 0 << endl;
        return 0;
    }
    int currPos = 0;
    for(int i = 0; i < m; i ++){
        int t = a[i].first;
        int p = a[i].second;
        if(currPos + j >=p){
            currPos = max(currPos, p);
            while(!pq.empty() && currPos + j >= pq.top()){
                currPos = max(currPos, pq.top());
                pq.pop();
            }
        }
        else{
            pq.push(p);
        }
        if(currPos + j > n){
            cout << t << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}