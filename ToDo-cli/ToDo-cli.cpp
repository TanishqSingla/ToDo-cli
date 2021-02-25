#include <iostream>
#include <string>
#include "todolist.h"

void print_menu() {
    system("cls");
    std::cout << "+-----------------+" << std::endl;
    std::cout << "|   To Do List    |" << std::endl;
    std::cout << "+-----------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "Choose what you want to do" << std::endl;
    std::cout << "1. Add a todo (a)" << std::endl;
    std::cout << "2. List todos (l)" << std::endl;
    std::cout << "3. Delete a todo (d)" << std::endl;
    std::cout << "4. Save todo (s)" << std::endl;
    std::cout << "5. Exit application (e)" << std::endl;
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
            system("cls");
            std::cout << "Add Todo:" << std::endl;
            std::string todo;
            std::getline(std::cin, todo);
            list.add_todo(todo);
        }

        if (c == 'l') {
            system("cls");
            std::cout << "Todos:" << std::endl;
            list.list_todo();
            char c;
            std::cout << "Press q to go back to menu ";
            while ((c =getchar()) != 'q');
        }

        if (c == 'd') {
            system("cls");
            list.delete_todo();
        }

        if (c == 's') {
            system("cls");
            std::cout << "Enter file name: ";
            std::string filename;
            std::cin >> filename;
            list.save_todo(filename);
        }

        if (c == 'e')
            break;
    }

    // Freeing the memory
    list.free_todo();
 }


// TODO: Use smart pointers
// TOOD: Use JSON for storing todo
// std::unique_ptr<Node> = std::make_unique<Node>(args);
// implement class for nodes
