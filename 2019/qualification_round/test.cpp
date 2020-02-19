#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(const string& s, char delimiter) {
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

int main(){

    vector<string> f = split("My name is Junaid", ' ');
    f.erase(f.begin(), f.begin()+2);

    for(string k: f)
        cout << k << endl;

    return 0;
}