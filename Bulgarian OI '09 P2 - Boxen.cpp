#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std; 
const int MM = 1e5 + 5;
int n;
int parent[MM];
int find(int v){
    if(v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}
void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b)
        parent[b] = a;
}
void solve(){
    cin >> n;
    set<int>st;
    for(int i = 1; i<=n;i++)
        parent[i] = i;
    for(int i = 1, a; i <=n; i++){
        cin >> a;
        unite(i, a);
    }
    for(int i = 1; i <=n; i++){
        int n = find(parent[i]);
        st.insert(n);
    }
    cout << st.size() << ' ';
}
int main(){
    int t = 2;
    while(t--)solve();
}
