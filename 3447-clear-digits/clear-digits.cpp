class Solution {
public:
    string clearDigits(string s) {
        //Two pointer approach
        int wr_index = 0; 
        int rd_index = 0; 
        while (rd_index < s.length()) {
            if (isdigit(s[rd_index])) {
                ++rd_index;
                if (wr_index > 0) --wr_index;
            } 
            else s[wr_index++] = s[rd_index++];
        }
        s.resize(wr_index);
        return s;
    }
};