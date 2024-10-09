class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int count = 0;
        for(char c : s) {
            if(c == ')') {
                if(open == 0) {
                    count++;
                } else {
                    open--;
                }
            } else {
                open++;
            }
        }
        return count + open;
    }
};