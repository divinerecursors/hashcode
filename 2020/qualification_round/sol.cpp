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

int main(){
    string filename = "input_data/a_example.txt";

    vector<string> file_data = readFile(filename);
    vector<string> scores_string_arr = split(file_data[1], ' ');

    int no_of_books, no_of_libs, days;

    no_of_books = atoi(split(file_data[0], ' ')[0].c_str());
    no_of_libs = atoi(split(file_data[0],' ')[1].c_str());
    days = atoi(split(file_data[0], ' ')[2].c_str());

    int* scores = new int[no_of_books];

    for(int i=0; i<no_of_books; i++){
        scores[i] = atoi(scores_string_arr[i].c_str());
    }

    

    return 0;
}