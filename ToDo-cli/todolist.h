#pragma once
#include <iostream>
#include <string>

struct Todo {
    std::string todo;
    Todo* next = nullptr;
};

class TodoList {
private:
    Todo* head, * list;

    Todo* get_from_index(int index) { // index starts from 0
        Todo* temp = head;
        for (int i = 0; i < index && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr)
            return nullptr;
        else
            return temp;
    }
public:
    TodoList() {
        head = nullptr;
        list = nullptr;
    }

    void add_todo(std::string task) {
        Todo* temp = new Todo;
        temp->todo = task;
        temp->next = nullptr;
        if (head == nullptr)
            head = temp;
        else {
            list = head;
            while (list->next != nullptr)
                list = list->next;
            list->next = temp;
        }
    }

    void list_todo() {
        list = head;
        if (head == nullptr)
            std::cout << "There are no todos" << std::endl;
        else {
            int i = 1;
            while (list != nullptr) {
                std::cout << i << ". " << list->todo << std::endl;
                list = list->next;
                i++;
            }
        }
    }

    void delete_todo() {
        list = head;
        if (head == nullptr)
            std::cout << "There are no todos" << std::endl;
        else {
            std::cout << "Enter the todo number you want to delete ";
            unsigned n;
            std::cin >> n;
            if (n == 1) { // Deleting head
                head = head->next;
                delete list;
                list = nullptr;
            }
            else {
                Todo* temp = list;
                for (unsigned i = 1; i < n; i++) {
                    temp = list;
                    list = list->next;
                }
                temp->next = list->next;
                delete list;
                list = nullptr;
            }
        }
    }

    void free_todo() {
        while (head != nullptr) {
            list = head;
            head = head->next;
            delete list;
        }
        list = nullptr;
    }
};
