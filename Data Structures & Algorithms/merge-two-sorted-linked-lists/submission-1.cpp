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

// class Solution {
// public:
//     ListNode* help(ListNode* list1, ListNode* list2){
//         if(list1 == NULL){
//             return list2;
//         }
//         if(list2 == NULL){
//             return list1;
//         }
//         ListNode* head = NULL;
//         if(list1->val <= list2->val){
//             head = help(list1->next,list2);
//             list1->next = head;
//             return list1;
//         }
//         else{
//             head = help(list1,list2->next);
//             list2->next = head;
//             return list2;
//         }
//         return NULL;
//     }
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         return help(list1,list2);
//     }
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the start of the merged list.
        // This avoids edge cases involving the head of the list.
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Traverse both lists while neither is empty
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next; // Move the tail forward
        }

        // At least one list is now empty. Attach the remaining nodes of the other list.
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // dummy.next points to the actual head of the merged list
        return dummy.next; 
    }
};

// iske iterative approach ko yaad rkho , ki kaise dummy node bna, kaise bject bnaya 
// phit uska pointer tail , tail ka next mtlab dummy ke next me hi value jana 
// cocept hai pointers ka hi. 
