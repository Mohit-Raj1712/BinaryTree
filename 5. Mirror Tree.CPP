

/* A binary tree node has data, pointer to left child
   and a pointer to right child 
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
public:
    void mirror(Node* root) {
        
        if (root == nullptr)
            return;
        
        mirror(root -> left);
        mirror(root -> right);
        
        Node* left_subtree = root -> left;
        Node* right_subtree = root -> right;
        
        root -> right = left_subtree;
        root -> left  = right_subtree;
    }
};