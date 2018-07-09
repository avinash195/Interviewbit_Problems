int Solution::divide(int A, int B) {
    if (!B || (A == INT_MIN && B == -1)) {
        return INT_MAX;
    }
    int sign = ((A^B) < 0) ? -1: 1;
    long long dvd = labs(A);
    long long dvs = labs(B);
    int res = 0;
    while(dvd >= dvs) {
        long long temp = dvs, multiple = 1;
        while(dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        res += multiple;
    }
    return (sign == 1) ? res: -res;
}