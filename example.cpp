#include "linkedList.hpp"
#include "linkedList.cpp"

int main(){
    //LinkedList: is the type of a linked list 
    LinkedList<int> l;
    //Append: appends a node to the linked list
    //void(T value) T is a template
    l.Append(3);
    //Print: prints the linked list
    l.Print();
    //Extend: is a variadic function; it appends multiple elements to the linked list
    //void(int count, T ...) T is a template
    l.Extend(3, 1, 2, 3);
    l.Print();
}
