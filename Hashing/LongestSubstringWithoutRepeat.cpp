int Solution::lengthOfLongestSubstring(string A) {
    
    vector<int> visited(256, -1);
    int max_len = 0;
    int start = -1;
    for(int i = 0; i < A.length(); i++) {
        if (visited[A[i]] > start)
            start = visited[A[i]];
        visited[A[i]] = i;
        max_len = max(max_len, i - start);
    }
    return max_len;
}