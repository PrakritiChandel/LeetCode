class Solution {
public:
    vector<pair<int,int>> directions = { {1,0}, {0,1}, {-1,0}, {0,-1} };
    typedef tuple<int,int,int> int3;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int N = moveTime.size(), M = moveTime[0].size();
        vector<vector<int>> distance(N, vector<int>(M, INT_MAX));
        priority_queue<int3, vector<int3>, greater<int3>> pq;
        pq.push({0,0,0});

        while (pq.size()){
            auto [time, x, y] = pq.top(); pq.pop();
            for (const auto [dx, dy] : directions){
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || nx >= N) continue;
                if (ny < 0 || ny >= M) continue;

                // the ONLY change: if the manhattan distance from 0,0 is odd, 
                // then the cost is 2. if even, then its one. This is always true
                // because a grid is a bipartite graph.
                int cost = ((x+y)%2 == 1) ? 2 : 1;

                int timeAtNeighbor = max(time, moveTime[nx][ny]) + cost;
                if (timeAtNeighbor >= distance[nx][ny]) continue; 
                distance[nx][ny] = timeAtNeighbor;
                pq.push({timeAtNeighbor,nx,ny});
            }
        }
        return distance[N-1][M-1];
    }
};