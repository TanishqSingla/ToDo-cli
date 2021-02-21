#include <iostream>
#include <string>
#include "todolist.h"

void print_menu() {
    std::cout << "+-----------------+" << std::endl;
    std::cout << "|   To Do List    |" << std::endl;
    std::cout << "+-----------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "Choose what you want to do" << std::endl;
    std::cout << "1. Add a todo (a)" << std::endl;
    std::cout << "2. List todos (l)" << std::endl;
    std::cout << "3. Delete a todo (d)" << std::endl;
    std::cout << "4. Exit application (e)" << std::endl;
}

int main()
{
    TodoList list;
    
    char c;

    while (true) {
        print_menu();
        std::cin >> c;
        std::cin.ignore();

        if (c == 'a') {
            std::string todo;
            std::getline(std::cin, todo);
            list.add_todo(todo);
        }

        if (c == 'l')
            list.list_todo();

        if (c == 'd') {
            list.delete_todo();
        }

        if (c == 'e')
            break;
    }

 }


// TODO: Use smart pointers
// TOOD: Use JSON for storing todo
// std::unique_ptr<Node> = std::make_unique<Node>(args);
// implement class for nodes
