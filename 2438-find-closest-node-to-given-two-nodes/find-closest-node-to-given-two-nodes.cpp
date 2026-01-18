class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> dist1(n, -1), dist2(n, -1);

        for (int cur = node1, d = 0; cur != -1 && dist1[cur] == -1;
             cur = edges[cur]) {
            dist1[cur] = d++;
        }

        for (int cur = node2, d = 0; cur != -1 && dist2[cur] == -1;
             cur = edges[cur]) {
            dist2[cur] = d++;
        }

        int ans = -1;
        int best = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int mx = max(dist1[i], dist2[i]);
                if (mx < best) {
                    best = mx;
                    ans = i;
                }
            }
        }

        return ans;
    }
};
