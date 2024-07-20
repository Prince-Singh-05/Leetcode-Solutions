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

    // T.C => O(2N) && S.C => O(N) + O(N)

    // Node* copyRandomList(Node* head) {
    //     unordered_map<Node*, Node*> nodes;
    //     Node* h = head;
        
    //     while (h){
    //         nodes[h] = new Node(h->val);
    //         h = h->next;
    //     }
    //     h = head;
    //     while (h){
    //         Node* newNode = nodes[h];
    //         newNode->next = nodes[h->next];
    //         newNode->random = nodes[h->random];
    //         h = h->next;
    //     }
    //     return nodes[head];
    // }

    Node* copyRandomList(Node* head) {

        Node* temp = head;
        Node* dNode = new Node(-1);
        Node* res = dNode;

        // cout << (temp->random != NULL) ? temp->random : NULL;

        while(temp) {
            Node* new_node = new Node(temp->val);
            new_node->next = temp->next;
            temp->next = new_node;
            temp = temp->next->next;
        }

        temp = head;

        while(temp) {
            if(temp->random != NULL) {
                temp->next->random = temp->random->next;
            }else {
                temp->next->random = NULL;
            }            
            temp = temp->next->next;
        }

        temp = head;
        while(temp) {
            res->next = temp->next;
            res = res->next;
            temp->next = res->next;
            temp = temp->next;
        }

        return dNode->next;
    }
};