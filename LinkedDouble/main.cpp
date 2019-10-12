/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 11 de septiembre de 2017, 11:03 AM
 */

#include <cstdlib>

#include "LinkedDouble.cpp"
#include "LinkedDouble.hpp"
#include "FootballTeam.hpp"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    
    int op1, op2,op3,age;  vector<FootballTeam> ft,ft2;  bool cont = true;  string name, code, nameNode;  double value;
    LinkedDouble<FootballTeam> linked;
    LinkedDouble<FootballTeam> linkedSorted;
    FootballTeam *footballTeam;
    linked.addBegin(FootballTeam("23x","Manchester United",98,9000));
    linked.addBegin(FootballTeam("24x","Real Madrid",100,1000));
    linked.addBegin(FootballTeam("25x","FC Barcelona",40,200));
    
    linkedSorted.addSort(FootballTeam("5x","America_De_Cali",30,4));
    linkedSorted.addSort(FootballTeam("4x","Junior_De_Barranquilla",30,6));
    linkedSorted.addSort(FootballTeam("9x","Nacional",30,6));
    linkedSorted.addSort(FootballTeam("2x","Barranquilla FC",30,4));
    std::vector<FootballTeam> aux;
    
    while(cont){
    cout<<"                       MENU"<<endl;
    cout<<"(1).<Mostrar equipos> (2).<Agregar> (3).<Buscar> (4).<Salir> (5).<Eliminar>"<<endl;
    cout<<"Seleccionar : "<<endl;
    cin>>op1;
    switch(op1){
        case 1:
            cout<<"Mostrando listas..."<<endl;
            ft = linked.printList(true);
            ft2 = linkedSorted.printList(true);          
            cout<<"Lista numero 1:"<<endl;
            for(int i=0; i<ft.size();i++){cout<<ft[i].toString()<<endl;}
            cout<<"fin lista 1:"<<endl;
            cout<<""<<endl;
            cout<<"Lista 2 : "<<endl;
            for(int j=0; j<ft2.size();j++){cout<<ft2[j].toString()<<endl;}
            cout<<"fin lista 2:"<<endl;
            
            break;
        case 2:
            system("cls");
            cout<<"OPCION : AGREGAR"<<endl;
            cout<<"(1).<Agregar al comienzo> (2).<Agregar al final> (3).<Agregar antes de:> (4).<Agregar despues de:> "
                    "(5).<Agregar Ordenado>"<<endl;
            cout<<"Seleccionar : "<<endl;
            cin>>op2;
            switch(op2){
                case 1:
                    system("cls");
                    cout<<" SE AGREGARA AL COMIENZO "<<endl;
                    cout<<"            FOOTBALL TEAM\n"<<endl;
                    cout<<"Digite el código : "<<endl;
                    cin>>code;
                    cout<<"Digite el nombre : "<<endl;
                    cin>>name;
                    cout<<"Digite la edad del equipo : "<<endl;
                    cin>>age;
                    cout<<"Digite el valor del equipo : "<<endl;
                    cin>>value;
                    
                    linked.addBegin(FootballTeam(code,name,age,value));
                    cout<<"Se agregó al comienzo de la lista .."<<endl;
                    break;
                case 2:
                    system("cls");
                    cout<<" SE AGREGARA AL FINAL "<<endl;
                    cout<<"            FOOTBALL TEAM\n"<<endl;
                    cout<<"Digite el código : "<<endl;
                    cin>>code;
                    cout<<"Digite el nombre : "<<endl;
                    cin>>name;
                    cout<<"Digite la edad del equipo : "<<endl;
                    cin>>age;
                    cout<<"Digite el valor del equipo : "<<endl;
                    cin>>value;
                    
                    linked.addEnd(FootballTeam(code,name,age,value));
                    cout<<"Se agregó al final de la lista .."<<endl;
                    break;
                case 3:
                    system("cls");
                    cout<<"AGREGAR ANTES DE : "<<endl;
                    cout<<"Digite el codigo del nodo que será predecesor : "<<endl;
                    cin>>nameNode;
                    if(linked.findNode(nameNode) != NULL){
                        cout<<"El NODO EXISTE"<<endl;
                        cout<<"Digite el código : "<<endl;  cin>>code;
                        cout<<"Digite el nombre : "<<endl;  cin>>name;
                        cout<<"Digite la edad del equipo : "<<endl;  cin>>age;
                        cout<<"Digite el valor del equipo : "<<endl;  cin>>value;
                        
                        linked.addBeforeTo(linked.findNode(nameNode),FootballTeam(code,name,age,value));
                        cout<<" >>Se agrego el nuevo nodo<<"<<endl;
                    }
                    break;
                case 4:
                    system("cls");
                    cout<<"AGREGAR DESPUES DE : "<<endl;
                    cout<<"Digite el codigo del nodo que será sucesor : "<<endl;
                    cin>>nameNode;
                    if(linked.findNode(nameNode) != NULL){
                        cout<<"El NODO EXISTE"<<endl;
                        cout<<"Digite el código : "<<endl;  cin>>code;
                        cout<<"Digite el nombre : "<<endl;  cin>>name;
                        cout<<"Digite la edad del equipo : "<<endl;  cin>>age;
                        cout<<"Digite el valor del equipo : "<<endl;  cin>>value;
                        
                        linked.addAfterTo(linked.findNode(nameNode),FootballTeam(code,name,age,value));
                        cout<<" >>Se agrego el nuevo nodo<<"<<endl;
                    }
                    break;
                case 5:
                    system("cls");
                    cout<<"AGREGAR ORDENADO : "<<endl;
                    cout<<"Digite el código : "<<endl;  cin>>code;
                    cout<<"Digite el nombre : "<<endl;  cin>>name;
                    cout<<"Digite la edad del equipo : "<<endl;  cin>>age;
                    cout<<"Digite el valor del equipo : "<<endl;  cin>>value;
                    
                    linkedSorted.addSort(FootballTeam(code,name,age,value));
                    cout<<" >>Se agrego el nuevo nodo<<"<<endl;
                    break;
                default:
                    cout<<"Opcion Invalida"<<endl;
                    break;
            }
            break;
        case 3:
            cout<<"OPCION : BUSCAR"<<endl;
            cout<<"(1).<Buscar posicion de memoria> (2).<Buscar Objeto>"<<endl;
            cin>>op3;
            
            switch(op3){
                case 1:
                    cout<<"BUSCAR POS_MEMORIA"<<endl;
                    cout<<"Digite el codigo : "<<endl;
                    cin>> nameNode;
                    
                    if(linked.findNode(nameNode) != NULL){
                        cout<<linked.findNode(nameNode)<<endl;
                    }else if(linkedSorted.findNode(nameNode) != NULL){
                        cout<<linkedSorted.findNode(nameNode)<<endl;
                    }else{
                        cout<<"EL NODO NO EXISTE"<<endl;
                    }
                    break;
                case 2:
                    cout<<"BUSCAR OBJETO"<<endl;
                    cout<<"Digite el codigo : "<<endl;
                    cin>> nameNode;
                    
                    if(linked.findObject(nameNode) != NULL){
                        footballTeam = linked.findObject(nameNode);
                        cout<<footballTeam->toString()<<endl;
                    }else if(linkedSorted.findObject(nameNode) != NULL){
                        footballTeam = linkedSorted.findObject(nameNode);
                        cout<<footballTeam->toString()<<endl;
                    }else{
                        cout<<"EL NODO NO EXISTE"<<endl;
                    }
                    break;
                    
                default:
                    cout<<"Opcion Invalida"<<endl;
                    break;
            }
            
            break;
        case 4:
            cont = false;
            break;
            
        case 5:
            cout<<"ELIMINAR"<<endl;
            cout<<"Digite el codigo : "<<endl;
            cin>> nameNode;
            
            if(linked.findNode(nameNode)!=NULL ){
                cout<<"El node existe"<<endl;
                linked.deleteNode(linked.findNode(nameNode));
                cout<<"El nodo se elimino correctamente de la lista 1"<<endl;
            }else if(linkedSorted.findNode(nameNode)!= NULL ){
                cout<<"El node existe en la lista ordenada:"<<endl;
                linkedSorted.deleteNode(linkedSorted.findNode(nameNode));
                cout<<"Se eliminó el nodo de la lista 2"<<endl;
            }
            break;
    }
    
    }//WHILE
    
    return 0;
}

