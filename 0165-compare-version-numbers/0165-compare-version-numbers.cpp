class Solution {
public:
    int compareVersion(string version1, string version2) {
        char delim = '.';

        vector<int> v1, v2;
        string temp;

        stringstream s1(version1);

        while (getline(s1, temp, delim)) {
            int ans = 0;
            for (int i = 0; i < temp.size(); i++) {
                ans = ans * 10 + (temp[i] - '0');
            }
            v1.push_back(ans);
        }

        stringstream s2(version2);

        while (getline(s2, temp, delim)) {
            int ans = 0;
            for (int i = 0; i < temp.size(); i++) {
                ans = ans * 10 + (temp[i] - '0');
            }
            v2.push_back(ans);
        }

        int n = max(v1.size(), v2.size());
        while (v1.size() < n)
            v1.push_back(0);
        while (v2.size() < n)
            v2.push_back(0);

        for (int i = 0; i < n; i++) {
            if (v1[i] > v2[i])
                return 1;
            if (v1[i] < v2[i])
                return -1;
        }
        return 0;
    }
};