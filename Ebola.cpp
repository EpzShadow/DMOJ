#include<bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 2;
int parent[MM], size[MM];

void make_set(int v) {
    parent[v] = v;
}

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

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        make_set(i);
    while (m--) {
        int q;
        cin >> q;
        int arr[MM];
        for (int i = 0; i < q; i++)
            cin >> arr[i];
        for (int i = 1; i < q; i++)
            union_sets(arr[i], arr[i - 1]);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int x = find_set(1);
        if (find_set(i) == x)
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i : ans)
       cout << i << ' ';
}