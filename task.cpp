#include "task.hpp"

Task::Task(const std::string& description, Priority priority)
    : description(description), completed(false), priority(priority),
    dueDate(std::chrono::system_clock::now() + std::chrono::hours(24 * 7)) {}

std::string Task::getDescription() const {
    return description;
}

void Task::setDescription(const std::string& description) {
    this->description = description;
}

bool Task::isCompleted() const {
    return completed;
}

void Task::setCompleted(bool completed) {
    this->completed = completed;
}

Priority Task::getPriority() const {
    return priority; }


void Task::setPriority(Priority priority) {
    this->priority = priority;
}

std::chrono::system_clock::time_point Task::getDueDate() const {
    return dueDate;
}

void Task::setDueDate(const std::chrono::system_clock::time_point& dueDate) {
    this->dueDate = dueDate;
}
