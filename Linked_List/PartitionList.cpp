/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    if (!A) return A;
    ListNode *first = new ListNode(0);
    ListNode *second = new ListNode(0);
    ListNode *l1 = first, *l2 = second;
    while(A) {
        if (A->val < B) {
            l1->next = A;
            l1 = l1->next;
        } else {
            l2->next = A;
            l2 = l2->next;
        }
        A = A->next;
    }
    l2->next = NULL;
    l1->next = second->next;
    return first->next;
}
