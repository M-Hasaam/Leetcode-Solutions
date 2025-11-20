class Solution {

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();

        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> dist(N, INT_MAX);
        vector<bool> visited(N, false);

        pq.push({0, 0});
        dist[0] = 0;
        visited[0] = true;

        while (!pq.empty()) {

            auto [d, curr] = pq.top();
            pq.pop();
            visited[curr] = true;

            for (int nxt = 0; nxt < N; nxt++) {
                if (nxt == curr || visited[nxt])
                    continue;

                int nxt_dist = abs(points[curr][0] - points[nxt][0]) +
                               abs(points[curr][1] - points[nxt][1]);

                if (nxt_dist < dist[nxt]) {
                    dist[nxt] = nxt_dist;
                    pq.push({dist[nxt], nxt});
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += dist[i];

        return sum;
    }
};