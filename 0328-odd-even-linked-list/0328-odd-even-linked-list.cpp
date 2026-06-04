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
#define ll ListNode
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
       if(!head || !head->next || !head->next->next) return head;
       ll* odd= head;
       ll* even = head->next;
       ll* evens= head->next;
       while(odd->next && even->next){
        odd->next= even->next;
        even->next=odd->next->next;
        odd= odd->next;
        even = even->next;
       }
       odd->next= evens;
       return head;

    }
};