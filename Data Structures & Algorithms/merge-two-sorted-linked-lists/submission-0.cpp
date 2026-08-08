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
    ListNode* help(ListNode* list1, ListNode* list2){
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        ListNode* head = NULL;
        if(list1->val <= list2->val){
            head = help(list1->next,list2);
            list1->next = head;
            return list1;
        }
        else{
            head = help(list1,list2->next);
            list2->next = head;
            return list2;
        }
        return NULL;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return help(list1,list2);
    }
};
