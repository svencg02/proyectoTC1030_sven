#ifndef ORDEN
#define ORDEN // se define para la clase orden 
#include <iostream>
#include <string>
#include <sstream>
#include "Combo.h"
#include <math.h>

const int MAX = 1000; //constante para un maximo de combos en una orden

class Orden{ //aqui se creara la orden que contendra los combos
private:
    Combo *comb[MAX]; //se define el arreglo de combos como apuntador
    int num_combo; //referencia para la posicion del arregglo

public:
    Orden(): num_combo(0) {}; //constructor por default
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
// se crean ejemplos de combo para el programa (objetos)
void Orden::ejemplo(){
    comb[num_combo] = new Grandes("Sven", num_combo, "Adulto", "doble", "grande", 3);
    num_combo++; // se incrementa el indice para el arreglo de objetos 
    comb[num_combo] = new Grandes("Liliana", num_combo, "Adulto", "sencilla", "chico", 1);
    num_combo++;
    comb[num_combo] = new Peques("Romina", num_combo, "Niño", "doble", 2);
    num_combo++;
    comb[num_combo] = new Peques("Jagger", num_combo, "Niño", "sencilla", 1);
    num_combo++;
};
// se imprime el numero de combo la persona y tipo de combo
void Orden::muestra_combos(){
    string duenio, tipo_;
    for (int i = 0; i < num_combo; i++){ // for loop que nos ayuda a imprimir cada uno de los combos en el arreglo de combos 
        duenio = comb[i]->get_combo(); // dado que es un apuntador se utiliza -> en vez de "." 
        cout<<"Combo: "<<i+1<<" de: "<<duenio<<endl;
    };
};
//se busca un tipo de combo especificio y se imprimen esos combos
void Orden::muestra_tipos(string tipo){
    for (int i = 0; i < num_combo; i++) {// for loop que nos permite evaluar cada combo en el arreglo de objetos de tipo combo 
        if (tipo == comb[i]->get_tipo()) { // condicional que revisa que tipo de combos hay y devuelve los que coinciden 
            comb[i] -> get_combo();
        };
    };
};

// se calcula el precio final con base al calculo individual de cada combo dependiendo de su tipo 

double Orden::precio_final(){
    double suma=0;
    for (int i = 0; i < num_combo; i++){ // for loop que nos permite ir incrementando el valor de suma 
        suma = suma + comb[i]->calcula_precio();
    };
    return suma;
};

// se implementa sobrecarga en uno de los metodos para hacer un descuento del 20% 

double Orden::precio_final(string codigo_promo){
    double suma=0;
    if (codigo_promo == "EL_MEJOR_PROYECTO"){ // se evalua si efectivamente se tiene el codigo correcto 
        /*for (int i = 0; i < num_combo; i++){// se implementa el precio de cada uno de los objetos 
            suma = suma + comb[i]->calcula_precio();
        }*/
        return precio_final()*0.8; // se devuelve el precio menos el 20%
    }
    else {
        cout<<"el codigo es incorrecto, lo sentimos..."<<endl;
        return precio_final(); // si el codigo es incorrecto se devuele el precio final normal

    };
}
//se agrega un combo de tipo peques
void Orden::agrega_peque(string nombre, string hamburguesa, int toy){
    comb[num_combo] = new Peques(nombre, num_combo, "Niño", hamburguesa, toy); // se crea un objeto nuevo en el heap y se agrega en el arreglo de objetos 
    num_combo++;
}

//se agrega un combo de tipo grande

void Orden::agrega_grande(string nombre, string hamburguesa, string refresco, int cup){
    comb[num_combo] = new Grandes(nombre, num_combo, "Adulto", hamburguesa, refresco, cup); // se crea un objeto nuevo en el heap y se agrega en el arreglo de objetos 
    num_combo++;
}
// se ingresa un numero y se revisa en el arreglo y devuelve el combo correspondiente 
void Orden::obten_combo(int num){
    if (num <= num_combo){ // se hace una evaluacion sencilla para evitar que ingresen valores mas grandes que los que hay en el arreglo 
        comb[num]->get_combo();
    }
}
// se determina el indice del arreglo, esto puede hacer que se borren objetos ya creados 
void Orden::set_num(int numero){
    num_combo = numero; 
}
#endif
