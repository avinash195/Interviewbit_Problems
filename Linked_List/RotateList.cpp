/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int k) {
    if (!A || !A->next || k == 0) return A;
    ListNode *p = A, *kthnode = A;
    int len = 1, count = 1;
    while(p->next) {
        len++;
        p = p->next;
    }
    p->next = A;
    k = len - k%len;                       // give a little thought to this:)
    while(count < k) {
        count++;
        kthnode = kthnode->next;
    }
    A = kthnode->next;
    kthnode->next = NULL;
    
    return A;
}
