#include <cstdio>
#include <cstdarg>
#include <iostream>
#include "linkedList.hpp"


template <typename T>
Node<T>::Node(){
    this->next = nullptr;
    this->prev = nullptr;
}


template <typename T>
LinkedList<T>::LinkedList(){
    this->length = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
void LinkedList<T>::Append(T v){
    Node<int>* n = (Node<T>*)malloc(sizeof(Node<T>));
    n->value = v;
    if (this->length <= 0){
        this->tail = n;
        this->head = n;
    } else {
        n->prev = this->tail;
        this->tail->next = n;
        this->tail = n;
    }
    this->length++;
}

template <typename T>
Node<T>* LinkedList<T>::GetElement(int index){
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

template <typename T>
void LinkedList<T>::Print(){
    if (this->length == 0) {
        std::cout << "[ ]" << std::endl;
        return;
    }
    std::cout << "[ ";
    for (int i = 0; i < this->length; i++){
        Node<T>* n = GetElement(i);
        std::cout << n->value << ", ";
    }
    std::cout << "\b\b ]" << std::endl;
}

template <typename T>
void LinkedList<T>::SwapElements(int i1, int i2){
    if (i1 == i2) return;
    Node<T>* n1 = GetElement(i1);    
    Node<T>* n2 = GetElement(i2);    

    if (n1 == this->head){
        n2->prev->next = n1;
        this->head = n2;
        n1->prev = n2->prev;
        n2->prev = nullptr;
    } else if (n2 == this->head){
        n1->prev->next = n2;
        this->head = n1;
        n2->prev = n1->prev;
        n1->prev = nullptr;
    } else {
        n1->prev->next = n2;
        n2->prev->next = n1;
        Node<T>* tempPrev = n1->prev;
        n1->prev = n2->prev;
        n2->prev = tempPrev;
    }

    if (n1 == this->tail){
        n2->next->prev = n1;
        this->tail = n2;
        n1->next = n2->next;
        n2->next = nullptr;
    } else if (n2 == this->tail){
        n1->next->prev = n2;
        this->tail = n1;
        n2->next = n1->next;
        n1->next = nullptr;
    } else {
        n1->next->prev = n2;
        n2->next->prev = n1;
        Node<T>* tempNext = n1->next;
        n1->next = n2->next;
        n2->next = tempNext;
    }

}

template <typename T>
void LinkedList<T>::Extend(int count, ...){
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++){
        T v = va_arg(args, T);
        this->Append(v);
    }
}

