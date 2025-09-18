class TaskManager {
    priority_queue<pair<int, int>> pq;  // {priority, taskId}
    unordered_map<int, int> taskPriority;
    unordered_map<int, int> taskUser;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        taskPriority[taskId] = priority;
        taskUser[taskId] = userId;
        pq.push({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        taskPriority[taskId] = newPriority;
        pq.push({newPriority, taskId});
    }

    void rmv(int taskId) {
        taskPriority.erase(taskId);
        taskUser.erase(taskId);
    }

    int execTop() {
        while (!pq.empty() && 
              (!taskPriority.count(pq.top().second) || 
               taskPriority[pq.top().second] != pq.top().first)) {
            pq.pop();
        }
        if (pq.empty()) return -1;

        int taskId = pq.top().second;
        pq.pop();
        return taskUser[taskId];
    }
};
