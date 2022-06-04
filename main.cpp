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

#include <iostream>
#include <string>
#include "Combo.h"
#include "Orden.h"

using namespace std;

int main(){
    Orden orden1;
    orden1.ejemplo();
    cout<<orden1.get_num();
    orden1.muestra_combos();
    orden1.muestra_tipos("Adulto");
    cout<<"El precio final es de: \t"<<orden1.precio_final()<<endl;
    orden1.obten_combo(1);
    orden1.agrega_grande("Benja", "doble", "grande", 5);
    orden1.agrega_peque("arturito", "sencilla", 4);
    cout<<"el precio final actualizado es de \t"<<orden1.precio_final()<<endl;

return 0;
}
