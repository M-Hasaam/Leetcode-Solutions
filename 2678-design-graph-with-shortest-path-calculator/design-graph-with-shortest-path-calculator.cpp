class Graph {
    vector<vector<pair<int, int>>> graph;
    using P = pair<int, int>;
    int size;

public:
    Graph(int n, vector<vector<int>>& edges) : graph(n), size(n) {
        for (const auto& e : edges) {
            graph[e[0]].push_back(P{e[2], e[1]});
        }
    }

    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back(P{edge[2], edge[1]});
    }

    int shortestPath(int node1, int node2) {

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> dist(size, INT_MAX);

        pq.emplace(0, node1);
        dist[node1] = 0;

        while (!pq.empty()) {
            auto [curr_dist, curr] = pq.top();
            pq.pop();

            if (curr_dist > dist[curr])
                continue;

            if (curr == node2)
                return dist[curr];

            for (auto [nxt_dist, nxt] : graph[curr]) {
                int new_dist = curr_dist + nxt_dist;

                if (new_dist >= dist[nxt])
                    continue;

                dist[nxt] = new_dist;
                pq.emplace(new_dist, nxt);
            }
        }

        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */