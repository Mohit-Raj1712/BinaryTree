class Solution {
public:
    bool hasPathSum(Node *root, int target) {
        
        if (root == nullptr)
            return false;
        
        if (root -> left == nullptr && root -> right == nullptr)
            if (target - root -> data == 0)
                return true;
        
        return hasPathSum(root -> left, target - root -> data) || hasPathSum(root -> right, target - root -> data);
    }
};