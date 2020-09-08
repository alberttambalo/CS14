
#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <string>
using namespace std;
class PlaylistNode{
    private: 
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;

    public:
        PlaylistNode();
        PlaylistNode(string id, string sName, string aName, int sLength);


        void InsertAfter(PlaylistNode* nodeLoc);
        void SetNext(PlaylistNode* n);
        string GetID() const;
        string GetSongName() const;
        string GetArtistName() const;
        int GetSongLength() const;
        PlaylistNode* GetNext() const;
        void PrintPlaylistNode();
};

class Playlist {
    private:
        PlaylistNode *head;
        PlaylistNode *tail;
    public:
        Playlist();
        void PrintPlaylist();
        void AddToPlaylist();
        void RemoveSong();
        void ChangePosition();
        void outputSongsBy();
        void outputTotalTime();
};
#endif