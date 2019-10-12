/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodeDouble.hpp
 * Author: Usuario
 *
 * Created on 11 de septiembre de 2017, 11:04 AM
 */

#ifndef NODEDOUBLE_HPP
#define NODEDOUBLE_HPP
#include <cstdlib>
template <class T> class LinkedDouble;
template <class T>
class NodeDouble {
    friend class LinkedDouble<T>;
public:
    NodeDouble(T);
    virtual ~NodeDouble();
private:
    T info;
    NodeDouble<T>* next;
    NodeDouble<T>* last;
};
template<class T>
NodeDouble<T>::NodeDouble(T info){
    this->info = info;
    next=NULL;
    last=NULL;
}
template <class T>
NodeDouble<T>::~NodeDouble(){   
}
#endif /* NODEDOUBLE_HPP */