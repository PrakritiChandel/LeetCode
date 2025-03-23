class Solution {
public: 
    typedef long long ll; // Because typing "long long" is too much work \U0001f644
    typedef pair<ll, int> P; // Pair of (time, node) for the priority queue
    int mod = 1e9 + 7; // Modulo because the problem loves big numbers

    int countPaths(int n, vector<vector<int>>& roads) {
        // Step 1: Build the graph—because we can’t do anything without it \U0001f3d7️
        unordered_map<int, vector<P>> adj; // Adjacency list: node -> (neighbor, time)
        for (auto& e : roads) {
            adj[e[0]].push_back({e[1], e[2]}); // Add edge u -> v
            adj[e[1]].push_back({e[0], e[2]}); // Add edge v -> u (undirected, duh!)
        }
        
        // Step 2: Set up the source and destination \U0001f30d
        int src = 0;
        int dest = n - 1;

        // Step 3: Set up for counting paths \U0001f4dd
        unordered_map<int, ll> freq; // Number of shortest paths to each node
        freq[src] = 1; // There’s 1 way to reach the source—by standing still, genius!

        // Step 4: Set up Dijkstra’s with a priority queue \U0001f6e0️
        priority_queue<P, vector<P>, greater<P>> pq; // Min-heap: (time, node)
        pq.push({0, src}); // Start at source with time 0

        vector<ll> time(n, LLONG_MAX); // Shortest time to reach each node
        time[src] = 0; // It takes 0 time to reach the source—shocking!
        
        // Step 5: Run Dijkstra’s with a twist to count paths \U0001f504
        while (!pq.empty()) {
            ll currT = pq.top().first; // Current time
            int node = pq.top().second; // Current node
            pq.pop();
            if (currT > time[node]) continue; // Skip if we found a faster path already—Dijkstra’s rules!

            // Check all neighbors of the current node
            for (auto& nbr : adj[node]) {
                int nbrNode = nbr.first; // Neighbor node
                ll edgeT = nbr.second; // Time to reach the neighbor

                // Case 1: Found a faster path to the neighbor \U0001f3ce️
                if (time[nbrNode] > time[node] + edgeT) {
                    time[nbrNode] = time[node] + edgeT; // Update shortest time
                    freq[nbrNode] = freq[node]; // Same number of paths as the current node
                    pq.push({time[nbrNode], nbrNode}); // Add to queue to explore further
                }
                // Case 2: Found another path with the same time \U0001f6e4️
                else if (time[nbrNode] == time[node] + edgeT) {
                    freq[nbrNode] = (freq[nbrNode] + freq[node]) % mod; // Add the number of paths
                }
            }
        }

        // Step 6: Return the number of shortest paths to the destination \U0001f389
        return freq[n-1] % mod; // Don’t forget the modulo—because big numbers are scary!
    }
};