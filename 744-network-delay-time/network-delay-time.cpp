
// using BFS 92 ms
class Solution2 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using P = pair<int, int>; // next , time

        vector<vector<P>> graph(n + 1); // 1-based indexing

        for (const vector<int>& time : times) {
            int u = time[0], v = time[1], w = time[2];
            graph[u].emplace_back(v, w);
        }

        vector<int> visited(n + 1, INT_MAX); // 1-based indexing
        visited[k] = 0;

        queue<int> q;
        q.push(k);

        int Max = 0;

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (auto& [next, weight] : graph[front]) {
                if (visited[next] > visited[front] + weight) {
                    visited[next] = visited[front] + weight;
                    q.push(next);
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (visited[i] == INT_MAX)
                return -1;
            Max = max(Max, visited[i]);
        }

        return Max;
    }
};

// using Priority BFS
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using P = pair<int, int>;

        // P = ( next , time )
        vector<vector<P>> graph(n + 1); // 1-based indexing

        for (const vector<int>& time : times) {
            int u = time[0], v = time[1], w = time[2];
            graph[u].emplace_back(v, w);
        }

        vector<int> min_time(n + 1, INT_MAX);        // 1-based indexing
        priority_queue<P, vector<P>, greater<P>> pq; // P = ( time , src )

        min_time[k] = 0;
        pq.emplace(0, k);

        while (!pq.empty()) {

            auto [curr_time, front] = pq.top();
            pq.pop();

            if (curr_time > min_time[front])
                continue;

            for (auto& [next, time] : graph[front]) {

                if (min_time[next] > time + curr_time) {
                    min_time[next] = time + curr_time;

                    pq.emplace(min_time[next], next);
                }
            }
        }

        int Max = 0;

        for (int i = 1; i <= n; ++i) {
            if (min_time[i] == INT_MAX)
                return -1;
            Max = max(Max, min_time[i]);
        }

        return Max;
    }
};