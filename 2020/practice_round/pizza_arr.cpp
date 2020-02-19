#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main() {
    string filename = "e_also_big.in";
    int n;
    int max;
    
    
    ifstream fin;
    fin.open(filename);

    int first_line_arr[2] = {0,0};
    
    string line;
    getline(fin, line);
    
    int k=0;
    for(char i: line){
        if(i == ' '){
            k++;
            continue;
        }
        else {
            first_line_arr[k] = first_line_arr[k]*10 + (int) i-'0';
        }

    }
    
    int a[first_line_arr[1]];
    
    getline(fin, line);    
    k=0;
    a[k] = 0;

    for(char i: line){
        if(i == ' '){
            k++;
            a[k] = 0;
            continue;
        }
        else {
            a[k] = a[k]*10 + (int) i-'0';
        }

    }

    fin.close();
    
    max = first_line_arr[0];
    n = first_line_arr[1];

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