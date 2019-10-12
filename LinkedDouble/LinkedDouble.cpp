/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedDouble.cpp
 * Author: Usuario
 * 
 * Created on 11 de septiembre de 2017, 11:03 AM
 */

#include "LinkedDouble.hpp"
#include <string>
#include <vector>

template <class T>
LinkedDouble<T>::LinkedDouble() {
    head = NULL;
    end = NULL;
}
template <class T>
bool LinkedDouble<T>::isEmpty(){
    return head==NULL && end == NULL;
}
template <class T>
void LinkedDouble<T>::addEnd(T info){
    NodeDouble<T>* recent = new NodeDouble<T>(info);
    if(isEmpty()){
        head = end = recent;
    }else{
        end->next = recent;
        recent->last = end;
        end = recent;
    }
}
template <class T>
void LinkedDouble<T>::addBegin(T info){
    NodeDouble<T>* aux = new NodeDouble<T>(info);
    if(isEmpty()){
        head = end = aux;
    }else{
        aux->next=head;
        head->last=aux;
        head = aux;
    }
}
template <class T>
std::vector<T> LinkedDouble<T>::printList(bool sw){
    std::vector<T> output;
    if(sw){
        NodeDouble<T>* aux2 = head;
        while(aux2 != NULL){
            output.push_back(aux2->info);
            aux2 = aux2->next;
        }
    }else{
        NodeDouble<T> *aux = end;
        while(aux != NULL){
            output.push_back(aux->info);
            aux = aux->last;
        }
    }
    return output;
}
////////////////////////////////////////////////
template<class T>
NodeDouble<T>* LinkedDouble<T>::findNode(std::string key){
    NodeDouble<T>* aux = head;
    while( aux != NULL ){
        if(aux->info.getIdTeam().compare(key) == 0){
            return aux;
        }
        aux = aux->next;
    }
    return NULL;   
}
template<class T>
T* LinkedDouble<T>::findObject(std::string key) {
    NodeDouble<T>* aux = head;
    while(aux!=NULL){
        if(aux->info.getIdTeam().compare(key)==0){
            return &aux->info;
        }
        aux = aux->next;
    }
    return NULL;
}
template <class T>
void LinkedDouble<T>::addBeforeTo(NodeDouble<T>* node , T info){
    NodeDouble<T>* newNode = new NodeDouble<T>(info);
    newNode->next=node;
    if(node==head){
        head = newNode;
    }else{
        NodeDouble<T>* aux = head;
        while(aux->next != node){
            aux = aux->next;
        }
        aux->next = newNode;
    }
}
template <class T>
void LinkedDouble<T>::addAfterTo(NodeDouble<T>* node, T info){
    NodeDouble<T>* newNode = new NodeDouble<T>(info);
    newNode->next = node->next;
    node->next = newNode;
}
template <class T>
void LinkedDouble<T>::addSort(T info){
    NodeDouble<T>* newNode = new NodeDouble<T>(info);
    if(isEmpty()){
        head = newNode;
    }else{
        NodeDouble<T>* aux = head;
        NodeDouble<T>* ant = NULL;
        
        while(aux!= NULL && aux->info.getIdTeam().compare(info.getIdTeam())<0){
            ant = aux;
            aux=aux->next;
        }
        if(ant==NULL){
            head = newNode;
        }else{
            ant->next=newNode;
        }
        newNode->next = aux;  
    }   
}
template <class T>
T* LinkedDouble<T>::deleteNode(NodeDouble<T>*node){
    T* aux = &node->info;
    if(node==head){
        head = head->next;
    }else{
        NodeDouble<T>*x=head;
        while(x->next!=node){
            x = x->next;
        }
        x->next = node->next;
    }
    delete(node);
    return aux;
}
template <class T>
LinkedDouble<T>::~LinkedDouble() { }