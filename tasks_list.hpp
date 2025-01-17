#pragma once

#include "task.hpp"

#include <string>
#include <vector>
#include <memory>
#include <chrono>
#include <stdexcept>
#include <algorithm>


class TodoList {
public:
    void addTask(const std::string& description, Priority priority = Priority::Medium);

    void completeTask(size_t index);

    void removeTask(size_t index);

    void updateTask(size_t index, const std::string& description, Priority priority);

    void setDueDate(size_t index, const std::chrono::system_clock::time_point& dueDate);

    std::vector<std::shared_ptr<Task>> getTasks() const;

    std::vector<std::shared_ptr<Task>> getTasksSortedByPriority() const;

    std::vector<std::shared_ptr<Task>> getTasksSortedByDueDate() const;

    std::vector<std::shared_ptr<Task>> getCompletedTasks() const;

    std::vector<std::shared_ptr<Task>> getUncompletedTasks() const;

    size_t getTaskCount() const;

private:
    std::vector<std::shared_ptr<Task>> tasks;
};
