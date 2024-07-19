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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* head = list1;

        if(l1->val > l2->val) {
            head = list2;
        }

        while(l1 != NULL && l2 != NULL) {

            ListNode* p1 = l1->next;
            ListNode* p2 = l2->next;

            if(l1->val <= l2->val) {
                if(p1 != NULL && p1->val <= l2->val) {
                    l1 = p1;
                    continue;
                }
                l1->next = l2;
                l1 = p1;
            } else {
                if(p2 != NULL && l1->val > p2->val) {
                    l2 = p2;
                    continue;
                }
                l2->next = l1;
                l2 = p2;
            }
        }

        return head;
        
    }
};