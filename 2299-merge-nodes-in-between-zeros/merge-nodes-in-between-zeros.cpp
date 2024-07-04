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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;

        while (curr) {
            ListNode* running = curr;
            int sum = 0;
            while (running->val) {
                sum += running->val;
                running = running->next;
            }
            curr->val = sum;
            curr->next = running->next;
            curr = running->next;
        }

        return head->next;
    }
};