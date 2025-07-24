class Solution {
    vector<int>in;
    vector<int>out;
    bool ancestor(int x, int y)
    {
        if(in[x] <= in[y] && out[x] >= out[y])
        return true;

        return false;
    }
    void dfs(vector<int>adj[], vector<int>&nums, int node, vector<int>&vis, vector<int>&x_or, int par, int &timer)
    {
        vis[node] = 1;
        x_or[node] ^= nums[node];
        in[node] = ++timer;

        for(auto &x: adj[node])
        {
            if(!vis[x])
            {
                dfs(adj, nums, x, vis, x_or, node, timer);
                x_or[node] ^= x_or[x];
            }
        }

        out[node] = ++timer;
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int>adj[n];
        in.clear();
        in.resize(n, 0);
        out.clear();
        out.resize(n, 0);
        for(auto &x: edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int>visited(n, 0);
        vector<int>x_or(n, 0);
        int timer = 0;
        dfs(adj, nums, 0, visited, x_or, -1, timer);

        int total_xor = x_or[0];
       // cout<<x_or[4]<<" ";

    //    for(auto &x: in)
    //    {
    //      cout<<x<<" ";
    //    }

    //    cout<<"\n";

    //    for(auto &x: out)
    //    {
    //     cout<<x<<" ";
    //    }

        int answer = INT_MAX;

        for(int i=1; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int a = x_or[i];
                int b = x_or[j];

            if(ancestor(i, j))
            {
                a ^= b;

                int rem = total_xor ^ a;
                rem ^= b;
                int maxi = max({a, b, rem});
                int mini = min({a, b, rem});
                answer = min(answer, (maxi - mini)); 
            }
            else if(ancestor(j, i))
            {
                b ^= a;
                int rem = total_xor ^ a;
                rem ^= b;
                int maxi = max({a, b, rem});
                int mini = min({a, b, rem});
                answer = min(answer, (maxi - mini)); 
            }
            else
            {
                int rem = total_xor ^ a;
                rem ^= b;
                int maxi = max({a, b, rem});
                int mini = min({a, b, rem});
                answer = min(answer, (maxi - mini)); 
            }
            }
        }

      
        return answer;
    }
};