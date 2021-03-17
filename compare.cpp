#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
                string myText;
        string myText1;
//      int count=0;
        ifstream MyReadFile("sample.txt");
        ifstream MyReadFile1("sample1.txt");
        ofstream MyFile("diff.txt");
        while (getline(MyReadFile, myText) && getline(MyReadFile1, myText1)) {
                vector<string> token;
                vector <string> tokens;
                stringstream check(myText);
                stringstream check1(myText1);
                string inter;
                string intermid;

                int i=0;
              while (  getline(check, inter, ',') && getline(check1, intermid, ',') )
                        {
                        token.push_back(inter);
                        tokens.push_back(intermid);
        //      cout<<i<<" "<<token[i]<<" "<<tokens[i]<<endl;
                if(i!=0 && i!=3){
                if(token==tokens){
//                              count++;
                        }else{

                                MyFile<<"\nFirst file ";
                                MyFile<<token[i];
                                MyFile<<"\nSecond file ";
                                MyFile<<tokens[i];
                        }
                 }
                                i++;
                        }
        }
//      cout<<count;
        MyFile.close();
        return 0;
}
