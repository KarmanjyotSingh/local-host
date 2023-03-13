#include <bits/stdc++.h>
using namespace std;

//  read csv file and store in vector
long long int idx = 1;
int rowpixel = 309, colpixel = 474;
void f()
{
    ifstream file("data.csv");
    string line;
    vector<vector<long long int>> data;
    vector<long long int> row;
    map<vector<int>,long long int>m;
    int rowc= 0;
    while (getline(file, line))
    {
        rowc++;
        vector<int>rgb;
        stringstream ss(line);
        string word;
        while (getline(ss, word, ','))
        {
            //  convert word to int
            int x = stoi(word);
            rgb.push_back(x);
        }
        if(m[rgb]== 0){
            m[rgb] = idx;
            idx++;
        }
        row.push_back(m[rgb]);
        if(rowc == rowpixel){
            data.push_back(row);
            rowc = 0;
        row.clear();
        }
    }
    //  write to csv file
    ofstream myfile;
    myfile.open("output.csv");
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            myfile << data[i][j] << ",";
        }
        myfile << endl;
    }
    myfile.close();
    ofstream color;
    color.open("color.csv");
    color<<"Index,Red,Green,Blue"<<endl;
    for(auto i:m){
        color<<i.second<<","<<i.first[0]<<","<<i.first[1]<<","<<i.first[2]<<endl;
    }
    color.close();
}


int main()
{
    f();
    return 0;
}