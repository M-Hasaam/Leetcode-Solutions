class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> adj(n);

        for (const auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n, INT_MAX);

        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto [v, vd] : adj[u]) {

                int nd = d + vd + 1;

                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves)
                count++;
        }
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            int a = max(maxMoves - dist[u], 0);
            int b = max(maxMoves - dist[v], 0);

            count += min(w, a + b);
        }

        return count;
    }
};

class Solution___ {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<int>> graph(n, vector<int>(n, INT_MIN));
        vector<vector<int>> v_e(n, vector<int>(n, INT_MIN));

        for (const auto& e : edges) {
            graph[e[0]][e[1]] = e[2];
            graph[e[1]][e[0]] = e[2];
            v_e[e[0]][e[1]] = e[2];
            v_e[e[1]][e[0]] = e[2];
        }

        queue<tuple<int, int, int>> q;
        vector<bool> visited(n, false);

        q.push({0, 0, -1});
        visited[0] = true;
        int count = 1;

        while (!q.empty()) {
            auto [curr, moves, parent] = q.front();
            q.pop();

            if (moves >= maxMoves)
                continue;

            for (int nbr = 0; nbr < n; nbr++) {
                int w = graph[curr][nbr];

                if (w == INT_MIN || parent == nbr)
                    continue;

                cout << "moves=" << moves << " w=" << w << endl;
                if (moves + w + 1 > maxMoves) {

                    count += min(maxMoves - moves, v_e[curr][nbr]);

                    v_e[curr][nbr] = 0;
                    v_e[nbr][curr] = min(v_e[nbr][curr],
                                         graph[curr][nbr] - (maxMoves - moves));

                    // graph[nbr][curr] -= maxMoves - moves;
                    cout << "graph[" << curr << "][" << nbr
                         << "]=" << graph[nbr][curr] << endl;
                } else {

                    count += min(v_e[curr][nbr], w);
                    v_e[curr][nbr] = v_e[nbr][curr] = 0;

                    if (!visited[nbr]) {
                        cout << "visited[" << nbr << "]\n";
                        count += 1;
                        visited[nbr] = true;
                    }
                    // if (nbr == 2)
                    //     cout << "--->" << curr << endl;
                    q.push({nbr, moves + w + 1, curr});
                }
                cout << curr << "->" << nbr << " count=" << count << endl
                     << endl;
            }
        }

        return count;
    }
};
class Solution__ {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<int>> graph(n, vector<int>(n, -1));

        for (const auto& e : edges) {
            graph[e[0]][e[1]] = e[2];
            graph[e[1]][e[0]] = e[2];
        }

        queue<tuple<int, int, int>> q;
        vector<bool> visited(n, false);

        q.push({0, 0, -1});
        visited[0] = true;
        int count = 1;

        while (!q.empty()) {
            auto [curr, moves, parent] = q.front();
            q.pop();

            if (moves >= maxMoves)
                continue;

            for (int nbr = 0; nbr < n; nbr++) {
                int w = graph[curr][nbr];

                if (w <= -1 || parent == nbr)
                    continue;

                cout << "moves=" << moves << " w=" << w << endl;
                if (moves + w + 1 > maxMoves) {
                    count += (maxMoves - moves);
                    graph[curr][nbr] = 0;
                    graph[nbr][curr] -= maxMoves - moves;
                    cout << "graph[" << curr << "][" << nbr
                         << "]=" << graph[nbr][curr] << endl;
                } else {

                    count += w;
                    graph[curr][nbr] = graph[nbr][curr] = -1;

                    if (!visited[nbr]) {
                        cout << "visited[" << nbr << "]\n";
                        count += 1;
                        visited[nbr] = true;
                    }
                    if (nbr == 2)
                        cout << "--->" << curr << endl;
                    q.push({nbr, moves + w + 1, curr});
                }
                cout << curr << "->" << nbr << " count=" << count << endl
                     << endl;
            }
        }

        return count;
    }
};

class Solution_ {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> graph(n);

        for (const auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        queue<tuple<int, int, int>> q;
        vector<bool> visited(n, false);

        q.push({0, 0, -1});
        // visited[0] = true;
        int count = 1;

        while (!q.empty()) {
            auto [curr, moves, parent] = q.front();
            q.pop();

            for (auto [nbr, w] : graph[curr]) {
                if (visited[nbr] || parent == nbr)
                    continue;

                if (moves + w > maxMoves) {
                    count += (maxMoves - moves);
                } else {
                    visited[nbr] = true;
                    count += w + 1;
                    q.push({nbr, moves + w + 1, curr});
                }

                cout << count << endl;
            }
        }

        return count;
    }
};