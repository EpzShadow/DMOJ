#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std; 
const int MM = 10005;
int adj[MM];
int n;
int main(){
    int x = -1, y = -1;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        adj[a] = (b);
    }
    do{
        int seperation = -1;
        vector<int>vis(MM);
        cin >> x >> y;
        if(x == 0 && y == 0)break;
        do{
            vis[x] = true;
            x = adj[x];
            seperation ++;
        }while(x != y && !vis[x]);
        if(x==y)cout << "Yes " << seperation << endl;
        else cout << "No" << endl;

    }while(x != 0 && y != 0);
}
