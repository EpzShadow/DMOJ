#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define unsigned long long
using namespace std;
int n, m, dp[3005][3005];
string a,b;
int main(){
    cin >> a >> b;
    n = a.size();
    m = b.size();
    for(int i = 0; i <= n; i++)
        for(int j = 0; j<=m ;j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    
    string s = "";
    int i = n, j = m;
    while(i > 0 && j > 0){

        if(a[i-1] == b[j-1]){
            s += a[i-1];
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    reverse(s.begin(), s.end());
    cout << s;
}
