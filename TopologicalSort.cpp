#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> pre; //It will be given
    vector<int> adj[n];
    vector<int> ind(n, 0);
    vector<bool> vis(n, false);
    for (auto c : pre)
    {
        adj[c[0]].push_back(c[1]);
        ind[c[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
            vis[i] = true;
        }
    }
    vector<int> topo;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        topo.push_back(x);
        for (auto c : adj[x])
        {
            ind[c]--;
            if (ind[c] == 0 && vis[c] == false)
            {
                q.push(c);
                vis[c] = true;
            }
        }
    }
    return 0;
}
