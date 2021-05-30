#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, q;
    cin >> m;
    cin >> q;
    vector<string> names;
    vector<int> times;
    vector<int> dp;
    vector<int> groupings;
    dp.resize(q + 1, INT_MAX);
    names.resize(q + 1);
    times.resize(q + 1);
    groupings.resize(q + 1);
    for (int i = 1; i <= q; i++) {
        cin >> names[i];
        cin >> times[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= q; i++) {
        int temp = 0;
        for (int j = i; i - j + 1 <= m && j >= 1; j--) {
            temp = max(temp, times[j]);
            if (temp + dp[j - 1] < dp[i]) {
                groupings[i] = j;
                dp[i] = temp + dp[j - 1];
            }
        }
    }
    vector<string>groupNames;
    int i = q;
    while (i >= 1) {
        int k = groupings[i];
        string s = "";
        for (int j = k; j <= i; j++) {
            s = s + names[j];
            s = s + " ";
        }
        s.pop_back();
        groupNames.push_back(s);
        i = k - 1;
    }
    reverse(groupNames.begin(), groupNames.end());

    cout << "Total Time: " << dp[q] << endl;
    for (i = 0; i < groupNames.size(); i++) {
        cout << groupNames[i] << endl;
    }
}