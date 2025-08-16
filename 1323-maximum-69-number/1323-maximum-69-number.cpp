class Solution {
public:
    int maximum69Number(int num) {
        string no = to_string(num);

        for (int i = 0; i < no.size(); i++) {
            if (no[i] == '6') {
                no[i] = '9';
                break;
            }
        }

        int ans = stoi(no);
        return ans;
    }
};