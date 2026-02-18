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
private:
    void reverse(ListNode* head, int times) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (times--) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* left = head;
        ListNode* right = NULL;
        ListNode* prevleft = NULL;
        ListNode* res = NULL;

        while (true) {
            right = left;
            for (int i = 0; i<k-1; i++) {
                if (right == NULL) break;
                right = right->next;
            }

            if (right) {
                ListNode* nextleft = right->next;
                reverse(left, k);

                if (prevleft) {
                    prevleft->next = right;
                }

                prevleft = left;

                if (res == NULL) {
                    res = right;
                }

                left = nextleft;
            } else {
                if (prevleft) {
                    prevleft->next = left;
                }

                if (res == NULL) {
                    res = left;
                }

                break;
            }
        }

        return res;
    }
};