#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)){
        tokens.push_back(token);
    }
   
    return tokens;
}

vector<string> readFile(string filename){
    vector<string> data;

    ifstream fin;
    fin.open(filename);

    string line;
    
    while(fin){
        getline(fin, line);
        data.push_back(line);
    }

    return data;
}

typedef struct LIB_S {
    int n; // number of books
    int m; // number of books the lib can ship in one day
    vector<vector<int>> id_and_scores; //list of (id, scores)
} library;



int main(){
    string filename = "input_data/f_libraries_of_the_world.txt";

    vector<string> file_data = readFile(filename);
    vector<string> scores_string_arr = split(file_data[1], ' ');

    int no_of_books, no_of_libs, days;

    no_of_books = atoi(split(file_data[0], ' ')[0].c_str());
    no_of_libs = atoi(split(file_data[0],' ')[1].c_str());
    days = atoi(split(file_data[0], ' ')[2].c_str());

    int* scores = new int[no_of_books]; // scores of books

    for(int i=0; i<no_of_books; i++){
        scores[i] = atoi(scores_string_arr[i].c_str());
    }

    library library_structure[no_of_libs]; // the library structure

    for(int i=0, j=2; i<no_of_libs; i++, j+=2){
        vector<string> first_line = split(file_data[j], ' ');
        vector<string> second_line = split(file_data[j+1], ' ');

        library_structure[i].n = atoi(first_line[0].c_str());
        library_structure[i].m = atoi(first_line[2].c_str());

        for(string book: second_line){
            vector<int> k;
            k.push_back(atoi(book.c_str()));
            k.push_back(scores[atoi(book.c_str())]);
            library_structure[i].id_and_scores.push_back(k);
        }

    }

    // Code to print library_structure
    // cout << library_structure[0].n << ' ' << library_structure[0].m << endl;

    // for(auto k: library_structure[0].id_and_scores)
    //     cout << k[0] << ' ' << k[1] << endl;

    

    return 0;
}