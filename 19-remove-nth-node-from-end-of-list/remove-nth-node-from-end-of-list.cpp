/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head->next == NULL) return NULL;

        ListNode* temp = head;
        int count = 0;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        if(n == count) {
            return head->next;
        }

        ListNode* left = head;
        ListNode* right = head;

        for(int i = 1; i < count-n; i++) {
            left = left->next;
        }

        for(int i = 1; i < count-n+1; i++) {
            right = right->next;
        }

        left->next = right->next;

        return head;
        
    }
};