#include <bits/stdc++.h>
using namespace std;

class TaskManager {
    struct Node {
        int priority;
        int taskId;
        int userId;
        bool operator<(const Node &other) const {
            if (priority == other.priority) {
                if (taskId == other.taskId) {
                    return userId > other.userId; // smaller userId first
                }
                return taskId < other.taskId; // larger taskId first
            }
            return priority < other.priority; // max-heap by priority
        }
    };

    priority_queue<Node> pq;  
    unordered_map<int, pair<int,int>> taskMap; 
    // taskId -> {priority, userId}

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            pq.push({priority, taskId, userId});
            taskMap[taskId] = {priority, userId};
        }
    }

    void add(int userId, int taskId, int priority) {
        // overwrite with latest version
        taskMap[taskId] = {priority, userId};
        pq.push({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        if (!taskMap.count(taskId)) return;
        auto [_, userId] = taskMap[taskId];
        taskMap[taskId] = {newPriority, userId};
        pq.push({newPriority, taskId, userId}); 
    }
    
    void rmv(int taskId) {
        taskMap.erase(taskId);
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto top = pq.top();
            if (taskMap.count(top.taskId)) {
                auto [currPriority, currUser] = taskMap[top.taskId];
                if (currPriority == top.priority && currUser == top.userId) {
                    taskMap.erase(top.taskId); 
                    pq.pop();
                    return top.userId;
                }
            }
            pq.pop(); // stale entry
        }
        return -1; 
    }
};
