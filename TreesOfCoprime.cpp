class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        vector<vector<int>> coprimes(51);
        for(int i=1; i<=50; ++i) {
            vector<int> v;
            for(int j=1; j<=50; ++j) {
                if(gcd(i, j) == 1)
                    v.push_back(j);
            }
            coprimes[i] = v;
        }
        
        int n = nums.size();
        vector<list<int>> G(n);
        for(vector<int>& e : edges) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        
        vector<int> res(n);
        vector<bool> vis(n, false);
        
        function<void(int, vector<int>&)> dfs = [&] (int u, vector<int>& c) {
            res[u] = c[nums[u]];
            vis[u] = true;
            
            for(int v : G[u]) {
                if(!vis[v]) {
                    vector<int> nc = c;
                    for(int x : coprimes[nums[u]])
                        nc[x] = u;
                    dfs(v, nc);
                }
            }
        };
        vector<int> c(51, -1);
        dfs(0, c);
        return res;
    }
};
