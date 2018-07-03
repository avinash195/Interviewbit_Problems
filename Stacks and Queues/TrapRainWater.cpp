int Solution::trap(const vector<int> &A) {
    int n = A.size();
    vector<int> lMax(n);
    vector<int> rMax(n);
    lMax[0] = A[0];
    rMax[n-1] = A[n-1];
    for(int i = 1; i < n; i++) {
        lMax[i] = max(A[i], lMax[i-1]);
    }
    for(int i = n-2; i >= 0; i--) {
        rMax[i] = max(A[i], rMax[i+1]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += min(lMax[i], rMax[i]) - A[i];
    }
    return ans;
}