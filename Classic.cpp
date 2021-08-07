#include "bits/stdc++.h"
using namespace std;
int main(){
    deque<int>mx, mi;
    int ans = 0, n, k, arr[(int)3e6+5];
    cin >> n >> k;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    for(int j = 0, i = 0; j < n; j ++){
        while(!mx.empty() && mx.back() < arr[j])mx.pop_back();
        while(!mi.empty() && mi.back() > arr[j])mi.pop_back();
        mx.push_back(arr[j]), mi.push_back(arr[j]);
        while(mx.front() - mi.front() > k){
            if(mx.front() == arr[i])mx.pop_front();
            if(mi.front() == arr[i])mi.pop_front();
            i++;
        }
        ans += j-i+1;
    }
    cout << ans << endl;
}