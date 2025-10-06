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
    Node* intersect(Node* quadTree1, Node* quadTree2) {

        if (quadTree1->isLeaf) {
            if (quadTree1->val == 1)
                return new Node(1, 1);
            return new Node(*quadTree2);
        }
        if (quadTree2->isLeaf) {
            if (quadTree2->val == 1)
                return new Node(1, 1);
            return new Node(*quadTree1);
        }

        Node* topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* bottomLeft =
            intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* bottomRight =
            intersect(quadTree1->bottomRight, quadTree2->bottomRight);

        if ((topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf &&
             bottomRight->isLeaf) &&
            (topLeft->val == topRight->val &&
             topRight->val == bottomLeft->val &&
             bottomLeft->val == bottomRight->val)) {
            return new Node(topLeft->val, 1);
        }

        return new Node(0, 0, topLeft, topRight, bottomLeft, bottomRight);
    }
};