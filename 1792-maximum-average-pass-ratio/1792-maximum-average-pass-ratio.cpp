class Solution {
    struct comp{
        bool operator()(const vector<int> &a, const vector<int> &b){
            return gain(a) < gain(b);
        }

        double gain(const vector<int> &a){
            return double(a[0]+1) / (a[1]+1) - double(a[0])/a[1];
        }
    };
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<int> , vector<vector<int>>, comp> pq;

        for(auto it : classes){
            pq.push(it);
        }

        while(extraStudents){
            vector<int> temp = pq.top();
            pq.pop();

            temp[0]++;
            temp[1]++;

            pq.push(temp);

            extraStudents--;
        }

        double sum = 0.0;

        while(!pq.empty()){
            sum += (double)pq.top()[0] / pq.top()[1];
            pq.pop();
        }

        return sum / classes.size();
    }
};