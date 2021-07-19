#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n, ans = 0;
    cin >> n;
    stack<pair<int, int>>stack;
    for(int i = 0; i < n; i ++){
        int h;
        cin >> h;
        while(!stack.empty() && stack.top().first < h){
            ans += stack.top().second;
            stack.pop();
        }
        if(stack.empty())
            stack.push({h,1});
        else{
            if(stack.top().first == h){
                ans += stack.top().second + (stack.size()>1);
                stack.top().second++;
            }
            else{
                ans++;
                stack.push({h,1});
            }
        }
    }
    cout << ans << endl;
}