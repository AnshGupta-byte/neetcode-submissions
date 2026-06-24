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
    void reorderList(ListNode* head) {
        // mid
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;

        ListNode* head2 = mid->next;
        mid->next = NULL;

        // reverse
        ListNode* prev = NULL;
        ListNode* curr = head2;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* temp = head;
        while (temp && prev) {
            ListNode* temp1 = temp->next;
            ListNode* temp2 = prev->next;

            temp->next = prev;
            if (temp1 == NULL) break;
            prev->next = temp1;
            temp = temp1;
            prev = temp2;
        }
        return;
    }
};
