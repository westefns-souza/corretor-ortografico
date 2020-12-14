#pragma once

#include <iostream>
#include "node.hpp"

// Referencia:
// Projeto do trabalho 2 (https://github.com/westefns-souza/trabalhoedb)

template <class T>
class Queue
{
public:
    size_t size()
    {
        return this->length;
    }

    void pushBack(T value)
    {
        Node<T> *node = new Node<T>();
        node->value = value;

        if (this->last != nullptr)
        {
            node->prev = this->last;
            this->last->next = node;
        }
        else
        {
            this->first = node;
        }

        this->last = node;
        length++;
    }

    void popFront()
    {
        this->first = this->first->next;
        length--;
    }

    T front()
    {
        return this->first->value;
    }

    T back()
    {
        return this->last->value;
    }

    void print()
    {
        Node<T> *currentNode = this->first;

        while (currentNode != nullptr)
        {
            std::cout <<  currentNode->value << std::endl;

            currentNode = currentNode->next;
        }
    }

private:
    size_t length;
    Node<T> *first;
    Node<T> *last;
};