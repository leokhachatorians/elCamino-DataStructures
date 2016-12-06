#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    string value;
    Node *next;
};

class LinkedList {
    public:
        LinkedList() {
            head = nullptr;
        }
        ~LinkedList() {
            Node *p;
            p = head;
            while (p != nullptr) {
                Node *n = p->next;
                delete p;
                p = n;
            }
        }

        void add_to_front(string v) {
            Node *p;
            p = new Node;
            p->value = v;
            p->next = head;
            head = p;
        }

        void add_to_rear(string v) {
            if (head == nullptr) {
                add_to_front(v);
            }
            else {
                Node *p;
                p = head;
                while (p->next != nullptr) {
                    p = p->next;
                }
                Node *n = new Node;
                n->value = v;
                p->next = n;
                n->next = nullptr;
            }
        }

        void add_node(string v) {
            if (head == nullptr) {
                add_to_front(v);
            }
            else if (v < head->value) {
                add_to_front(v);
            }
            else {
                Node *p = head;
                while (p->next != nullptr) {
                    if (v >= p->value && v <= p->next->value ) {
                        break;
                    }
                    p = p->next;
                }
                Node *latest = new Node;
                latest->value = v;
                latest->next = p->next;
                p->next = latest;
            }
        }

        void delete_item(string v) {
            if (head == nullptr) {
                return;
            }
            if (head->value == v) {
                Node *kill = head;
                head = kill->next;
                delete kill;
                return;
            }
            Node *p = head;
            while (p != nullptr) {
                if (p->next != nullptr && p->next->value == v) {
                    break;
                }
                p = p->next;
            }
            if (p != nullptr) {
                Node *kill = p->next;
                p->next = kill->next;
                delete kill;
            }
        }

        void add_at(string v, int index) {
            if (head == nullptr || index == 0) {
                add_to_front(v);
            }
            else {
                Node *prev = new Node;
                Node *current = head;
                Node *new_node = new Node;
                new_node->value = v;
                int count = 0;
                while (current->next != nullptr && count != index) {
                    prev = current;
                    current = current->next;
                    count++;
                }
                if (index > count) {
                    add_to_rear(v);
                }
                prev->next = new_node;
                new_node->next = current;
            }
        }

        void print() { 
            Node *p;
            p = head;
            while (p != nullptr) {
                cout << p->value << " ";
                p = p->next;
            }
            cout << endl;
        }

        bool find_item(string v) {
            if (head == nullptr) {
                return false;
            }
            Node *p;
            p = head;

            while (p != nullptr) {
                if (p->value == v) {
                    return true;
                }
                p = p->next;
            }
            return false;
        }
    private:
        Node *head;
};

int main() {
    LinkedList my_friends;
    my_friends.add_to_front("jeff");
    my_friends.add_to_rear("je3ff");
    my_friends.add_to_rear("jef");
    my_friends.add_to_front("fadhf");
    my_friends.add_at("poop", 6);
    cout << my_friends.find_item("je3ff3") << endl;
    my_friends.print();
    my_friends.delete_item("jeff");
    my_friends.print();
    return 0;
}
