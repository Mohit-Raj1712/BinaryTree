/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
private:
    class checkBalance {
    
    public:
        int height;
        bool is_balanced;
        
    public:
        checkBalance(int height, bool is_balanced) {
            
            this -> height = height;
            this -> is_balanced = is_balanced;
        }        
    };
    
    
public:
    bool isBalanced(Node* root) {
        
        bool output = balanced_binary_tree(root) -> is_balanced;
        return output;
    }

private:
    checkBalance* balanced_binary_tree(Node* root) {
        
        if (root == nullptr)
            return new checkBalance(0, true);
            
        checkBalance* is_leftsubtree_balanced = balanced_binary_tree(root -> left);
        checkBalance* is_rightsubtree_balanced = balanced_binary_tree(root -> right);
        
        int left_subtree_height = is_leftsubtree_balanced -> height;
        int right_subtree_height = is_rightsubtree_balanced -> height;
        int height = max(left_subtree_height, right_subtree_height) + 1;
        
        bool balance_factor = abs(left_subtree_height - right_subtree_height) <= 1;
        bool is_tree_balanced = (is_leftsubtree_balanced -> is_balanced && is_rightsubtree_balanced -> is_balanced) && balance_factor;
        
        return new checkBalance(height, is_tree_balanced);
    }
};