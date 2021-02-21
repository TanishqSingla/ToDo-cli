#include <iostream>
#include <string>

struct Todo {
    std::string todo;
    Todo* next = nullptr;
};

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
    Todo* head = nullptr;
    Todo* list = head;
    
    char c;

    while (true) {
        print_menu();
        std::cin >> c;
        std::cin.ignore();

        if (c == 'a') {
            if (head == nullptr) {
                head = new Todo();
                std::getline(std::cin, head->todo);
            }
            else {
                list = head;
                while (list->next != nullptr)
                    list = list->next;
                Todo* next = new Todo();
                list->next = next;
                std::getline(std::cin, next->todo);
                next->next = nullptr;
            }
        }

        if (c == 'l') {
            if (head == nullptr) {
                std::cout << "There are no todos";
            }
            else if (head != nullptr && head->next == nullptr) {
                std::cout << head->todo << std::endl;
            }
            else {
                list = head;
                int i = 1;
                while (list != nullptr) {
                    std::cout << i << ". " << list->todo << std::endl;
                    list = list->next;
                    i++;
                }
            }
        }

        if (c == 'd') {
            if (head == nullptr) {
                std::cout << "There are no todos" << std::endl;
            }
            else {
                std::cout << "Enter the todo number you want to delete";
                unsigned n;
                std::cin >> n;
                list = head;
                if (n == 1) { // Deleting head
                    Todo* temp = head;
                    head = head->next;
                    delete temp;
                }
                else {
                    Todo* temp = list;
                    for (unsigned i = 1; i < n - 1; i++) {
                        temp = list;
                        list = list->next;
                    }
                    temp->next = list->next;
                    delete list;
                }
            }
        }

        if (c == 'e')
            break;
    }
 }


// TODO: Use smart pointers
// TOOD: Use JSON for storing todo
// std::unique_ptr<Node> = std::make_unique<Node>(args);
// implement class for nodes
