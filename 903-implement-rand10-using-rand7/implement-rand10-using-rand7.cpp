// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {

        int v1 = rand7();
        int v2 = rand7();

        int num = (v1 - 1) * 7 + v2; //  1-49 uniform

        // accepting only 1-40 uniform
        return (num > 40 ? rand10() : num % 10 + 1);
    }
};

class Solution_9ms {
public:
    int rand10() { // 9 ms
        int v1 = rand7();
        int v2 = rand7();

        while (v1 > 5)
            v1 = rand7();
        while (v2 == 7)
            v2 = rand7();

        return (v2 <= 3) ? v1 : v1 + 5;
    }
};