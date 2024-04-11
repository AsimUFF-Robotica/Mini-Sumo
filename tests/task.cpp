#include "constants.h"
#include "task.h"
#include "Arduino.h"

void executeSequentialTasks(Task tasks[], int& tasksSize) {
  static int currentTaskIndex = 0;
  static unsigned long taskStartTime;
  
  if(currentTaskIndex < tasksSize) {
    if(!tasks[currentTaskIndex].isActive) {
      tasks[currentTaskIndex].isActive = true;
      taskStartTime = millis();
      tasks[currentTaskIndex].execute();
    } else if (millis() - taskStartTime >= tasks[currentTaskIndex].duration) {
      tasks[currentTaskIndex].isActive = false;
      currentTaskIndex++;
    }
  }
}