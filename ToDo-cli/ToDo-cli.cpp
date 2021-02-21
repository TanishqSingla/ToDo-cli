#include <iostream>
#include <string>

struct Todo {
    std::string todo;
    Todo* next = nullptr;
};

class TodoList {
private:
    Todo *head, *list;
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
