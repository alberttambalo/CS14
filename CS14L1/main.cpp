#include "Playlist.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <istream>
using namespace std;

void PrintMenu(string tit){
    cout << endl;
    cout << tit << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option:" << endl;
    return;
}

int main(){
    string Ptitle;
    char userChoice;
    cout << "Enter playlist's title:" << endl;
    getline(cin, Ptitle);
    
    Playlist newP;

    do{
        //cout << endl;
        PrintMenu(Ptitle);
        cin >> userChoice;
        cin.ignore();
        if(userChoice == 'a'){
            cout << "ADD SONG" << endl;
            newP.AddToPlaylist();
        } else if(userChoice == 'd'){
            cout << "REMOVE SONG" << endl;
            newP.RemoveSong();
        } else if(userChoice == 'c'){
            cout << "CHANGE POSITION OF SONG" << endl;
            newP.ChangePosition();
        } else if(userChoice == 's'){
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            newP.outputSongsBy();
        } else if(userChoice == 't'){
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            newP.outputTotalTime();
        } else if(userChoice == 'o'){
            cout << Ptitle << " - OUTPUT FULL PLAYLIST";
            newP.PrintPlaylist();
        } else if(userChoice == 'q'){
            break;
        }
    } while(true);
}