//User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/

class Solution {
public:
    vector<int> inOrder(Node* root) {
        
        vector<int> output;
        stack<Node*> Stack;
        
        Node* node = root;
        
        while (true) {
            
            while (node != nullptr)
            {
                Stack.push(node);
                node = node -> left;
            }
            
            if (Stack.empty())
                break;
                
            node = Stack.top(); Stack.pop();
            output.push_back(node -> data);
            node = node -> right;
        }
        
        return output;
    }
};