#include<iostream>
#include<fstream>
#include "string.cpp"

using namespace std;


int main(int argc, char**argv)
{
    String s=argv[1];
    int i=s; 
    ifstream in("DataFile",ios::binary);
    while(!in.eof())
    {
       unsigned int temp;
       in.read((char*)&temp,4);
       in.seekg(12,ios::cur);
       if(temp==i)
       {
          cout<<"FOUND\n";
          break;
       }   
    }
    return 0;
}










