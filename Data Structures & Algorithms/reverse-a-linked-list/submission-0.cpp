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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = head;
        if(!curr or !curr->next) return head;

        curr = curr->next;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        head->next = nullptr;
        return prev;
    }
};
