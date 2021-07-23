#include "bits/stdc++.h"
using namespace std;
const int MM = 2e5 + 2;
int parent[MM];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>adj(n+1);
    // vector<pair<int, int>>edges(m);
    // vector<vector<int, int>>adj()
    for(int i = 1; i <= n; i ++)
        parent[i] = i;
    int cnt = 0;
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        if(find_set(a) != find_set(b)){
            union_sets(a,b);
        }
        else
            cnt ++;
    }
    if(cnt <= 1)
        cout << "YES";
    else
    cout << "NO";
    // cout << c;
    // if(n - c ==  m || n - c + 1 == m){
    //     cout << "YES";
    // }
    // else{
    //     cout << "NO";
    // }
    //a graph is a tree if there is one less edge than nodes
    //this means if I have "c" trees, then the number of edges I should have is N-C
    //N is the number of total nodes, and for each connected component, I subtract one edge
    //so the answer is YES if M = N-C or M = N-C+1




    
}