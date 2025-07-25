class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();

        vector<bool> visited(n, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {

            int front = q.front();
            q.pop();

            for (int next : rooms[front]) {

                if (!visited[next]) {
                    visited[next] = true;

                    q.push(next);
                }
            }
        }

        return find(visited.begin(), visited.end(), false) == visited.end();
    }
};