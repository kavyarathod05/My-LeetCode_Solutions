class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        int n = 1;
        ListNode* temp = head;
        while(temp->next){
            temp = temp->next;
            n++;
        }

        k = k % n;
        if(k == 0) return head;

        // make circular
        temp->next = head;

        ListNode* first = head;
        for(int i = 1; i < (n - k); i++){
            first = first->next;
        }

        // first = newTail
        ListNode* newHead = first->next;

        // break
        first->next = nullptr;

        return newHead;
    }
};