#include "bits/stdc++.h"
using namespace std;
void solve(){
    int n;
    scanf("%d", &n);
    stack<int>mountain;
    stack<int>branch;
    stack<int>lake;
    lake.push(0);
    for(int i = 0; i < n; i ++){
        int x;
        scanf("%d", &x);
        mountain.push(x);
    }    
    while(!mountain.empty() || !branch.empty()){
        if(!mountain.empty() && mountain.top() == lake.top()+1){
            lake.push(mountain.top());
            mountain.pop();
        }
        else if(!branch.empty() && branch.top() == lake.top() + 1){
            lake.push(branch.top());
            branch.pop();
        } 
        else{
            branch.push(mountain.top());
            mountain.pop();
        }
        if(!branch.empty() && mountain.empty() && branch.top() != lake.top() +1){
            break;
        }
    }
    lake.top() == n? cout << 'Y' << endl: cout << 'N' << endl; 
}
int main(){
    int t;
    cin >> t;
    while(t--)
    solve();
}