#include<iostream> 
#include<fstream>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
#include<iomanip>
using namespace std;

void playlist( int numLines,  int num){
    vector<int> v(numLines);
    for(int i = 0; i < numLines; i++)
        v[i] = i;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(v.begin(), v.end(), default_random_engine(seed));
    sort(v.begin(), v.begin() + num);
    ifstream fin("Database - Sheet1.csv", ios::in);
    int i = 0, j = 0;
    vector<string> row;
    string line, word;
    cout << setw(42) << left << "Song" << setw(42) << "Album" << setw(42) << "Artist";
    cout << endl;
    while(!fin.eof() && j < num){
        row.clear();
        getline(fin, line);
        if(i != v[j]){
            i++;
            continue;
        }
        j++;
        i++;
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        int row_size = row.size();
        for(int k = 2; k >= 0; k--)
            cout << setw(42) << left << row[k];
        cout << endl;
    }
}