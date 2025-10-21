class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int r = n - 1;
        int l = 0;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (citations[mid] >= n - mid) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return n - l;
    }
};