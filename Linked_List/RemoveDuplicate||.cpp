/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if (!A || !A->next) return A;
    
    ListNode *temp = new ListNode(0);
    temp->next = A;
    ListNode *p = temp;
    while(A) {
        while (A->next && A->val == A->next->val)
            A = A->next;
        
        if (p->next == A)
            p = p->next;
        else 
            p->next = A->next;
            
        A = A->next;
    }
    p = p->next;
    return temp->next;
}