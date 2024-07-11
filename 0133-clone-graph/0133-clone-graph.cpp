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
// 1. hashmaps to store the visited nodes
// 2. if the nodes are visited , return its clone
// 3. create a new node with the same value as the old node
// 4. reccuresively iterate through neighbors to get the clone
class Solution {
public:
    unordered_map<Node* , Node*> visited;
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
    
    
    if (visited.find(node) != visited.end()) {
        return visited[node];
    }
    
    Node* cloneNode = new Node (node->val);
    visited[node] = cloneNode;
    
    for (Node* neighbor : node->neighbors) {
        cloneNode->neighbors.push_back(cloneGraph(neighbor));
    }  
    return cloneNode;
}
    
};