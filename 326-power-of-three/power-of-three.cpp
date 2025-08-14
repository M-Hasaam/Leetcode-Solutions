class Solution {
public:
    bool isPowerOfThree(int n) {

        if (n < 1)
            return false;

        long long int i = 1;
        while (i < n) {
            i *= 3;
        }
        return i == n;
    }
};