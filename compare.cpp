#include<stdio.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<bits/stdc++.h>
#include<ostream>
#include<stdlib.h>
using namespace std;
int main(){
        string myText;
        string myText1,FirstFile,SecondFile,output;
        int j=0;
        int count=0;
        cout<<"Enter first file name\n";
        cin>>FirstFile;
        cout<<"Enter second file name\n";
        cin>>SecondFile;
        cout<<"Enter output file name\n";
        cin>>output;
        ifstream MyReadFile(FirstFile.c_str());
        ifstream MyReadFile1(SecondFile.c_str());
        ofstream ob(output.c_str());
        while (1){
                getline(MyReadFile1, myText1);
                getline(MyReadFile, myText);
                vector<string> token;
                vector <string> tokens;
                stringstream check(myText);
                stringstream check1(myText1);
                string inter;
                string intermid;
                j++;
                if(MyReadFile.eof() && MyReadFile1.eof()){
                        break;

                }
                if(MyReadFile.eof()){
                                ob <<"\nRemaining line of  Second File:\n";
                                ob <<myText1;
                                continue;

                }
                if(MyReadFile1.eof()){
                                ob <<"\nRemaining line of First File:\n";
                                ob <<myText;
                                continue;

                }
                if(j==1 || j==2)//to skip first two line of files
                        continue;
                int i=0;
                while (getline(check, inter, ',') && getline(check1, intermid, ',') )
                        {
                        if(i!=0 && i!=3){//to skip 1st and 4th column of a line
                                token.push_back(inter);
                                tokens.push_back(intermid);

                        }
                        i++;
                }

                if(token.size()==0){//to check blank line
                        cout<<j;
                        break;
                }

                stringstream geek(token[0]);
                int x=0;
                geek>>x;
                stringstream geek1(tokens[0]);
                int y=0;
                geek1>>y;

                if(j-2!=x || j-2!=y){//to check sequence number mismatch
                        ob<<"\nsequence mismatched at -> ";
                        ob<<j-2;
                        ob<<"th line";
                        break;
                }
                if((token[1]=="N" || token[1]=="M" ||token[1]=="X" ||token[1]=="T")&& (tokens[1]=="N" || tokens[1]=="M" ||tokens[1]=="X" ||tokens[1]=="T")){
                        if(token==tokens){
                        }else{
                                ob <<"Mismatch line of First File:\n";
                                ob <<myText;
                                ob <<"\nMismatch line of Second File:\n";
                                ob <<myText1;

                        }
                 }
        }
        ob.close();
        return 0;
}

