/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    if (!A || !A->next) return NULL;
    ListNode *fast = A, *slow = A;
    bool isCycle = false;

    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            isCycle = true;break;
        }
    }
    
    if (!isCycle) return NULL;
    fast = A;
    while(fast != slow) {
        fast = fast->next;
        slow = slow->next; 
    }
    return slow;
}
