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
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == NULL || head->next == NULL) return head;

        ListNode* prev = head;
        ListNode* unique = head;
        ListNode* curr = prev->next;

        while (curr != NULL) {
            if (curr->val != prev->val) {
                unique->next = curr;
                unique = unique->next;
                // prev->next = NULL;
            }
            prev = prev->next;
            curr = curr->next;
        }

        unique->next = NULL;

        return head;
    }
};