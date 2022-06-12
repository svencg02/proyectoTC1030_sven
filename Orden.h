#ifndef ORDEN
#define ORDEN
#include <iostream>
#include <string>
#include <sstream>
#include "Combo.h"
#include <math.h>

const int MAX = 1000; //constante para un maximo de combos en una orden

class Orden //aqui se creara la orden que contendra los combos
{
private:
    Combo *comb[MAX]; //se define el arreglo de combos como apuntador
    int num_combo; //referencia para la posicion del arregglo

public:
    Orden(): num_combo(0) {}; //constructor por default
   // ~Orden(); //destructor
    void ejemplo();
    void muestra_combos();
    void muestra_tipos(string tipo);
    double precio_final();
    double precio_final(string codigo_promo);
    void agrega_peque(string nombre, string hamburguesa, int toy);
    void agrega_grande(string nombre, string hamburguesa, string refresco, int cup);
    void obten_combo(int num);
    int get_num(){return num_combo;};
    void set_num(int numero_combo);
};
// se crean ejemplos para el programa
void Orden::ejemplo(){
    comb[num_combo] = new Grandes("Sven", num_combo, "Adulto", "doble", "grande", 3);
    num_combo++;
    comb[num_combo] = new Grandes("Liliana", num_combo, "Adulto", "sencilla", "chico", 1);
    num_combo++;
    comb[num_combo] = new Peques("Romina", num_combo, "Niño", "doble", 2);
    num_combo++;
    comb[num_combo] = new Peques("Jagger", num_combo, "Niño", "sencilla", 1);
    num_combo++;
}
// se imprime el numero de combo y la persona y tipo de combo
void Orden::muestra_combos(){
    string aux;
    for (int i = 0; i < num_combo; i++){
        aux = comb[i]->get_combo();
        cout<<"Combo: "<<i+1<<" de: "<<aux<<endl;
    }
};
//se busca un tipo de combo especificio y se imprimen esos combos
void Orden::muestra_tipos(string tipo){
    for (int i = 0; i < num_combo; i++)
        if (tipo == comb[i]->get_tipo()) {
            comb[i] -> get_combo();
        }
}

// se calcula el precio final

double Orden::precio_final(){
    double suma=0;
    for (int i = 0; i < num_combo; i++){
        suma = suma + comb[i]->calcula_precio();
    }
    return suma;
}

double Orden::precio_final(string codigo_promo){
    if (codigo_promo == "EL_MEJOR_PROYECTO"){
        double suma=0;
    for (int i = 0; i < num_combo; i++){
        suma = suma + comb[i]->calcula_precio();
    }
    return suma*0.8;
    }
    else {
        cout<<"el codigo es incorrecto, lo sentimos..."<<endl;
        precio_final();
    }

}
//se agrega un combo de tipo peques
void Orden::agrega_peque(string nombre, string hamburguesa, int toy){
    comb[num_combo] = new Peques(nombre, num_combo, "Niño", hamburguesa, toy);
    num_combo++;
}

//se agrega un combo de tipo grande

void Orden::agrega_grande(string nombre, string hamburguesa, string refresco, int cup){
    comb[num_combo] = new Grandes(nombre, num_combo, "Adulto", hamburguesa, refresco, cup);
    num_combo++;
}

void Orden::obten_combo(int num){
    if (num <= num_combo){
        comb[num]->get_combo();
    }
}
void Orden::set_num(int numero){
    num_combo = numero;
}
#endif
