#ifndef USER
#define USER
#include <iostream>
#include <string>
#include <random>
#include <Song.h>
#include <Playlist.h>

using namespace std;

class User
{
private:
    string nametag;
    int id_user;
    string mail;
    Playlist playlists[]; //apuntadores

public:
    User();
    ~User();
    User(string tag, string mail_): nametag(tag), mail(mail_), id_user(0){};
    void create_playlist(string nom, int num);
    void create_playlist(string nom, int num, Song cancion);
    void set_nametag(string name);
    string get_nametag();
    string search_song(string cancion); //el return debera de ser title de una cancion

};

#endif