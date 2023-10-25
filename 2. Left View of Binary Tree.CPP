

/* A binary tree node

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


vector<int> leftView(Node *root) {
    
    if (root == nullptr)
        return {};
    
    vector<int> output;
    queue<Node*> Queue;
    Queue.push(root);
    
    while (!Queue.empty())
    {
        int N = Queue.size();
        bool flag = true;
        
        for (int i = 0; i < N; i++)
        {
            Node* temp = Queue.front(); Queue.pop();
            
            if (flag)
            {
                int val = temp -> data;
                output.push_back(val);
                flag = false;
            }
            
            if (temp -> left != nullptr)
                Queue.push(temp -> left);
                
            if (temp -> right != nullptr)
                Queue.push(temp -> right);
        }
    }
    
    return output;
}
