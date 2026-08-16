/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> check;
        return find(head,check);
    }
private:
    ListNode* find(ListNode* node,unordered_set<ListNode*>& check){
        if(!node) return nullptr;
        if(check.find(node)!=check.end())return node;
        check.insert(node);
        return find(node->next,check);
    }
};