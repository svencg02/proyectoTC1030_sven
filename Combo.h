#ifndef COMBO
#define COMBO
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Combo{
protected:
    string cliente;
    int combo_id;
    string tipo_combo;
    string tipo_hamb;
    string tam_refresco;

public:
    Combo(): cliente("na"), combo_id(0), tipo_combo("na"), tipo_hamb("sencilla"), tam_refresco("chico"){};
    Combo(string nom, int id, string tipo, string ham, string refresco):cliente(nom), combo_id(id), tipo_combo(tipo), tipo_hamb(ham), tam_refresco(refresco){};
    virtual double calcula_precio() = 0; //aplicamos abstaccion o virtual puro por lo que no se puede crear un objeto combo 
    virtual string imprime_combo() = 0; //aplicamos polimorfismo a traves del virtual
    string get_combo();
    string get_tipo();
};
// este metodo regresa el tipo de combo y el cliente correspondiente 
string Combo::get_combo(){
    string aux;
    aux = " "+cliente+" de tipo: "+tipo_combo+"\n"; // se crea un auxiliar para el combo 
    return aux;
}
// devuelve el tipo 
string Combo::get_tipo(){
    return tipo_combo;
}
// creamos la clase combo que sera hija de combo y por lo tanto se utiliza herencia
class Peques: public Combo { //hacemos publica la clase combo 
private:
    int juguetes;
public:
    Peques(): Combo(), juguetes(0){};
    Peques(string nom, int id, string tipo, string ham, int juguete):
    Combo(nom, id, tipo, ham, "pequeno"), juguetes(juguete){}; // constructor
    //~Peques();
    double calcula_precio(); // aqui se aplica el polimorfismo 
    string imprime_combo(); // aqui tambien aplica polimorfismo 
};

// se calcula el precio del combo considerando que es de tipo peques
double Peques::calcula_precio(){

    double precio_ham, precio_juguetes;
    double precio_refresco = 25.5;

    if (tipo_hamb == "doble"){// si la hmaburguesa es doble tiene un costo extra
        precio_ham = 89.9;
    }
    else {precio_ham = 59.9;}; // si la hamburguesa es sencilla tiene un costo base 

    precio_juguetes = (double) juguetes * 35.5;// se considera a juguetes como double para multiplicarlo por el precio individual de cada uno

    return precio_ham + precio_juguetes + precio_refresco; // se devuelve la suma de todo 
};
// se imprime el combo considerando que es de tipo peques 
string Peques::imprime_combo(){
    stringstream prompt; // se crea un auxiliar para concatenar un string 
    prompt<<"cliente: "<<cliente<<" su combo con numero: "<<combo_id<<" de tipo: Niños incluye una hamburguesa: "
    <<tipo_hamb<<" con refresco: pequeño y un total de "<<juguetes<<" juguetes."<<"\n"<<"Precio: "<<calcula_precio()<<"\n";
    return prompt.str(); // se imprime el string 
}
// esta clase es hija de Combo 
class Grandes: public Combo {
private:
    int cupones;
public:
    Grandes(): Combo(), cupones(0){};
    Grandes(string nom, int id, string tipo, string ham, string refresco, int cupon):
    Combo(nom, id, tipo, ham, refresco), cupones(cupon){}; // se asignan los atributos con el constructor 
    double calcula_precio(); // polimorfismo
    string imprime_combo(); // polimorfismo 
};
// se calcula el precio del combo basandose en las caracteristicas del combo grande 
double Grandes::calcula_precio(){
    double precio_ham, precio_juguetes, precio_refresco; // se definen las variables para cada uno de los articulos 
    if (tam_refresco == "grande"){ // se avalua las caractristicas del combo 
        precio_refresco = 49.9;
    }
    else if (tam_refresco == "chico") {precio_refresco = 25.5;}

    else {cout<<"ese no es un tamaño valido";};

    if (tipo_hamb == "doble"){
        precio_ham = 89.9;
    }
    else if (tipo_hamb == "sencilla") {precio_ham = 59.9;};

    precio_juguetes = (double) cupones * 20; // 

    return precio_ham + precio_juguetes + precio_refresco; // se regresa la suma de cada uno de los objetos 
}
// se imprime el combo correspondiente al combo grande (polimorfismo) 
string Grandes::imprime_combo(){
    stringstream prompt;
    prompt<<"cliente: "<<cliente<<" su combo con numero: "<<combo_id<<" de tipo: Adulto incluye una hamburguesa: "
    <<tipo_hamb<<" con refresco: "<<tam_refresco<<" y un total de "<<cupones<<" cupones."<<"\n"<<"Precio: "<<calcula_precio()<<"\n";
    return prompt.str(); // se regresa el string 
}
#endif
