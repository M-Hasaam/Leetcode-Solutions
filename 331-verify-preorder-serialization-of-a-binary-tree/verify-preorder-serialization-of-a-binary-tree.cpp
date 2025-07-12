// 0ms CORRECT SOLUTION

// class Solution {
// public:
//     void test(const vector<int>& nodes, int& idx, const int& size) {

//         if (idx >= size) {
//             idx += 2;
//             return;
//         }

//         if (nodes[idx] != -1) {

//             idx++;

//             test(nodes, idx, size);
//             test(nodes, idx, size);

//         } else {

//             idx++;
//         }
//     }

//     bool isValidSerialization(string preorder) {

//         stringstream ss(preorder);

//         string token;

//         vector<int> nodes;
//         while (getline(ss, token, ',')) {
//             if (token == "#")
//                 nodes.push_back(-1);
//             else
//                 nodes.push_back(stoi(token));
//         }

//         int idx = 0;
//         int size = nodes.size();

//         test(nodes, idx, size);

//         return idx == size;
//     }
// };

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);

        string token;

        int slot = 1;

        while (getline(ss, token, ',')) {
            slot--;

            if (slot < 0)
                return false;

            if (token != "#")
                slot += 2;
        }

        return slot == 0;
    }
};