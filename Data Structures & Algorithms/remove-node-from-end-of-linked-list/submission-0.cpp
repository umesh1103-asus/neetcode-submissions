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
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp=temp->next;
        }

        temp = head;
        n = len-n;
        if(n==0) return temp->next;
        int k = 0;
        while(temp){
            if(k==n-1){
                temp->next = temp->next->next;
                return head;
            }
            temp=temp->next;
            k++;
        }

        return head;
    }
};
