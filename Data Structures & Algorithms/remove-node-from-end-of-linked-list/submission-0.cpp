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
        int N = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            N++;
            cur = cur->next;
        }

        int removeIndex = N - n;
        if (removeIndex == 0) {
            return head->next;
        }

        cur = head;
        for (int i = 1; i <= N - 1; i++) {
            if ((i) == removeIndex) {
                cur->next = cur->next->next;
                break;
            }
            cur = cur->next;
        }
        return head;
    }
};
