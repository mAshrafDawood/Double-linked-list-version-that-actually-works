//
// Created by Mohamed on 8/11/2022.
//

#ifndef LINKED_LIST_DOUBLE_LINKED_LIST_HPP
#define LINKED_LIST_DOUBLE_LINKED_LIST_HPP

#include <bits/stdc++.h>

template <class t>
struct node{
public:
    t val;
    node<t> *next;
    node<t> *prev;

    node(){
        this->next = nullptr;
        this->prev = nullptr;
    }

    node(t v, node<t>* n, node<t>* p){
        this->val = v;
        this->next = n;
        this->prev = p;
    }
};

template <class t>
class double_linked_list {
protected:
    node<t>* head;
    node<t>* tail;

public:
    double_linked_list(){
        this->head = new node<t>;
        this->tail = new node<t>;
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }

    explicit double_linked_list(t value){
        this->head = new node<t>;
        this->tail = new node<t>;
        this->head->next = this->tail;
        this->tail->prev = this->head;
        this->insert(value, 0);
    }

    bool insert(t value, int pos = 0){
        node <t>* temp = this->head;
        while ( temp->next != this->tail && pos){
            temp = temp->next;
            pos--;
        }
        if (pos > 0) return false;
        auto *in = new node<t>(value, temp->next, temp);
        temp->next = in;
        in->next->prev = in;
        return true;
    }

    void print_list(){
        node <t> *temp = this->head->next;
        while (temp != this->tail){
            std :: cout << temp->val << " ";
            temp = temp->next;
        }
    }

    bool erase(int pos = 0){
        node <t>* temp = head->next;
        while ( temp != tail && pos){
            temp = temp->next;
            pos--;
        }
        if (temp == this->tail) return false;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        return true;
    }

    //TODO : Erase using a node pointer for internal usage

    bool empty(){
        return this->head->next == this->tail;
    }

    bool clear(){
        node<t> *temp = this->head->next;
        while (temp != tail){
            temp = temp->next;
            erase(0);
        }
        return true;
    }
};


#endif //LINKED_LIST_DOUBLE_LINKED_LIST_HPP
