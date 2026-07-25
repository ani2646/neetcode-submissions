class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        vector<int> minf(n, INT_MAX);
        vector<int> vis(n, 0);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        minf[0] = 0;
        pq.push({0, 0}); // {cost, index}

        int ans = 0;

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int wt = curr[0];
            int index = curr[1];

            if (vis[index])
                continue;

            vis[index] = 1;
            ans += wt;

            for (int v = 0; v < n; v++) {

                if (!vis[v]) {

                    int dist =
                        abs(points[index][0] - points[v][0]) +
                        abs(points[index][1] - points[v][1]);

                    if (dist < minf[v]) {
                        minf[v] = dist;
                        pq.push({dist, v});
                    }
                }
            }
        }

        return ans;
    }
};