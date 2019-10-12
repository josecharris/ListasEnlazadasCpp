/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedDouble.hpp
 * Author: Usuario
 *
 * Created on 11 de septiembre de 2017, 11:03 AM
 */

#ifndef LINKEDDOUBLE_HPP
#define LINKEDDOUBLE_HPP

#include <vector>
#include <string>

#include "NodeDouble.hpp"


template <class T>
class LinkedDouble {
public:
    LinkedDouble();
    virtual ~LinkedDouble();
    bool isEmpty();
    void addEnd(T);
    void addBegin(T);   
    std::vector<T> printList(bool);
    
    NodeDouble<T>* findNode(std::string);
    T* findObject(std::string);
    void addBeforeTo(NodeDouble<T>*, T);
    void addSort(T);
    void addAfterTo(NodeDouble<T>*, T);
    T* deleteNode(NodeDouble<T>*);
    
    //Complementar con los métodos de la lista sencilla
private:
    NodeDouble<T>* head;
    NodeDouble<T>* end;
};

#endif /* LINKEDDOUBLE_HPP */
/*
  bool isEmpty();
    void addFirst(T);
    void addLast(T);
    NodeList<T>* findNode(string);
    T* findObject(string);
    T* deleteNode(NodeList<T>*);
    void addBeforeTo(NodeList<T>*, T);
    void addSort(T);
    void addAfterTo(NodeList<T>*, T);
    vector<T> getList();*/
