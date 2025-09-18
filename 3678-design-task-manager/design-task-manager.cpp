class TaskManager {
public:
priority_queue<pair<int, int>> tasks;
unordered_map<int, int> taskPriority;
unordered_map<int, int> taskOwner;
    // Task Manager, listof "user-task-priority"
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }

    // Adding the new task into task Manager
void add(int userId, int taskId, int priority) {
    tasks.push({priority, taskId});
    taskPriority[taskId] = priority;
    taskOwner[taskId] = userId;
}
    
void edit(int taskId, int newPriority) {
    tasks.push({newPriority, taskId});
    taskPriority[taskId] = newPriority;
} 
    
    // Remove the TaskId from the tasks,
void rmv(int taskId) {
    taskPriority[taskId] = -1;
}
    // 
int execTop() {
    while (!tasks.empty()) {
      const auto task = tasks.top();
      tasks.pop();
      if (task.first == taskPriority[task.second]) {
        taskPriority[task.second] = -1;
        return taskOwner[task.second];
      }
    }
    return -1;
}
};

