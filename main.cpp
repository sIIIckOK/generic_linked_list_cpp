#include <cstdio>
#include <iostream>
#include <string>

template <typename T>
class Node{
    public:
        T value;
        struct Node<T>* next;
        struct Node<T>* prev;
};

template <typename T>
class LinkedList{
    public:
        size_t length;
        Node<T>* head;
        Node<T>* tail;
        LinkedList<T>(T v){
            Node<T>* n = new Node<T>;
            n->value = v;
            n->next = nullptr;
            n->prev = nullptr;
            this->length = 1;
            this->head = n;
            this->tail = n;
        }
        void Append(T v){
            Node<T>* n = new Node<T>;
            n->value = v;
            n->next = nullptr;
            n->prev = this->tail;
            this->tail->next = n;
            this->tail = n;
            this->length++;
        }
        Node<T>* GetElement(int index){
            Node<T>* nextNode = this->head;
            for (int i = 0; i < index; i++){
                nextNode = nextNode->next; 
                if (nextNode == NULL){
                    std::cerr << "[ERROR] in GetElement, element out of bounds" << std::endl;
                    break;
                }
            }
            return nextNode;
        } 

        void Print(){
            std::cout << "[ ";
            for (int i = 0; i < this->length; i++){
                Node<T>* n = GetElement(i);
                std::cout << n->value << ", ";
            }
            std::cout << "\b\b ]" << std::endl;
        }
};

int main(){
    LinkedList<int> l(1);
    l.Append(2);
    l.Append(3);
    Node<int>* n = l.GetElement(2);
    std::cout << n->value << std::endl;
}

