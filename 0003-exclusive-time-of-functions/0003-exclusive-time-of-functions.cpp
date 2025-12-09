class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);

        stack<int> st;
        int last = 0;

        for(auto &log : logs){
            int p1 = log.find(':');
            int p2 = log.find(':', p1+1);

            int id = stoi(log.substr(0, p1));
            string type = log.substr(p1+1, p2-p1-1);
            int time = stoi(log.substr(p2+1));

            if(type == "start"){
                if(!st.empty()){
                    ans[st.top()] += time - last;
                }

                st.push(id);
                last = time;
            }else{
                ans[st.top()] += time - last + 1;
                st.pop();
                last = time + 1;
            }
        }
        return ans;
    }
};