#ifndef COMBO
#define COMBO
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Combo
{
protected:
    string cliente;
    int combo_id;
    string tipo_combo;
    string tipo_hamb;
    string tam_refresco;

public:
    Combo(string nom, int id, string tipo, string ham, string refresco):cliente(nom), combo_id(id), tipo_combo(tipo), tipo_hamb(ham), tam_refresco(refresco){};
    virtual double calcula_precio() = 0; //aplicamos abstaccion o virtual puro por lo que no se puede crear un objeto combo 
    virtual string imprime_combo(){string aux = "no aplica"; return aux;}; //aplicamos polimorfismo a traves del virtual
    string get_combo();
    string get_tipo();
};

string Combo::get_combo(){
    string aux;
    aux = " "+cliente+" de tipo: "+tipo_combo+"\n";
    return aux;
}

string Combo::get_tipo(){
    return tipo_combo;
}

class Peques: public Combo {
private:
    int juguetes;
public:
    //Peques(); //constructor default
    Peques(string nom, int id, string tipo, string ham, int juguete):
    Combo(nom, id, tipo, ham, "pequeno"), juguetes(juguete){}; // constructor
    //~Peques();
    double calcula_precio();
    string imprime_combo();
};

double Peques::calcula_precio(){

    double precio_ham, precio_juguetes;
    double precio_refresco = 25.5;

    if (tipo_hamb == "doble"){
        precio_ham = 89.9;
    }
    else {precio_ham = 59.9;};

    precio_juguetes = (double) juguetes * 35.5;

    return precio_ham + precio_juguetes + precio_refresco;
};

string Peques::imprime_combo(){
    stringstream prompt;
    prompt<<"cliente: "<<cliente<<" su combo con numero: "<<combo_id<<" de tipo: Niños incluye una hamburguesa: "
    <<tipo_hamb<<" con refresco: pequeño y un total de "<<juguetes<<" juguetes."<<"\n"<<"Precio: "<<calcula_precio()<<"\n";
    return prompt.str();
}

class Grandes: public Combo {
private:
    int cupones;
public:
    Grandes(); // falta constructor default
    Grandes(string nom, int id, string tipo, string ham, string refresco, int cupon):
    Combo(nom, id, tipo, ham, refresco), cupones(cupon){};
    ~Grandes();
    double calcula_precio();
    string imprime_combo();
};

double Grandes::calcula_precio(){
    double precio_ham, precio_juguetes, precio_refresco;
    if (tam_refresco == "grande"){
        precio_refresco = 49.9;
    }
    else if (tam_refresco == "chico") {precio_refresco = 25.5;}

    else {cout<<"ese no es un tamaño valido";};

    if (tipo_hamb == "doble"){
        precio_ham = 89.9;
    }
    else if (tipo_hamb == "sencilla") {precio_ham = 59.9;};

    precio_juguetes = (double) cupones * 20;

    return precio_ham + precio_juguetes + precio_refresco;
}

string Grandes::imprime_combo(){
    stringstream prompt;
    prompt<<"cliente: "<<cliente<<" su combo con numero: "<<combo_id<<" de tipo: Adulto incluye una hamburguesa: "
    <<tipo_hamb<<" con refresco: "<<tam_refresco<<" y un total de "<<cupones<<" cupones."<<"\n"<<"Precio: "<<calcula_precio()<<"\n";
    return prompt.str();
}
#endif
