class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> Ugly(n, 0);

        Ugly[0] = 1;

        int i2 = 0, i3 = 0, i5 = 0;
        int next2 = 2, next3 = 3, next5 = 5;

        for (int i = 1; i < n; i++) {

            int minUgly = min(next2, min(next3, next5));
            Ugly[i] = minUgly;

            if (minUgly == next2) {
                i2++;
                next2 = Ugly[i2] * 2;
            }
            if (minUgly == next3) {
                i3++;
                next3 = Ugly[i3] * 3;
            }
            if (minUgly == next5) {
                i5++;
                next5 = Ugly[i5] * 5;
            }
        }

        return Ugly[n - 1];
    }
};