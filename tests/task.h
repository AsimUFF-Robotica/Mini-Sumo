#ifndef TASK_H
#define TASK_H

struct Task {
  unsigned long duration;
  void (*execute)();
  bool isActive;
};

void executeSequentialTasks(Task tasks[], int& tasksSize);

#endif