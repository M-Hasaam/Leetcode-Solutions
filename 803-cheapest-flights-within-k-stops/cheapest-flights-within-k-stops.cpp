class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        using P = pair<int, int>;
        vector<vector<P>> graph(n);

        for (const auto& flight : flights) {
            int from = flight[0], to = flight[1], cost = flight[2];
            graph[from].emplace_back(to, cost);
        }

        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<>> pq;
        pq.emplace(0, src, 0);

        vector<int> min_cost(n, INT_MAX);
        min_cost[src] = 0;

        vector<int> stops(n, INT_MAX);
        stops[src] = 0;

        while (!pq.empty()) {
            auto [curr_cost, curr_node, curr_k] = pq.top();
            pq.pop();

            if (curr_node == dst) {
                return curr_cost;
            }

            if (curr_k > k) {
                continue;
            }

            for (const auto& [next_node, next_cost] : graph[curr_node]) {
                int new_cost = curr_cost + next_cost;
                int new_stops = curr_k + 1;

                if (new_cost < min_cost[next_node] || new_stops < stops[next_node]) {
                    min_cost[next_node] = new_cost;
                    stops[next_node] = new_stops;
                    pq.emplace(new_cost, next_node, new_stops);
                }
            }
        }

        return -1;
    }
};