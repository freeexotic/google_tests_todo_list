#include <gtest/gtest.h>
#include "task.hpp"
#include "tasks_list.hpp"
#include <chrono>

class TodoListTest : public ::testing::Test {
protected:
    TodoList todoList;
};

TEST_F(TodoListTest, AddTask) {
    todoList.addTask("Купить продукты", Priority::High);
    EXPECT_EQ(todoList.getTaskCount(), 1);
    auto tasks = todoList.getTasks();
    EXPECT_EQ(tasks[0]->getDescription(), "Купить продукты");
    EXPECT_EQ(tasks[0]->getPriority(), Priority::High);
    EXPECT_FALSE(tasks[0]->isCompleted());
}

TEST_F(TodoListTest, CompleteTask) {
    todoList.addTask("Сделать ужин");
    todoList.completeTask(0);
    EXPECT_TRUE(todoList.getTasks()[0]->isCompleted());
}

TEST_F(TodoListTest, RemoveTask) {
    todoList.addTask("Убрать дом");
    todoList.addTask("Выпить таблетки");
    todoList.removeTask(0);
    EXPECT_EQ(todoList.getTaskCount(), 1);
    EXPECT_EQ(todoList.getTasks()[0]->getDescription(), "Выпить таблетки");
}

TEST_F(TodoListTest, UpdateTask) {
    todoList.addTask("Старая задача", Priority::Low);
    todoList.updateTask(0, "Новая задача", Priority::High);
    auto task = todoList.getTasks()[0];
    EXPECT_EQ(task->getDescription(), "Новая задача");
    EXPECT_EQ(task->getPriority(), Priority::High);
}

TEST_F(TodoListTest, SetDueDate) {
    todoList.addTask("Задача с ограничением по времени");
    auto futureDate = std::chrono::system_clock::now() + std::chrono::hours(48);
    todoList.setDueDate(0, futureDate);
    EXPECT_EQ(todoList.getTasks()[0]->getDueDate(), futureDate);
}

TEST_F(TodoListTest, GetTasksSortedByPriority) {
    todoList.addTask("Задача с низким приоритетом", Priority::Low);
    todoList.addTask("Задача с высоким приоритетом", Priority::High);
    todoList.addTask("Задача с средним приоритетом", Priority::Medium);

    auto sortedTasks = todoList.getTasksSortedByPriority();
    EXPECT_EQ(sortedTasks[0]->getDescription(), "Задача с высоким приоритетом");
    EXPECT_EQ(sortedTasks[1]->getDescription(), "Задача с средним приоритетом");
    EXPECT_EQ(sortedTasks[2]->getDescription(), "Задача с низким приоритетом");
}

TEST_F(TodoListTest, GetTasksSortedByDueDate) {
    auto now = std::chrono::system_clock::now();
    todoList.addTask("Задача 1");
    todoList.addTask("Задача 2");
    todoList.addTask("Задача 3");

    todoList.setDueDate(0, now + std::chrono::hours(72));
    todoList.setDueDate(1, now + std::chrono::hours(24));
    todoList.setDueDate(2, now + std::chrono::hours(48));

    auto sortedTasks = todoList.getTasksSortedByDueDate();
    EXPECT_EQ(sortedTasks[0]->getDescription(), "Задача 2");
    EXPECT_EQ(sortedTasks[1]->getDescription(), "Задача 3");
    EXPECT_EQ(sortedTasks[2]->getDescription(), "Задача 1");
}

TEST_F(TodoListTest, GetCompletedAndUncompletedTasks) {
    todoList.addTask("Задача 1");
    todoList.addTask("Задача 2");
    todoList.addTask("Задача 3");

    todoList.completeTask(1);

    auto completedTasks = todoList.getCompletedTasks();
    auto uncompletedTasks = todoList.getUncompletedTasks();

    EXPECT_EQ(completedTasks.size(), 1);
    EXPECT_EQ(completedTasks[0]->getDescription(), "Задача 2");

    EXPECT_EQ(uncompletedTasks.size(), 2);
    EXPECT_EQ(uncompletedTasks[0]->getDescription(), "Задача 1");
    EXPECT_EQ(uncompletedTasks[1]->getDescription(), "Задача 3");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
