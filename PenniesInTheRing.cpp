#include"bits/stdc++.h"
using namespace std;
int solve(int r){
    double r2 = (double)(r * r);
    int ans = 0;
    for(int x = 1; x <= r; x ++){
        ans += (int)(sqrt(r2 - double(x*x))+ 1);
    }
    ans *= 4;
    ans ++;
    return ans;
}
int main(){
    int n = -1;
    while(true){
        scanf("%d", &n);
        if(n == 0)
        return 0;
        printf("%d\n", solve(n));
    }
    
}