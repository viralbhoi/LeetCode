class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        sort(events.begin(), events.end(),
             [&](const vector<string>& first, const vector<string>& second) {
                 int t1 = stoi(first[1]);
                 int t2 = stoi(second[1]);
                 if (t1 != t2) {
                     return t1 < t2;
                 }
                 if (second[0] == "OFFLINE") {
                     return false;
                 }
                 return true;
             });
        vector<int> count(n);
        vector<int> next_wake(n);
        int allCounter = 0;

        for (auto& event : events) {
            int time = stoi(event[1]);

            if (event[0] == "MESSAGE") {
                if (event[2] == "ALL") {
                    allCounter++;
                } else if (event[2] == "HERE") {
                    for (int i = 0; i < n; i++) {
                        if (next_wake[i] <= time) {
                            count[i]++;
                        }
                    }
                } else {
                    istringstream ss(event[2]);
                    string word;

                    while (ss >> word) {

                        int num = stoi(word.substr(2, word.size() - 2));

                        count[num]++;
                    }
                }
            } else {
                int idx = stoi(event[2]);
                next_wake[idx] = time + 60;
            }
        }

        for (int i = 0; i < n; i++) {
            count[i] += allCounter;
        }

        return count;
    }
};