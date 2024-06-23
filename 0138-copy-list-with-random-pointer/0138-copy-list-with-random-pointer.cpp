/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      // two passes
        // 1 would be responsible for the copying of nodes (using maps)
        // 2 would be responsible for the assigning of pointers (next & random)
        
        //1st Pass
        unordered_map<Node* , Node*> oldToNew;
        if(!head) return NULL;
        Node* current = head;
        while(current) {
            oldToNew[current] = new Node (current->val);
            current = current->next;
        }
        
        //2nd Pass
        
        current = head;
        while (current) {
            if (current->next) {
                oldToNew[current]->next = oldToNew [current->next];
            }
            if(current->random) {
                oldToNew[current]->random = oldToNew [current->random];
            }
            current = current->next;
        }
        return oldToNew[head];
    }
};