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
        if (head == NULL) return nullptr;
        ListNode* temp = head;
        int length = 1;
        while (temp && temp->next) {
            temp = temp->next;
            length++;
        }
        int i = 0;
        int k = length - n;
        if (k == 0) {
            head = head->next;
            return head;
        }
        temp = head;
        while (i < k - 1) {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
        return head;
    }
};
