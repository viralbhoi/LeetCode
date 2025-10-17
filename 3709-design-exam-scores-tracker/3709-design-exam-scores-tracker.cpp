class ExamTracker {
    vector<int> time;
    vector<long long> pre;

public:
    ExamTracker() { pre.push_back(0); }

    void record(int time, int score) {
        this->time.push_back(time);
        pre.push_back(pre.back() + score);
    }

    long long totalScore(int startTime, int endTime) {
        long long score = 0;

        int idx1 = lower_bound(time.begin(),time.end(),startTime) - time.begin();
        int idx2 = upper_bound(time.begin(),time.end(),endTime) - time.begin();

        if (idx1 == time.size() || idx2 == 0) return 0;

        score = pre[idx2] - pre[idx1];

        return score;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */