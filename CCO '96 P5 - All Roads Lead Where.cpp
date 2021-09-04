    #include "bits/stdc++.h"
    #define pb push_back
    #define f first
    #define s second
    // #define int long long
    using namespace std; 
    int n, t;
    string a, b, s;
    vector<char> adj[26];
    void solve(){
        int dis[26], pre[26];
        for(int i = 0; i  < 26; i ++)dis[i] = 100, pre[i] = i;
        cin >> a >> b;
        char c, d;
        c = a[0], d = b[0];
        queue<char>q;
        q.push(c);
        dis[c-'A'] = 0;
        while(!q.empty()){
            char v = q.front();
            q.pop();
            for(char u : adj[v-'A']){
                if(dis[u-'A'] == 100){
                    dis[u-'A'] = min(dis[u-'A'], dis[v-'A'] + 1);
                    q.push(u);
                    pre[u-'A'] = v-'A';
                }
            }
        }
        s = "";
        int curr = d-'A';
        for(int i = 0; i < dis[d-'A']; i ++){
            char e = curr + 'A';
            s = e + s;
            curr = pre[curr];
        }
        cout << c << s << endl;
    }
    signed main(){
        cin >> n >> t;
        for(int i = 0; i < n; i ++){
            char c,d;
            cin >> a >> b;
            c = a[0], d = b[0];
            adj[c-'A'].pb(d);
            adj[d-'A'].pb(c);
        }
        while(t--)
            solve();
    }
