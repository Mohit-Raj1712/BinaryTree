// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/

class Solution {
public:
    vector<int> postOrder(Node* root) {
        
        vector<int> output;
        stack<Node*> Stack;
        
        Node* node = root;
        
        while(true)
        {
            while (node != nullptr)
            {
                Stack.push(node);
                Stack.push(node);
                node = node -> left;
            }
            
            if (Stack.empty())
                break;
                
            node = Stack.top(); Stack.pop();
            
            if (!Stack.empty() && node == Stack.top())
            {
                node = node -> right;
            }
            else {
                
                output.push_back(node -> data);
                node = nullptr;
            }
            
        }
        
        return output;
    }
};