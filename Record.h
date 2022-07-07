#ifndef RECORD_H
#define RECORD_H 

#include<iostream> 
#include<fstream>
#include<iomanip>
#include<vector>
using namespace std;

class Record{
    public:
    string rec;
    int x;
    virtual void set( string name) = 0;
    virtual void showData() = 0;
    virtual int Delete( string,  int) = 0;
    virtual void Update( string,  int) = 0;
    void Add( string,  string,  string);
};

void Record :: Add( string artist,  string album,  string song){
    fstream fin, fout;
    fin.open("Database - Sheet1.csv", ios::in);
    fout.open("New.csv", ios::out);
    string line, word;
    vector<string> row;
    while (!fin.eof()) {
        row.clear();
        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        if(!fin.eof()){
            for (int i = 0; i < row.size() - 1; i++) {
                fout << row[i] << ",";
            }
            fout << row[row.size() - 1] << "\n";
        }
    }
    fout << artist << "," << album << "," << song << "," << 0 << "\n"; 
    fin.close();
    fout.close();
    remove("Database - Sheet1.csv");
    rename("New.csv", "Database - Sheet1.csv");
    cout << "New record has been added successfully!\n";
}

#endif