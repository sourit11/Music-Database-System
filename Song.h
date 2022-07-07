#ifndef SONG_H
#define SONG_H 
#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<ctype.h>
#include "Record.h"
using namespace std;

class Song : public virtual Record{
    string rec;
    int x;
    public:
    void set( string);
    void Update( string,  int){}
    void showData();
    int Delete( string,  int);
};

void Song :: set( string rec){
    x = 2;
    this -> rec = rec;
}

void Song :: showData()
{
    fstream fin;
    fin.open("Database - Sheet1.csv", ios::in);
    int count = 0;
    vector<string> row;
    string line, word, temp;
    bool flag = true;
    cout << setw(40) << left << "Song" << setw(40) << "Album" << setw(40) << "Artist" << setw(7) << "Streams";
    cout << endl;
    while (!fin.eof()) {
        row.clear();
        getline(fin, temp);
        stringstream s(temp);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        string str = row[x];
        transform(rec.begin(), rec.end(), rec.begin(), ::tolower);
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        if(!fin.eof()){
            if(rec == str){
                count = 1;
                cout << setw(40) << left << row[2];
                cout << setw(40) << left << row[1];
                cout << setw(40) << left << row[0];
                cout << row[3];
                cout << endl;
            }
        }
    }
    if (count == 0)
        cout << "Oops! No songs in the database!\n";
}

int Song :: Delete( string name,  int x)
{
    int del = 0;
    fstream fin, fout;
    fin.open("Database - Sheet1.csv", ios::in);
    fout.open("New.csv", ios::out);
    int count = 0, i;
    char sub;
    int index, new_streams;
    string line, word;
    vector<string> row;
    while (!fin.eof()) {
        row.clear();
        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        int row_size = row.size();
        string str = row[x];
        string art = row[0];
        string newname = name;
        transform(rec.begin(), rec.end(), rec.begin(), ::tolower);
        transform(art.begin(), art.end(), art.begin(), ::tolower);
        transform(newname.begin(), newname.end(), newname.begin(), ::tolower);
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        if (str == newname && art == rec){
            count = 1;
            del++;
            continue;
        }
        if (!fin.eof()) {
            for (i = 0; i < row_size - 1; i++) {
                fout << row[i] << ",";
            }
            fout << row[row_size - 1] << "\n";
        }
    }
    if(!count)
        cout << "Record not found\n";
    fin.close();
    fout.close();
    remove("Database - Sheet1.csv");
    rename("New.csv", "Database - Sheet1.csv");
    return del;
}

#endif