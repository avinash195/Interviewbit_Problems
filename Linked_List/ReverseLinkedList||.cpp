/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    if (m == n || !A || !A->next) return A;
    ListNode *mPrev = NULL,*mthnode = NULL, *prev = NULL, *curr = A;
    int i = 1;
    while(i <= m) {
        mPrev = mthnode;
        mthnode = curr;
        if (curr->next) curr = curr->next;
        i++;
    }
    i = 0;
    curr = mthnode;
    ListNode *nextNode = NULL;
    while(i <= (n-m)) {
        if (curr->next) nextNode = curr->next;
        else nextNode = NULL;
        curr->next = prev;
        prev = curr;
        if (curr) curr = nextNode;
        i++;
    }
    if(mPrev) mPrev->next = prev;
    else A = prev;
    mthnode->next = curr;
    
    return A;
}
