#ifndef SONG
#define SONG
#include <iostream>
#include <string>
#include <random>

using namespace std;

class Song {
    
protected:
    string title;
    int duration;
    string author;
    string album;
    string genres[]; //lista dinamica 

private:
    int id_song;

public:
    Song(): title(""), duration(0), author(""), album(""), id_song(0){};//constructor
    
    ~Song(); //destructor 
    
    Song(string titl, int durat, string auth, string albu, string genres):
      title(titl), duration(durat), author(auth), album(albu), id_song(rand()) {}; // sobrecarga 
    
    Song(int durat, string titl, string auth, string genre):
      title(titl), duration(durat), author(auth), id_song(rand()) {}; //sobrecarga
    Song(int durat, string titl, string auth):
      title(titl), duration(durat), author(auth), id_song(rand()) {}; //sobrecarga
    string get_title() {
        return title;
    };

    int get_duration(){
        return duration;
    };

    string get_author() {
        return author;
    };

    string get_album() {
        return album;
    };

    int get_id(){
        return id_song;
    };
    void add_genre(string new_genre){
        genre[1] = new_genre; //proximamente se arreglara este error con apuntadores 
    }
};

#endif