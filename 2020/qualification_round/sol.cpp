#include<bits/stdc++.h>


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
    int64_t index; //original index of library obtained from input
    int64_t n; // no of books in lib
    int64_t m; // the number of books that can be shipped from library
    int64_t t; // the number of days it takes to finish the library signup process
    vector<vector<int64_t>> id_and_scores; //list of (id, scores)
} library;


bool ascend(const library& p1, const library& p2) {
    return p1.t < p2.t;
}

bool descend(const vector<int64_t>& p1, vector<int64_t>& p2) {
    return p1[1] > p2[1];
}


int main(){
    string filename = "input_data/f_libraries_of_the_world.txt";

    vector<string> file_data = readFile(filename);
    vector<string> scores_string_arr = split(file_data[1], ' ');

    int64_t no_of_books, no_of_libs, days;

    no_of_books = atoi(split(file_data[0], ' ')[0].c_str());
    no_of_libs = atoi(split(file_data[0],' ')[1].c_str());
    days = atoi(split(file_data[0], ' ')[2].c_str());

    int64_t* scores = new int64_t[no_of_books]; // scores of books

    for(int64_t i=0; i<no_of_books; i++){
        scores[i] = atoi(scores_string_arr[i].c_str());
    }

    library library_structure[no_of_libs]; // the library structure

    for(int64_t i=0, j=2; i<no_of_libs; i++, j+=2){
        vector<string> first_line = split(file_data[j], ' ');
        vector<string> second_line = split(file_data[j+1], ' ');

        library_structure[i].index = i;
        library_structure[i].n = atoi(first_line[0].c_str());
        library_structure[i].t = atoi(first_line[1].c_str());
        library_structure[i].m = atoi(first_line[2].c_str());

        for(string book: second_line){
            vector<int64_t> k;
            k.push_back(atoi(book.c_str()));
            k.push_back(scores[atoi(book.c_str())]);
            library_structure[i].id_and_scores.push_back(k);
        }

    }

    sort(library_structure,library_structure+no_of_libs,ascend);

    for(int64_t i=0;i<no_of_libs;i++)
    {
        sort(library_structure[i].id_and_scores.begin(),library_structure[i].id_and_scores.end(),descend);
    }
    
    


    // Code to print64_t library_structure
    // cout << library_structure[0].n << ' ' << library_structure[0].m << endl;

    // for(auto k: library_structure[0].id_and_scores)
    //     cout << k[0] << ' ' << k[1] << endl;

    int64_t n=0;
    
    int64_t x;
    for(x=0;x<=no_of_libs;x++)
    {
        if(n<days)
        {
            n=n+library_structure[x].t;
        }
        else
        {
            break;
        }
        
    }

    int64_t sum=0;
    x--;
    cout<<x<<endl;

    for(int64_t i=0;i<x;i++)
    {
        sum=sum+library_structure[i].t;
        
        if(days-sum <= 0)
            break; 
        
        cout << library_structure[i].index <<' ';
        
        if (library_structure[i].n>((days-sum)*library_structure[i].m) ){
            cout<<(days-sum)*library_structure[i].m<<endl;
            for(int64_t k=0;k<(days-sum)*library_structure[i].m;k++)
            {
                cout << library_structure[i].id_and_scores[k][0]<<' ';
            }
        
                cout<<endl;
        }
        else
        {
            cout<<library_structure[i].n <<endl;
            for(auto k: library_structure[i].id_and_scores)
                cout << k[0] << ' ';
                cout<<endl;
            /* code */
        }
            
        
    }

    
  


    return 0;
}