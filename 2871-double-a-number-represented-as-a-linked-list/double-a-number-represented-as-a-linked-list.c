/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* doubleIt(struct ListNode* head) {
    if (head->val > 4) {
        struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
        newHead->val = 0;
        newHead->next = head;
        head = newHead;
    }
    
    struct ListNode* tmp = head;
    while (tmp != NULL) {
        tmp->val = (tmp->val * 2) % 10;
        if (tmp->next != NULL && tmp->next->val > 4) {
            tmp->val++;
        }
        
        tmp = tmp->next;
    }
    
    return head;
}

