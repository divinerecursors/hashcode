// greedy approach to solve the problem

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

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

int findInterestFactor(string a, string b) {
    const vector<string> a_data = split(a, ' ');
    const vector<string> b_data = split(b, ' ');

    int common = 0;

    for(auto i=a_data.begin()+2; i!=a_data.end(); i++){
        for(auto j=b_data.begin()+2; j!=b_data.end(); j++){
            if(*i == *j)
                common++;
        }
    }

    const int uncommon_a = a_data.size() - 2 - common; // tags unique in a
    const int uncommon_b = b_data.size() -2 - common; // tags unique in b

    return min({common, uncommon_a, uncommon_b});
}



int main(){
    ifstream fin;
    fin.open("input_data/a_example.txt");

    string n_str;
    getline(fin, n_str);

    int n = atoi(n_str.c_str());

    string image_data[n];

    for(int i=0; i<n; i++)
        getline(fin, image_data[i]);
    
    const int k = findInterestFactor(image_data[0], image_data[3]);
    cout << k << endl;

    string slideshow[n];


    return 0;
}