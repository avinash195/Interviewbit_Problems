int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    int i = 0;
    int value = 0;
    int ans = INT_MAX;
    while(i < A.size()-1) {
        value = A[i] ^ A[i+1];
        ans = min(ans, value);
        i++;
    }
    return ans;
}