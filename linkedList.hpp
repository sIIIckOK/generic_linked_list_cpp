#ifndef LinkedList__HPP
#define LinkedList__HPP
#include <cstdio>

template <typename T>
class Node{
    public:
        T value;
        Node<T>* next;
        Node<T>* prev;
        Node<T>();
};

template <typename T>
class LinkedList{
    public:
        size_t length;
        Node<T>* head;
        Node<T>* tail;
        LinkedList();
        void Append(T v);
        Node<T>* GetElement(int index);
        void Print();
        void SwapElements(int index1, int index2);
        void Extend(int count, ...);
};

#endif //LinkedList__HPP
       
       
       
