#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

vector<vector<int>> read_file(string name) {
    vector<vector<int>> data;

    ifstream fin;
    fin.open(name);

    while(fin) {
        vector<int> t;

        string line;
        getline(fin, line);
        
        for(string k: split(line, " ")){ 
            t.push_back(atoi(k.c_str()));
        }

    
        data.push_back(t);
    }

    return data;
}


int main() {
    string filename = "e_also_big.in";
    // cout << "Enter Input Filename: ";
    // cin >> filename;

    vector<vector<int>> data = read_file(filename);

    vector<int> a = data[1];
    int n = data[0][1];
    int max = data[0][0];
    
    int sum=0;
    int best=0;
    
    for(int i=n-1;i>=0;i--)
    {
        sum=0;
        for(int j=i;j>=0;j--)
        {
            if((sum+a[j])<=max)
            {
                sum=sum+a[j];
            }
        }
        if(best<sum)
        {
            best=sum;
        }
    }
    cout<<best;

    return 0;
}