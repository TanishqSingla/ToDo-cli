#pragma once
#include <iostream>
#include <string>
#include <fstream>

struct Todo {
    std::string todo;
    Todo* next = nullptr;
};

class TodoList {
private:
    Todo* head;

    Todo* get_from_index(int index) { // index starts from 0
        Todo* temp = head;
        for (int i = 0; i < index && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr)
            return nullptr;
        else
            return temp;
    }

    std::string createObject(Todo* listItem) {
        std::string object = "{\"task\": \"" + listItem->todo + "\"},";
        return object;
    }

public:
    unsigned int length = 0;

    TodoList() {
        head = nullptr;
    }

    void add_todo(std::string task) {
        Todo* list = head;
        Todo* temp = new Todo;
        temp->todo = task;
        temp->next = nullptr;
        if (head == nullptr) {
            head = temp;
            ++length;
        }
        else {
            list = head;
            while (list->next != nullptr) {
                list = list->next;
                ++length;
            }
            list->next = temp;
        }
    }

    void list_todo() {
        Todo* list = head;
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
        Todo* list = head;
        if (head == nullptr)
            std::cout << "There are no todos to delete" << std::endl;
        else {
            std::cout << "Enter the todo number you want to delete ";
            unsigned n;
            std::cin >> n;
            if (n == 1) { // Deleting head
                head = head->next;
                delete list;
                list = nullptr;
                --length;
            }
            else {
                Todo* temp = get_from_index(n-2);
                list = temp->next;// to be deleted
                temp->next = list->next;
                delete list;
                list = nullptr;
                --length;
            }
        }
    }

    void save_todo(std::string filename) {
        Todo* list = head;
        std::ofstream file;
        filename += ".json";
        file.open(filename);
        if (file.is_open()) {
            file << "[";
            while (list != nullptr) {
                file << createObject(list);
                list = list->next;
            }
            file << "]";
            file.close();
        }
        else std::cout << "Error opening file";
    }

    ~TodoList() {
        Todo* list = head;
        while (head != nullptr) {
            length = 0;
            list = head;
            head = head->next;
            delete list;
        }
        list = nullptr;
    }
};
