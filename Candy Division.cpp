#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
// #define int long long
using namespace std; 
int main(){
    int n, ans = 0;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++)cin >> arr[i];
    sort(arr.begin(), arr.end());
    if(n%2)ans = 0;
    else{
        ans = arr[n/2] - arr[n/2-1];
    }
    cout << ans;
}
