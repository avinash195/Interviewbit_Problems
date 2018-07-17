/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int n) {
    if (n == 0) return A;
    int size = 0;
    ListNode *p = A;
    while(p) {
        size++;
        p = p->next;
    }
    int front = size-n;
    if (front <= 0) return A->next;      // < case is from test case expected output
    
    ListNode *temp = A;
    int count = 1;
    while(count < front) {
        count++;
        temp = temp->next;
    }
    
    ListNode *nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
    
    return A;
}
