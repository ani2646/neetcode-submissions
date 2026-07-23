class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // dist[node][f] = minimum cost to reach 'node' using exactly 'f' flights
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        vector<vector<pair<int,int>>> adj(n);

        for (auto &edge : flights) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }

        // {cost, flightsUsed, node}
        priority_queue<
    tuple<int,int,int>,
    vector<tuple<int,int,int>>,
    greater<tuple<int,int,int>>
> pq;

        dist[src][0] = 0;
        pq.push({0, 0, src});

        while (!pq.empty()) {

            auto [cost, flightsUsed, node] = pq.top();
            pq.pop();

            // stale state
            if (cost > dist[node][flightsUsed])
                continue;

            // Cannot take more than k+1 flights
            if (flightsUsed == k + 1)
                continue;

            for (auto &[nei, wt] : adj[node]) {

                int newCost = cost + wt;
                int newFlights = flightsUsed + 1;

                if (newCost < dist[nei][newFlights]) {
                    dist[nei][newFlights] = newCost;
                    pq.push({newCost, newFlights, nei});
                }
            }
        }

        int ans = INT_MAX;

        for (int flightsUsed = 0; flightsUsed <= k + 1; flightsUsed++) {
            ans = min(ans, dist[dst][flightsUsed]);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};