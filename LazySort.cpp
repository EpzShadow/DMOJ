#include "bits/stdc++.h"
using namespace std;
bool solve(int a, deque<int>stack1){
    deque<int>stack2;
    if(a == 1){
        stack2.push_back(stack1.front());
        stack1.pop_front();
    }
    else{
        stack2.push_back(stack1.back());
        stack1.pop_back();
    }
    while(!stack1.empty()){
        int x = stack1.front();
        int y = stack1.back();
        if(stack2.front() - 1 == x){
            stack2.push_front(x);
            stack1.pop_front();
        }
        else if(stack2.front() - 1 == y){
            stack2.push_front(y);
            stack1.pop_back();
        }
        else if(stack2.back() + 1 == x){
            stack2.push_back(x);
            stack1.pop_front();
        }
        else if(stack2.back() + 1 == y){
            stack2.push_back(y);
            stack1.pop_back();
        }
        else{
            return false;
        }
    }
    return true;
    
}
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <=t; i ++){
        int n;
        cin >> n;
        deque<int> stack1;
        for(int i = 0; i < n; i ++){
            int x;
            cin >> x;
            stack1.push_back(x);
        }
        if(solve(0, stack1) || solve(1, stack1))
            cout << "Case #" << i << ": " << "yes" << endl;
        else
            cout << "Case #" << i << ": " << "no" << endl;
    }
}