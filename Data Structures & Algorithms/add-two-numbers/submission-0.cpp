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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0, nullptr);
        ListNode* dummy = head;
        while(l1 && l2){
            int val = l1->val + l2->val + carry;
            ListNode* temp = new ListNode(val%10, nullptr);
            dummy->next = temp;
            dummy = dummy->next;
            carry = val/10;

            l1 = l1->next;
            l2 = l2->next;
        } 

        while(l1){
            int val = l1->val + carry;
            ListNode* temp = new ListNode(val%10, nullptr);
            dummy->next = temp;
            dummy = dummy->next;
            carry = val/10;

            l1 = l1->next;
        }

        while(l2){
            int val = l2->val + carry;
            ListNode* temp = new ListNode(val%10, nullptr);
            dummy->next = temp;
            dummy = dummy->next;
            carry = val/10;

            l2 = l2->next;
        }

        if(carry){
            ListNode* temp = new ListNode(carry, nullptr);
            dummy->next = temp;
        }

        return head->next;
    }
};
