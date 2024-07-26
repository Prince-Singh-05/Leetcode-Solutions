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
    ListNode* swapPairs(ListNode* head) {

        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* new_head = head->next;
        ListNode* prev = NULL;
        ListNode* first = head;
        ListNode* second = NULL;
        ListNode* next = NULL;

        while(first != NULL && first->next != NULL) {
            second = first->next;
            next = second->next;
            first->next = next;
            second->next = first;
            
            if(prev != NULL) {
                prev->next = second;
                prev = first;
            } else {
                prev = first;
            }

            first = next;
        }

        return new_head;
        
    }
};