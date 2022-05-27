#ifndef PLAYLIST
#define PLAYLIST
#include <iostream>
#include <string>
#include <random>
#include <Song.h>

using namespace std;

class Playlist
{
protected:
    string name;
    int num_songs;
private:
    Song songs[]; //array dinamico 
public:
    Playlist(): name(""), num_songs(1), songs[1](Song()); //aqui marca error pero se corregira con los apuntadores despues
    ~Playlist();
    Playlist(string nom, int num, Song cancion): name(nom), num_songs(num), songs[1](cancion){};//aqui marca error pero se corregira con los apuntadores despues
    Playlist(string nom, int num){
        //asignacion variables
    };
    ~Playlist();
    int shuffle(){}; //este sera sobreescrito posteriormente 
    void enhance(){}; //este metodo se utilizara para polimorfismo posteriormente 

};

class Personalized : public Playlist { //herencia de Playlist 
private: 
    Song songs[]; // este arreglo sera dinamico y funcionara con apuntadores 
public:
    Personalized();
    //aqui falta un constructor 
    ~Personalized();
    Personalized(string nom, int num, Song cancion): Playlist(nom, num, cancion){
        //se asigna la cancion a la lista dinamica songs 
    }
    void addSong(string cancion);
    void removeSong(string cancion);
    void enhannce();
    void set_name(string nom);
    void enhance(){
        /* cuando se tenga una lista de canciones con sus respectivos generos se hara un algoritmo que detecte los generos mas repetidos 
        en cada playlist y se a~nadara nuevas canciones con base a los gustos del usuario */
    };
    int shuffle(){
        /* se supone que el shuffle solo funcionara en playlist de estilo personalizado, en las generadas hara una reproduccion en orden, 
        ya sea de mas recientes a mas antiguas, o por orden alfabetico, genero, etc. No desarrollo codigo pq necesito listas dinamicas
        */
    }
};

class Generated : public Playlist {

private:
    Song songs[];
    string theme;
public:
    Generated();
    ~Generated();
    Generated(string nom, int num, string theme): Playlist(nom, num) {
        //asignacion de variables y dependiendo a theme se generara la playlist buscando canciones aleatorias para la playlist
        // songs [1] = cancion
    };
    void enhance(string genre){
        /* cuando se genere la playlist recibira como parametro un genero, creara la playlist con base a ese genero, pero si se quiere mejorar
        la playlist se puede dar otro genero para que agregue mas canciones del genero*/
    };
    int shuffle(){
        /* se supone que el shuffle solo funcionara en playlist de estilo personalizado, en las generadas hara una reproduccion en orden, 
        ya sea de mas recientes a mas antiguas, o por orden alfabetico, genero, etc. No desarrollo codigo pq necesito listas dinamicas
        */
    }
    void change_genre(string genre){
        /* sobreescribe la playlist con el nuevo genero musical */ 
    }
   
};

#endif