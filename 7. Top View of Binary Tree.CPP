/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Pair {
public:    
    Node* node = nullptr;
    int horizontal_level = 0;
    
    Pair(Node* node, int horizontal_level) {
        
        this -> node = node;
        this -> horizontal_level = horizontal_level;
    }
};

class Solution {
public:
    vector<int> topView(Node *root) {
        
        vector<int> output;
        
        if (root == nullptr)
            return output;
        
        
        vector<int> min_max(2);
        width(root, 0, min_max);
        int l = min_max[1] - min_max[0] + 1;
        
        output.resize(l, 0);
        
        for (int i = 0; i < l; i++)
        {
            queue<Pair*> Queue;
            Queue.push(new Pair(root, abs(min_max[0])));
            
            while (!Queue.empty())
            {
                int size = Queue.size();
                
                while (size-- != 0)
                {
                    Pair* pair = Queue.front(); Queue.pop();
                    
                    Node* node = pair -> node;
                    int horizontal_level = pair -> horizontal_level;
                
                    if (output[horizontal_level] == 0)
                        output[horizontal_level] = node -> data;
                    
                    if (node -> left != nullptr)
                        Queue.push(new Pair(node -> left, horizontal_level - 1));
                    
                    if (node -> right != nullptr)
                        Queue.push(new Pair(node -> right, horizontal_level + 1));
                }
            }
        }
        
        return output;
    }

private:
    void width(Node* node, int level, vector<int>& min_max) {
        
        if (node == nullptr)
            return;
        
        min_max[0] = min(min_max[0], level);
        min_max[1] = max(min_max[1], level);
        
        width(node -> left, level - 1, min_max);
        width(node -> right, level + 1, min_max);
    }
};
