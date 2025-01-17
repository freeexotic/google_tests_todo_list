#include "tasks_list.hpp"


void TodoList::addTask(const std::string& description, Priority priority) {
    tasks.push_back(std::make_shared<Task>(description, priority));
}

void TodoList::completeTask(size_t index) {
    if (index >= tasks.size()) {
        throw std::out_of_range("Invalid task index");
    }
    tasks[index]->setCompleted(true);
}

void TodoList::removeTask(size_t index) {
    if (index >= tasks.size()) {
        throw std::out_of_range("Invalid task index");
    }
    tasks.erase(tasks.begin() + index);
}

void TodoList::updateTask(size_t index, const std::string& description, Priority priority) {
    if (index >= tasks.size()) {
        throw std::out_of_range("Invalid task index");
    }
    tasks[index]->setDescription(description);
    tasks[index]->setPriority(priority);
}

void TodoList::setDueDate(size_t index, const std::chrono::system_clock::time_point& dueDate) {
    if (index >= tasks.size()) {
        throw std::out_of_range("Invalid task index");
    }
    tasks[index]->setDueDate(dueDate);
}

std::vector<std::shared_ptr<Task>> TodoList::getTasks() const {
    return tasks;
}

std::vector<std::shared_ptr<Task>> TodoList::getTasksSortedByPriority() const {
    auto sortedTasks = tasks;
    std::sort(sortedTasks.begin(), sortedTasks.end(),
              [](const auto& a, const auto& b) { return a->getPriority() > b->getPriority(); });
    return sortedTasks;
}

std::vector<std::shared_ptr<Task>> TodoList::getTasksSortedByDueDate() const {
    auto sortedTasks = tasks;
    std::sort(sortedTasks.begin(), sortedTasks.end(),
              [](const auto& a, const auto& b) { return a->getDueDate() < b->getDueDate(); });
    return sortedTasks;
}

std::vector<std::shared_ptr<Task>> TodoList::getCompletedTasks() const {
    std::vector<std::shared_ptr<Task>> completedTasks;
    std::copy_if(tasks.begin(), tasks.end(), std::back_inserter(completedTasks),
                 [](const auto& task) { return task->isCompleted(); });
    return completedTasks;
}

std::vector<std::shared_ptr<Task>> TodoList::getUncompletedTasks() const {
    std::vector<std::shared_ptr<Task>> uncompletedTasks;
    std::copy_if(tasks.begin(), tasks.end(), std::back_inserter(uncompletedTasks),
                 [](const auto& task) { return !task->isCompleted(); });
    return uncompletedTasks;
}

size_t TodoList::getTaskCount() const { return tasks.size(); }
