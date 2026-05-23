/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void dfs(Node* node, Node* copyNode, Node* par, vector<bool>& visited, map<int, Node*>& nodeMap){
        //copyNode->val = node->val;
        visited[node->val] = true;
        for(auto neighbor : node->neighbors){
            if(!visited[neighbor->val]) {
                // create a new node
                Node* next = new Node();
                next->val = neighbor->val;
                // add neighbors
                next->neighbors.push_back(copyNode);
                copyNode->neighbors.push_back(next);
                // add new node in mapset
                nodeMap[next->val] = next;

                dfs(neighbor, next, node, visited, nodeMap);
            } else {
                if(neighbor->val != par->val){
                    Node* neighborCopyNode = nodeMap[neighbor->val];
                    //neighborCopyNode->neighbors.push_back(copyNode);
                    copyNode->neighbors.push_back(neighborCopyNode);
                }
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        vector<bool> visited(101, false);
        map<int, Node*> nodeMap;

        Node* copyNode = new Node();
        copyNode->val = node->val;
        nodeMap[copyNode->val] = copyNode;

        dfs(node, copyNode, node, visited, nodeMap);

        return copyNode;
    }
};
