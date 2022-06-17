/*
  Proyecto Hamburguesas main
  Sven Chávez García
  A01704151
  03/06/2022

  Este es un proyecto que ayuda al usuario a crear una orden de hamburguesas
  a traves de combos de tipo adulto y niño y que calculara sus precios finales
  e imprimira sus respectivos tickets, aplicando polimorfismo, apuntadores, herencia
  abstracción.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include "Combo.h"
#include "Orden.h"// importamos los headers de las clases 
#include <clocale>//importamos las librerias que vamos a utilizar 
using namespace std; // utilizando el estandar de escritura 

int main(){
  setlocale(LC_CTYPE, "Spanish"); // para que se puedan ver las ñ 
  cout<<"bienvenido al sistema de hamburguesas..."<<endl<<"que te gustaría hacer?"<<endl; 
  cout<<"1. correr simulacion"<<endl<<"2. hacer un ejemplo personalizado"<<endl;
  int opcion = 0;
  cin>>opcion;
  if (opcion == 1) {
    Orden orden1;
    orden1.ejemplo(); // se corren ejemplos de clases para hacer una demostracion simple 
    cout<<"en total hay: "<<orden1.get_num()<<" combos"<<endl;
    orden1.muestra_combos(); // mostramos los combos almacenados en el heap 
    orden1.muestra_tipos("Adulto");
    cout<<"El precio final es de: \t"<<orden1.precio_final()<<endl;
    orden1.obten_combo(1); // obtenemos el combo correspondiente a esa posicion 
    orden1.agrega_grande("Benja", "doble", "grande", 5); // agregamos un nuevo objeto 
    orden1.agrega_peque("arturito", "sencilla", 4);
    orden1.muestra_combos(); //  volvemos a mostrar los combos 
    cout<<"el precio final actualizado es de con dos combos nuevos es: \t"<<orden1.precio_final()<<endl; //mostramos el precio final de todos los combos 
    }
  else if (opcion == 2){
    Orden orden2;
    do{
    cout<<"bienvenido al sistema de hamburguesas que le gustaria ordenar el dia de hoy?:"<<endl<<"1. Combo niño "<<endl<<"2. Combo adulto"<<endl<<"3. terminar"<<endl;
    cin>>opcion;
      if (opcion == 1){
        cout<<"por favor indica el nombre"<<endl;
        string nombre;
        cin>>nombre;
        cout<<"por favor indica el tipo de hamburguesa sencilla o doble"<<endl;
        string tipo_hamburguesa;
        cin>>tipo_hamburguesa;
        for_each(tipo_hamburguesa.begin(), tipo_hamburguesa.end(), [](char & c) {
          c = ::tolower(c);}); // se transforma cualquier string a minusculas 
        cout<<"cuantos juguetes quisiera agregar?"<<endl; 
        int juguetes;
        cin>>juguetes;
        orden2.agrega_peque(nombre, tipo_hamburguesa, juguetes); // se crea combo para peques 
      }
      else if (opcion == 2) {
        cout<<"por favor indica el nombre"<<endl;
        string nombre;
        cin>>nombre;
        cout<<"por favor indica el tipo de hamburguesa sencilla o doble"<<endl;
        string tipo_hamburguesa;
        cin>>tipo_hamburguesa;
        cout<<"por favor indica el tipo de refresco chico o grande"<<endl;
        string tipo_refresco;
        cin>>tipo_refresco;
        for_each(tipo_hamburguesa.begin(), tipo_hamburguesa.end(), [](char & c) {
          c = ::tolower(c);});
        for_each(tipo_refresco.begin(), tipo_refresco.end(), [](char & c) {
          c = ::tolower(c);});
        cout<<"cuantos cupones quisiera agregar?"<<endl;
        int cupones;
        cin>>cupones;
        orden2.agrega_grande(nombre, tipo_hamburguesa, tipo_refresco, cupones); // se crea combo para adultos 
      };
    } while (opcion != 3); // cuando se deje de cumplir la condicion continua el codigo 
    cout<<"sus combos son: "<<endl;
    orden2.muestra_combos();
    cout<<"su precio final es: "<<orden2.precio_final()<<endl;
    cout<<"pero si jura que me pondrá 100 de calificacion en mi proyecto... se le hace un 20'%' de descuento"<<endl<<"lo juras?: si \t no"<<endl;
    string juramento;
    cin>>juramento;
    if (juramento == "si"){
      cout<<"su nuevo precio es: "<<orden2.precio_final("EL_MEJOR_PROYECTO")<<endl; // se hace un descuento del 20%
    }
    else{
      cout<<"buuuuuuuu \n";
    }

  };

//
return 0;
}
