#pragma once

template<class T>
struct Node
{
    T value;
    Node<T>* next;
    Node<T>* prev;
};