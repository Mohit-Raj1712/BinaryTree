/* A binary tree Node

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
    vector<int> levelOrder(Node* root) {
        
        vector<int> output;
        
        if (root == nullptr)
            return output;
        
        queue<Node*> Queue;
        Queue.push(root);
        
        while (!Queue.empty())
        {
            int n = Queue.size();
            for (int i = 0; i < n; i++)
            {
                Node* node = Queue.front(); Queue.pop();
                
                if (node -> left != nullptr)
                    Queue.push(node -> left);
                
                output.push_back(node -> data);
                
                if (node -> right != nullptr)
                    Queue.push(node -> right);
            }
        }
        
        return output;
    }
};