#include "bits/stdc++.h"
using namespace std;
int t, g, cnt = 0;
void print(vector<vector<bool>>a){
    for(int i = 1; i <=4; i ++){
        for(int j = 1; j <=4; j ++){
            cout << a[i][j];
        }
        cout << endl;
    }
}
int solve(vector<vector<bool>> matches, vector<int> points, int n){
    //if i played 6 games, then I do a check if this outcome is a win for my favourite team
    if(n >= 7){
        for(int i = 1; i <=4; i ++){
            if(i != t)
                if(points[i] >= points[t])
                    return 0;
        }
        return 1;
    }
    //other wise, i recursively go case by case.
    int ans = 0;
    for(int i = 1; i <=4; i ++){
        for(int j = i+1; j <= 4; j ++){
            if(!matches[i][j]){
                matches[i][j] = true;
                
                points[i]+= 3;
                ans += solve(matches, points, n+1);
                points[i] -=3;

                points[j] +=3;
                ans+= solve(matches, points, n+1);
                points[j] -=3;

                points[i] ++;
                points[j] ++;
                ans += solve(matches, points, n+1);
                points[i]--;
                points[j]--;

                matches[i][j] = false;
                return ans;
            }
        }
    }
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    vector<int>points(5, 0);
    vector<vector<bool>>matches(5, vector<bool>(5,0));
    cin >> t >> g;
    for(int i = 0, a, b, c, d; i < g; i ++){
        cin >> a >> b >> c >> d;
        if(c > d)
            points[a] +=3;
        else if (d > c)
            points[b] +=3;
        else{
            points[a]++;
            points[b]++;
        }
        matches[a][b] = true;
    } 
    cout << solve(matches, points, g+1) << endl;
}