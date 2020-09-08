#include <cstdlib>
#include <iostream>
#include "Playlist.h"
using namespace std;

PlaylistNode::PlaylistNode(){
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}
PlaylistNode::PlaylistNode(string id, string sName, string aName, int sLength){
    uniqueID = id;
    songName = sName;
    artistName = aName;
    songLength = sLength;
    nextNodePtr = nullptr;
}


void PlaylistNode::InsertAfter(PlaylistNode* nodeLoc){
    // this->SetNext(nodeLoc->GetNext());
    // nodeLoc->SetNext(this);          //I WROTE IT BACKWARDS HAHAHA
    // return;
    PlaylistNode *temp = nullptr;
    temp = this->GetNext();
    this->SetNext(nodeLoc);
    nodeLoc->SetNext(temp);
    return;
}

void PlaylistNode::SetNext(PlaylistNode* n){
    this->nextNodePtr = n; 
}//

string PlaylistNode::GetID() const{
    return uniqueID;
}

string PlaylistNode::GetSongName() const{
    return songName;
}

string PlaylistNode::GetArtistName() const{
    return artistName;
}

int PlaylistNode::GetSongLength() const{
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const{
    return this->nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode(){
    cout << "Unique ID: "<< this->GetID() << endl;
    cout << "Song Name: " << this->GetSongName() << endl;
    cout << "Artist Name: " << this->GetArtistName() << endl;
    cout << "Song Length (in seconds): " << this->GetSongLength() << endl;
    //cout << endl;
}


Playlist::Playlist(){
    head = nullptr;
    tail = nullptr;
}

void Playlist::PrintPlaylist(){
    int songNum = 1;
    if(this->head == nullptr){
        cout << endl << "Playlist is empty" << endl;
    }else{
        PlaylistNode* curr = this->head;
        while(curr != nullptr){
            cout << endl;
            cout << songNum << "." << endl;
            cout << "Unique ID: "<< curr->GetID() << endl;
            cout << "Song Name: " << curr->GetSongName() << endl;
            cout << "Artist Name: " << curr->GetArtistName() << endl;
            cout << "Song Length (in seconds): " << curr->GetSongLength();
            cout << endl;
            songNum++;
            curr = curr->GetNext();
        }
    }
}

void Playlist::AddToPlaylist(){
    string nID;
    string nSongName;
    string nArtistName;
    int nSongLength;

    cout << "Enter song's unique ID:" << endl;
    cin >> nID;
    cin.ignore();
    cout << "Enter song's name:" << endl;
    getline(cin,nSongName);
    cout << "Enter artist's name:" << endl;
    getline(cin, nArtistName);
    cout << "Enter song's length (in seconds):" << endl;
    cin >> nSongLength;

    PlaylistNode *newSong = new PlaylistNode(nID, nSongName, nArtistName, nSongLength);

    if(this->head == nullptr){
        head = newSong;
        tail = newSong;
    } else {
        this->tail->SetNext(newSong);
        this->tail = newSong;
    }
}

void Playlist::RemoveSong(){
    string IDtoRemove;
    string deleting;
    cout << "Enter song's unique ID:" << endl;
    cin >> IDtoRemove;
    
    if(this->head == nullptr){
        cout << "Playlist is empty" << endl;
        return;
    } else {
        while(true){
            PlaylistNode* first = this->head;
            if((first->GetID() == IDtoRemove)){
                head = first->GetNext();
                deleting = first->GetSongName();
                delete first;
                cout << '"' << deleting << '"' <<" removed.";
                return;
            } else {
                //curr = curr->GetNext();
                break;
            }
        }
    }

    PlaylistNode* curr = this->head->GetNext();
    PlaylistNode* pre = this->head;
    
    while(curr != nullptr){
        if(curr->GetID() != IDtoRemove){
            curr = curr->GetNext();
            pre = pre->GetNext();
        } else {
            if(curr->GetNext() == nullptr){
                deleting = curr->GetSongName();
                cout << '"' << deleting << '"' <<" removed." << endl;
                pre->SetNext(curr->GetNext());
                delete curr;
                tail = pre;
                return;
            } else {
                deleting = curr->GetSongName();
                cout << '"' << deleting << '"' <<" removed." << endl;
                pre->SetNext(curr->GetNext());
                delete curr;
                return;
            }
            //curr->SetNext(pre->GetNext());
        }
    }
    
}

void Playlist::ChangePosition(){
    int oPos = 0;
    int nPos = 0;

    cout << "Enter song's current position:" << endl;
    cin >> oPos;
    if(oPos < 1){
        cout << "position does not exist";
        return;
    }
    cout << "Enter new position for song:" << endl;
    cin >> nPos;

    if(head == nullptr){
        cout << "Playlist is empty!" << endl;
        return;
    } else if(head->GetNext() ==nullptr){
        if(oPos == 1){
            cout << '"' << head->GetSongName() << '"' << "moved to position 1";
            return;
        }
        return;
    }
    PlaylistNode *curr = head;
    PlaylistNode *fol = head;/////
    PlaylistNode *nLoc = head;
    for(int i = 0; i < oPos-1; ++i){
        curr = curr->GetNext();
        if(curr == nullptr){
            cout << "position does not exist";
            return;
        }
    }
    for(int i = 0; i < oPos-2; ++i){
        fol = fol->GetNext();
    }

    if(oPos == 1){
        head = head->GetNext();
        nLoc = head;
        PlaylistNode *append1 = new PlaylistNode(curr->GetID(), curr->GetSongName(), curr->GetArtistName(), curr->GetSongLength());
        delete curr;
        for(int i = 0; i < nPos-2; ++i){
            nLoc = nLoc->GetNext();
        }
        nLoc->InsertAfter(append1);
        cout <<'"' << append1->GetSongName() <<'"'<< " moved to position " << nPos << endl;
        return;
    }



    PlaylistNode *toappend = new PlaylistNode(curr->GetID(), curr->GetSongName(), curr->GetArtistName(), curr->GetSongLength());
    fol->SetNext(curr->GetNext());
    delete curr;

    if(nPos == 1){
        toappend->SetNext(head);
        head = toappend;
        cout <<'"' << toappend->GetSongName() <<'"'<< " moved to position " << nPos << endl;
        return;
    }

    for(int i = 0; i < nPos-2; ++i){
        nLoc = nLoc->GetNext();
    }

    nLoc->InsertAfter(toappend);
    cout <<'"' << toappend->GetSongName() <<'"'<< " moved to position " << nPos << endl;
}

void Playlist::outputSongsBy(){
    string tName;
    int count = 1;
    PlaylistNode *curr = head;
    cout << "Enter artist's name:" << endl;
    getline(cin, tName);
    while(curr != nullptr){
        if(curr->GetArtistName() == tName){
            cout << endl;
            cout << count << '.' << endl;
            curr->PrintPlaylistNode();
        }
        ++count;
        curr = curr->GetNext();
    }
}

void Playlist::outputTotalTime(){
    int totalTime = 0;
    cout << "Total time: ";
    PlaylistNode *curr = head;

    while(curr != nullptr){
        totalTime += curr->GetSongLength();
        curr = curr->GetNext();
    }
    cout << totalTime << " seconds" << endl;
}



