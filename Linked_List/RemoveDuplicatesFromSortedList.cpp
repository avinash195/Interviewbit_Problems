/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if (!A || !A->next) {
        return A;
    }
    ListNode *p = A, *nextNode;
    while(p->next != NULL) {
        if (p->val == p->next->val) {
            nextNode = p->next->next;
            free(p->next);
            p->next = nextNode;
        } else {
            p = p->next;
        }
    }
    
    return A;
}