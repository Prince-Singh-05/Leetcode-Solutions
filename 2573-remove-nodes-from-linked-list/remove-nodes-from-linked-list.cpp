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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;

        while (curr != NULL) {
            st.push(curr);
            curr = curr-> next;
        }

        curr = NULL;
        ListNode* prev = NULL;

        while (!st.empty()) {
            if (curr == NULL) {
                curr = st.top();
                st.pop();
                continue;
            }

            if (curr->val <= st.top()->val) {
                prev = curr;
                curr = st.top();
                curr->next = prev;
            }

            st.pop();
        }
        
        return curr;
    }
};