class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);

        set<char> st;

        for (auto c : brokenLetters) {
            st.insert(c);
        }

        string word;
        int wordCnt = 0;
        while (ss >> word) {
            bool found = false;
            for (auto c : word) {
                if (st.count(c)) {
                    found = true;
                }
            }

            if (!found) {
                wordCnt++;
            }
        }

        return wordCnt;
    }
};