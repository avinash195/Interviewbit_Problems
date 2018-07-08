int Solution::singleNumber(const vector<int> &A) {
    int n = A.size();
    int sum, x, result = 0;
    for(int i = 0; i < 32; i++) {
        sum = 0;
        x = (1 << i);
        for(int j = 0; j < n; j++) {
            if (A[j] & x) {
                sum++;
            }
        }
        if (sum % 3) {
            result |= x;
        }
    }
    return result;
}