class Solution {
public:
    struct node {
        int u;
        int cost;
        int time;
        node(int a =0,  int b=0 , int c=0) : u(a) , cost(b) , time(c) {}
    };



    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        
        auto cmp = [](const node& a, const node& b) {
            if (a.cost == b.cost)
                return a.time > b.time;   // min time
            return a.cost > b.cost;       // min cost
        };
        int numberOfStops = passingFees.size();

        vector<vector<pair<int,int>>>graph(numberOfStops );
        for (auto& edge : edges){
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
        }

        // for (int i = 0 ; i < numberOfStops ; i++){
        //     cout << i << "-> ";
        //     for (auto& list: graph[i])
        //         cout << "{"<< list.first  << "," << list.second << "} ";
        //     cout << endl;
        // }


        priority_queue<node, vector<node>, decltype(cmp)> qu(cmp);
        vector<int>visited(numberOfStops , 0);

        vector<vector<int>> best(numberOfStops, vector<int>(maxTime + 1, INT_MAX));
        
        best[0][0] = passingFees[0];
        qu.push({0, passingFees[0], 0});

        while (!qu.empty()) {
            node temp = qu.top();
            qu.pop();

            if (temp.u == numberOfStops - 1)
                return temp.cost;

            for (auto& [v, w] : graph[temp.u]) {
                int newTime = temp.time + w;
                if (newTime > maxTime) continue;

                int newCost = temp.cost + passingFees[v];

                if (newCost < best[v][newTime]) {
                    best[v][newTime] = newCost;
                    qu.push({v, newCost, newTime});
                }
            }
        }


        return -1;
    }
};
class Solution_states {
public:
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {

        int n = passingFees.size();
        using P = pair<int, int>;

        vector<vector<P>> graph(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1], t = e[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }

        using T = tuple<int, int, int>; // cost , time , index
        priority_queue<T, vector<T>, greater<>> pq;
        vector<queue<int>> visited_C(n);
        vector<queue<int>> visited_T(n);
        vector<queue<int>> parent(n);

        for (int i = 0; i < n; i++) {
            visited_C[i].push(INT_MAX);
            visited_T[i].push(INT_MAX);
            parent[i].push(-1);
        }

        pq.push({passingFees[0], 0, 0});
        visited_C[0].front() = passingFees[0];
        visited_T[0].front() = 0;

        while (!pq.empty()) {
            auto [C, T, curr] = pq.top();
            cout << " C= " << C << " T= " << T << " curr= " << curr << endl;
            pq.pop();

            if (T > maxTime)
                continue;

            for (auto [nxt, t] : graph[curr]) {
                if (nxt == parent[curr].front())
                    continue;

                int nxt_T = T + t, nxt_C = C + passingFees[nxt];

                if (nxt_T > maxTime)
                    continue;

                if (nxt_C < visited_C[nxt].front()) {
                    visited_C[nxt].front() = nxt_C;
                    visited_T[nxt].front() = nxt_T;
                    parent[nxt].front() = curr;
                    pq.push({nxt_C, nxt_T, nxt});
                } else if (nxt_T < visited_T[nxt].front()) {
                    visited_C[nxt].push(nxt_C);
                    visited_T[nxt].push(nxt_T);
                    parent[nxt].push(curr);
                    pq.push({nxt_C, nxt_T, nxt});
                }
            }
        }

        int Min = visited_C[n - 1].front();
        return Min == INT_MAX ? -1 : Min;
    }
};
class Solution_DFS {
public:
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {

        int n = passingFees.size();
        using P = pair<int, int>;

        vector<vector<P>> graph(n);
        for (const auto& e : edges) {
            int u = e[0], v = e[1], t = e[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }

        int Min = INT_MAX;

        function<void(int, int, int, int)> dfs = [&](int curr, int cost,
                                                     int time, int prev) {
            // cout << " pre = " << prev << " curr = " << curr
            //      << " cost = " << cost << " time = " << time << endl;
            if (cost >= Min || time > maxTime)
                return;

            if (curr == n - 1) {
                Min = min(cost, Min);
            }

            for (auto [nxt, t] : graph[curr]) {
                if (nxt == prev)
                    continue;
                dfs(nxt, cost + passingFees[nxt], time + t, curr);
            }
        };

        dfs(0, passingFees[0], 0, 0);

        return Min == INT_MAX ? -1 : Min;
    }
};