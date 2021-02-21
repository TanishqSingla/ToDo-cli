#include <iostream>
#include <string>
#define MAXCHARLEN 256

struct Todo {
    char todo[MAXCHARLEN];
    Todo* next;
};


int main()
{
    Todo* head = NULL;
    std::cout << "+-----------------+" << std::endl;
    std::cout << "|   To Do List    |" << std::endl;
    std::cout << "+-----------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "Choose what you want to do" << std::endl;
    std::cout << "1. Add a todo (a)" << std::endl;
    std::cout << "2. List todos (l)" << std::endl;
    std::cout << "3. Delete a todo (d)" << std::endl;
    std::cout << "4. Exit application (e)" << std::endl;

    char c;
    std::cin >> c;

    if (c == 'a') {
        if (head == NULL) {
            head = new Todo();
            std::cin.getline(head->todo, sizeof(head->todo));
        }
        else if (head->next == NULL) {
            Todo* next = new Todo();
            head->next = next;
        }
    }

    if (c == 'l') {
        if (head == NULL) {
            std::cout << "There are no todos";
        }
    }
 }
