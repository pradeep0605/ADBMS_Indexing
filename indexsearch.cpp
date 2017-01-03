#include<iostream>
#include<fstream>
#include "string.cpp"

using namespace std;


int main(int argc, char**argv)
{
    String s=argv[1];
    unsigned int usn=s;    
    ifstream in3("3.index",ios::binary);
    ifstream in2("2.index",ios::binary);
    ifstream in1("1.index",ios::binary);
    ifstream in("DataFile",ios::binary);    
    
    unsigned int tempusn;
    unsigned int seekLength=0;
    unsigned int fileSize=0;
    in3.seekg(0,ios::end);
    fileSize=in3.tellg();
    in3.seekg(0,ios::beg);
    do         
    {          
        in3.read((char*)&tempusn,4);
        in3.read((char*)&seekLength,4);
    }while(tempusn<usn && !in3.eof());
    
    if(tempusn  > usn )
    {      
        in3.seekg(-16,ios::cur);	
        in3.read((char*)&tempusn,4);
        in3.read((char*)&seekLength,4);
        if(tempusn==0)
        seekLength=0;
    }      
    cout<<"AFter third level index:\n";
    cout<<tempusn<<"\t"<<seekLength<<endl<<endl;
    cout.flush();
       
    if(seekLength!=0)
      in2.seekg(seekLength-1024,ios::beg);
    else
       in.seekg(seekLength,ios::beg);      

    do
    {
       in2.read((char*)&tempusn,4);
       in2.read((char*) &seekLength,4);
    }while(tempusn<usn && !in2.eof());
    if(tempusn>usn)
    {
        in2.seekg(-16,ios::cur);
        in2.read((char*)&tempusn,4);
        in2.read((char*)&seekLength,4);
        if(tempusn==0)
        seekLength=0;
    }

    cout<<"AFter second level index:\n";
    cout<<tempusn<<"\t"<<seekLength<<endl<<endl;
    cout.flush();
    
    if(seekLength!=0)
    in1.seekg(seekLength-1024,ios::beg);
        else
    in.seekg(seekLength,ios::beg);      

    do
    {
       in1.read((char*)&tempusn,4);
       in1.read((char*) &seekLength,4);
    }while(tempusn<usn && !in1.eof());
    if(tempusn>usn)
    {
        in1.seekg(-16,ios::cur);
        in1.read((char*)&tempusn,4);
        in1.read((char*)&seekLength,4);
        if(tempusn==0)
           seekLength=0;
    }
    cout<<"AFter FIRST level index:\n";
    cout<<tempusn<<"\t"<<seekLength<<endl<<endl;
    cout.flush();
    if(seekLength!=0)
      in.seekg(seekLength-1024,ios::beg);
    else
      in.seekg(seekLength,ios::beg);      
    do
    {
       in.read((char*)&tempusn,4);
       in.seekg(12,ios::cur);
     }while(tempusn!=usn && !in.eof());
    
    if(in.eof())
    {
       cout<<"NOT FOUND\n";
       return 0;
    }    
    cout<<tempusn<<"\t"<<seekLength<<endl;
    cout<<"AFter DataFile level index:\n";
    cout.flush();
    
    cout<<"\n***********************FOUND***********************\n";
    return 0;
}










