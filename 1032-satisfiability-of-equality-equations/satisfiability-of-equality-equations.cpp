class Solution {
public:
    // using DSU
    int find(vector<int>& parent, int x) {
        if (parent[x] != x)
            parent[x] = find(parent, parent[x]); 
        return parent[x];
    }

    void unite(vector<int>& parent, int x, int y) {
        int px = find(parent, x);
        int py = find(parent, y);
        if (px != py)
            parent[px] = py;
    }

    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        for (int i = 0; i < 26; ++i)
            parent[i] = i;

        //  "=="
        for (const string& eq : equations) {
            if (eq[1] == '=') {
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';
                unite(parent, a, b);
            }
        }

        // "!="
        for (const string& eq : equations) {
            if (eq[1] == '!') {
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';
                if (find(parent, a) == find(parent, b))
                    return false;
            }
        }

        return true;
    }
};
