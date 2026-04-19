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
        ListNode* curr = head;
        rec(curr, curr);
        return;
    }

    pair<ListNode*, ListNode*> rec(ListNode* curr, ListNode* currLast){
        if(!currLast->next) {
            return {curr, currLast};
        }

        pair<ListNode*, ListNode*> res = rec(curr, currLast->next);
        curr = res.first;
        ListNode* last = res.second;

        if(curr==nullptr || last==nullptr) return {nullptr, nullptr};

        ListNode* next = curr->next;

        if(curr==last){
            curr->next = nullptr;
            return {nullptr, nullptr};
        }
        curr->next = last;

        if(last==next){
            last->next = nullptr;
            return {nullptr, nullptr};
        }
        last->next = next;

        return {next, currLast};
    }
};
