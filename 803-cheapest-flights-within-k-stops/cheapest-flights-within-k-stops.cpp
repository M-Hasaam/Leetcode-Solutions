class Solution {
    struct Node {
        int cost, u, k;
        Node(int a, int b, int c) {
            cost = a;
            u = b;
            k = c;
        }

        bool operator<(const Node& O) const { return cost > O.cost; }
    };

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        using P = pair<int, int>;
        using T = tuple<int, int, int>;

        vector<vector<P>> graph(n);
        for (auto F : flights) {
            graph[F[0]].push_back({F[1], F[2]});
        }

        // priority_queue<T, vector<T>, greater<>> pq;
        priority_queue<Node> pq;
        vector<int> Cost(n, INT_MAX);
        vector<int> Stops(n, INT_MAX);

        pq.push({0, src, 0});
        Cost[src] = 0;
        Stops[src] = 0;

        while (!pq.empty()) {
            Node curr = pq.top();
            pq.pop();

            cout << " U= " << curr.u << " Cost= " << curr.cost
                 << " Stops= " << curr.k << endl;

            if (curr.u == dst)
                return curr.cost;

            for (auto [v, C] : graph[curr.u]) {
                int n_cost = curr.cost + C;
                int n_k = curr.k + 1;

                if (n_k > k + 1)
                    continue;

                if (n_cost < Cost[v] || n_k < Stops[v]) {
                    Cost[v] = n_cost;
                    Stops[v] = n_k;
                    pq.push({n_cost, v, n_k});
                }
            }
        }

        return -1;
    }
};