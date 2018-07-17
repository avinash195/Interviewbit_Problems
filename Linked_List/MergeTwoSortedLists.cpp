/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if (!A) return B;
    if (!B) return A;
    ListNode *final = new ListNode(0);
    ListNode *p = final;
    while(A && B) {
        if (A->val <= B->val) {
            p->next = A;
            A = A->next;
            p = p->next;
        } else {
            p->next = B;
            B = B->next;
            p = p->next;
        }
    }
    if (!A) p->next = B;
    if (!B) p->next = A;
    return final->next;
}
