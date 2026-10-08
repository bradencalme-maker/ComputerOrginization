#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "DLLNode.hpp"
#include "Pair.hpp"

class DoublyLinkedList {
    private:
        DLLNode* head;
        DLLNode* tail;

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        DoublyLinkedList(const DoublyLinkedList& other);
        DoublyLinkedList& operator=(const DoublyLinkedList& other);

        void push_front(int k, double v);
        void push_back(int k, double v);
        bool insert(int k, double v, int i);

        bool pop_front();
        bool pop_back();
        bool remove(int i);
        bool remove_key(int k);
        void clear();

        Pair<int, double> get_front();
        Pair<int, double> get_back();
        Pair<int, double> at(int i);
        double search(int k, double dfault);   //returns value associated with said key
        bool contains(int k);
        bool contains_value(double v);
        int find(int k, int dfault); // returns index

        bool is_empty();
        int size();
        int length();

        // should only be used for debugging
        DLLNode* get_head() {return head;}
        DLLNode* get_tail() {return tail;}

};

#endif
