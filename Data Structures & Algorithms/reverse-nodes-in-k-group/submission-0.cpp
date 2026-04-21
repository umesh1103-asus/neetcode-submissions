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
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        int count = 1;
        ListNode* temp = head;
        while(count<k && temp){
            temp = temp->next;
            count++;
        }

        if(count<k || !temp) return head;
        ListNode* nxt = temp->next;
        temp->next = nullptr;
        ListNode* newHead = reverseList(head);
        ListNode* nextNode = reverseKGroup(nxt, k);
        head->next = nextNode;
        return newHead;
    }
};
