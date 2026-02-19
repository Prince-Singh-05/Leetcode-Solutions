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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;

        int count = 0;
        ListNode* curr = head;

        while (curr->next != NULL) {
            curr = curr->next;
            count++;
        }

        curr->next = head;

        int n = count+1;
        int times = n+1 - k%n;

        while (--times) {
            curr = curr->next;
        }

        ListNode* newhead = curr->next;
        curr->next = NULL;

        return newhead;
    }
};