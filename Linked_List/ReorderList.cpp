/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* findMiddle(ListNode *head) {
    ListNode *fast = head, *slow = head;  
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverse(ListNode* mid)
{
    if(!mid || !mid->next)
        return mid;
    ListNode *curr, *next, *prev;
    prev = mid; //didn't understand this part; should be NULL but that doesn't works.
    curr = mid->next;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    mid->next = curr;
    return prev;
}

ListNode* merge(ListNode* l1, ListNode* l2)
{
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    ListNode* head = l1;
    l1 = l1->next;
    bool alteringListFlag = true;
    ListNode* p = head;
    while(l1 && l2)
    {
        if(!alteringListFlag)
        {
            p->next = l1;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
        }
        alteringListFlag = !alteringListFlag;
        p = p->next;
    }
    
    if(l1)
        p->next = l1;
    else
        p->next = l2;
    return head;
}

ListNode* Solution::reorderList(ListNode* A) {
    if(!A || !A->next || !A->next->next) return A;
    ListNode *midPrev = findMiddle(A);
    ListNode *second = reverse(midPrev->next);
    midPrev->next = NULL;
    return merge(A, second);
}
