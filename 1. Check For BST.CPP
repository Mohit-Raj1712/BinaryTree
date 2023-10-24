// link to the problem : https://practice.geeksforgeeks.org/problems/check-for-bst/1?page=1&category[]=Tree&sortBy=submissions

class Solution {
private:
    class checkBST {
    public:
        bool isBST;
        int max, min;
        
        checkBST(int min, int max, bool isBST) {
            
            this -> min = min;
            this -> max = max;
            this -> isBST = isBST;
        }
    };
    
public:
    bool isBST(Node* root) {
        
        bool output = validate_BST(root) -> isBST;
        return output;
    }
    
private:
    checkBST* validate_BST(Node* root) {
        
        if (root == nullptr)
            return new checkBST(INT_MAX, INT_MIN, true);
        
        checkBST* left_subtree = validate_BST(root -> left);
        checkBST* right_subtree = validate_BST(root -> right);
        
        bool is_left_subtree_BST = left_subtree -> isBST;
        bool is_right_subtree_BST = right_subtree -> isBST;
        
        int left_subtree_max = left_subtree -> max;
        int right_subtree_min = right_subtree -> min;
        
        bool isBST = is_left_subtree_BST && is_right_subtree_BST && (left_subtree_max < root -> data && root -> data < right_subtree_min);
        
        int min = fmin(root -> data, fmin(left_subtree -> min, right_subtree -> min));
        int max = fmax(root -> data, fmax(left_subtree -> max, right_subtree -> max));
        
        return new checkBST(min, max, isBST);
    }
};