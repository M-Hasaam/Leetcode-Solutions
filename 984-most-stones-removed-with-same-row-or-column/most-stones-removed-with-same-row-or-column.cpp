class Solution {
public:
    vector<int> parent;

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        parent.assign(n,0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    Union(i, j);
                }

        unordered_set<int> unique_sets;

        for (int i = 0; i < n; i++)
            unique_sets.insert(find_parent(i));

        return n - unique_sets.size();
    }

private:
    int find_parent(int n) {

        if (parent[n] != n)
            parent[n] = find_parent(parent[n]); // path compression O(log(n))

        return parent[n];
    }

    void Union(int a, int b) {

        int Pa = find_parent(a);
        int Pb = find_parent(b);

        if (Pa != Pb)
            parent[Pa] = Pb;
    }
};