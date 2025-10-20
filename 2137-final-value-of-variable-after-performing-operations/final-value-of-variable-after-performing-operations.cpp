class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;

        for(string op:operations){
            if(op[0]=='-'||op[2]=='-')x--;
            if(op[0]=='+'||op[2]=='+')x++;
        }

        return x;
    }
};