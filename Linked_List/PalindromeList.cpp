/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    vector<int> temp;
    ListNode *p = A;
    while(p) {
        temp.push_back(p->val);
        p = p->next;
    }
    int n = temp.size();
    for(int i = 0; i< n; i++) {
        if (temp[i] != temp[n-1-i])
            return 0;
    }
    return 1;
}