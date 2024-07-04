/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* x = (struct ListNode*)malloc(sizeof(struct ListNode));
    x->val = 0;
    x->next = NULL;
    struct ListNode* curr = x;
    int tmp = 0;

    while (head != 0) {
        if (head->val == 0) {
            if (tmp != 0) {
                curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                curr->next->val = tmp;
                curr->next->next = NULL;
                curr = curr->next;
                tmp = 0;
            }
        } else {
            tmp += head->val;
        }
        head = head->next;
    }

    return x->next;
}