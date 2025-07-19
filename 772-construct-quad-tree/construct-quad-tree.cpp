/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }

private:
    Node* build(const vector<vector<int>>& grid, int row, int col, int size) {

        if (isUniform(grid, row, col, size))
            return new Node(grid[row][col], true);

        int new_size = size / 2;

        Node* TL = build(grid, row, col, new_size);
        Node* TR = build(grid, row, col + new_size, new_size);
        Node* BL = build(grid, row + new_size, col, new_size);
        Node* BR = build(grid, row + new_size, col + new_size, new_size);

        return new Node(false, false, TL, TR, BL, BR);
    }

    bool isUniform(const vector<vector<int>>& grid, int row, int col,
                   int size) {
        int val = grid[row][col];

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (grid[row + i][col + j] != val)
                    return false;

        return true;
    }
};