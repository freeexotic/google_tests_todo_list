#pragma once
#include <string>
#include <vector>
#include <memory>
#include <chrono>
#include <stdexcept>
#include <algorithm>

enum class Priority { Low, Medium, High };

class Task {
public:
    Task(const std::string& description, Priority priority = Priority::Medium);

    std::string getDescription() const;

    void setDescription(const std::string& description);

    bool isCompleted() const;

    void setCompleted(bool completed);

    Priority getPriority() const;

    void setPriority(Priority priority);

    std::chrono::system_clock::time_point getDueDate() const;

    void setDueDate(const std::chrono::system_clock::time_point& dueDate);

private:
    std::string description;

    bool completed;

    Priority priority;

    std::chrono::system_clock::time_point dueDate;
};
