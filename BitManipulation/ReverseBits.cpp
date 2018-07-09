unsigned int Solution::reverse(unsigned int A) {
    unsigned int reverse_no = 0;
    for(int i = 0; i < 32; i++) {
        if (A & (1 << i)) {
            reverse_no |= 1 << (31 - i);
        }
    }
    return reverse_no;
}