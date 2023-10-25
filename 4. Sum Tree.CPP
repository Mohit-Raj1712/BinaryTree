class Pair {
public:
    bool is_sum_tree;
    int sum;
    
    Pair(bool is_sum_tree, int sum) {
        
        this -> is_sum_tree = is_sum_tree;
        this -> sum = sum;
    }
};

class Solution {
public:
    bool isSumTree(Node* root) {
        
        if (root == nullptr)
            return true;
        
        return f(root) -> is_sum_tree;
    }
    
private:
    Pair* f(Node* root) {
        
        if (root == nullptr)
            return new Pair(true, 0);
        
        if (root -> left == nullptr && root -> right == nullptr)
            return new Pair(true, root -> data);
            
        Pair* left_subtree = f(root -> left);
        Pair* right_subtree = f(root -> right);
        
        if (left_subtree -> is_sum_tree == false || right_subtree -> is_sum_tree == false) 
            return new Pair(false, -1);
        
        int root_val = root -> data;
        int left_subtree_sum = left_subtree -> sum;
        int right_subtree_sum = right_subtree -> sum;
        int sum = left_subtree_sum + right_subtree_sum;
        
        if (sum == root_val)
            return new Pair(true, sum + root -> data);
        
        return new Pair(false, -1);
    }
};
