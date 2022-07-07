#include<iostream> 
#include<fstream>
#include "playlist.h"
#include "Record.h"
#include "Artist.h"
#include "Album.h"
#include "Song.h"
using namespace std;

int main(){
    cout << "Welcome to our music streaming database!!!\n";
    cout << "Do you want to login as a user or an artist?\n\nChoose 1 for User or 2 for Artist!\n\n";
    int c;
    cin >> c;
    int numLines = 0;
    ifstream fin("Database - Sheet1.csv");
    string unused;
    while (getline(fin, unused))
        ++numLines;
    do{
        switch(c){
            case 1: cout << "Hello user!\n\nWhat function do you want to perform?\n"
                        << "1. View data\n"
                        << "2. Listen to music\n"
                        << "3. Generate a custom playlist\n"
                        << "4. Log out\n";
                    int a;
                    cin >> a;
                    do{
                        Record *record;
                        string s;
                        switch(a){
                            case 1: {
                                        cout << "Enter 1. to view Artist data\n2. to view Album data\n3. to view Song data: ";
                                        int y;
                                        cin >> y;
                                        if(y == 1){
                                            cout << "Enter the name of the artist: ";
                                            cin.ignore();
                                            getline(cin, s);
                                            record = new Artist();
                                            
                                        }
                                        else if(y == 2){
                                            cout << "Enter the name of the album: ";
                                            cin.ignore();
                                            getline(cin, s);
                                            record = new Album();
                                        }
                                        else{
                                            cout << "Enter the name of the song: ";
                                            cin.ignore();
                                            getline(cin, s);
                                            record = new Song();
                                        }
                                        record -> set(s);
                                        record -> showData();
                                        break;
                                    }
                            case 2: {
                                        cout << "Enter 1. to stream album\n2. to stream single: ";
                                        int y;
                                        cin >> y;
                                        string s1;
                                        cout << "Enter name of the artist: ";
                                        cin.ignore();
                                        getline(cin,s1);
                                        record = new Artist();
                                        record -> set(s1);
                                        if(y == 1){
                                            cout << "Enter name of album: ";
                                        }
                                        else{
                                            cout << "Enter name of single: ";
                                        }
                                        getline(cin, s);
                                        record -> Update(s, y);
                                        break;
                                    }
                            case 3: {
                                        cout << "Enter number of songs you want in the playlist: ";
                                        int num;
                                        cin >> num;
                                        if(num > numLines){
                                            cout << "Not enough songs in the database!\n";
                                            break;
                                        }
                                        playlist(numLines, num);
                                        break;
                                    }
                            default: cout << "Enter a valid input!\n";
                        }
                        cout << "What other function do you want to perform?\n"
                            << "1. View data\n"
                            << "2. Listen to music\n"
                            << "3. Generate a custom playlist\n"
                            << "4. Log out\n";
                        cin >> a;
                    }while(a != 4);
                    break;
            case 2: {
                        cout << "Hello artist!\n\nPlease enter your name: ";
                        string s1, s2, s3;
                        cin.ignore();
                        getline(cin, s1);
                        Record *art = new Artist();
                        art -> set(s1);
                        cout << "What function do you want to perform?\n"
                            << "1. Add single\n"
                            << "2. Add album\n"
                            << "3. Remove single\n"
                            << "4. Remove album\n"
                            << "5. View your data\n"
                            << "6. Log out\n";
                        int b;
                        cin >> b;
                        do{
                            switch(b){
                                case 1: {
                                            cout << "Enter name of the single: ";
                                            cin.ignore();
                                            getline(cin, s3);
                                            art -> Add(s1, s3, s3);
                                            numLines++;
                                            break;
                                        }
                                case 2: {
                                            cout << "Enter album name and number of tracks: ";
                                            int num;
                                            cin.ignore();
                                            getline(cin, s2);
                                            cin >> num;
                                            cout << "Enter name of the track " << 1 << ": ";
                                            cin.ignore();
                                            getline(cin, s3);
                                            art -> Add(s1, s2, s3);
                                            for(int i = 1; i < num; i++){
                                                cout << "Enter name of the track " << i + 1 << ": ";
                                                getline(cin, s3);
                                                art -> Add(s1, s2, s3);
                                            }
                                            numLines += num;
                                            break;
                                        }
                                case 3: {
                                            cout << "Enter the name of the single you want to delete: ";
                                            string s;
                                            cin.ignore();
                                            getline(cin, s);
                                            int y = art -> Delete(s, 2);
                                            numLines -= y;
                                            break;
                                        }
                                case 4: {
                                            cout << "Enter the name of the album you want to delete: ";
                                            string s;
                                            cin.ignore();
                                            getline(cin, s);
                                            int y = art -> Delete(s, 1);
                                            numLines -= y;
                                            break;
                                        }
                                case 5: {
                                            art -> showData();
                                            break;
                                        }
                                default: cout << "Enter a valid input!\n";
                            }
                            cout << "What other function do you want to perform?\n"
                                << "1. Add single\n"
                                << "2. Add album\n"
                                << "3. Remove single\n"
                                << "4. Remove album\n"
                                << "5. View your data\n"
                                << "6. Log out\n";  
                            cin >> b;
                        }while(b != 6);
                        break;
                    }
            default: cout << "Enter a valid input!\n";
        }
        cout << "Do you want to login as a user or an artist?\n\n"
            << "Choose 1 for User\n"
            << "2 for Artist\n"
            << "3 if you want to log out!\n\n";
        cin >> c;
    }while(c != 3);
    cout << "\n\nSuccessfully logged out! Thanks for using our service!\n";
    return 0;
}