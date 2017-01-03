#include <iostream>
#include <string.h>
#include <fstream>
#include<time.h>
#include "string.cpp"


using namespace std;
class record
{
     public:
     int  usn;
     char *name;

     record()
     {
        usn=0;
        name=NULL;
     }
     record(int u, int size)
     {
        usn=u; name=new char[ size ];
     }     
};



int main(int argc, char **argv)
{
    unsigned int noRecords=0,susn;
    int recordSize=0;

    record R;
    String s;
    s.str=argv[1];
    
    noRecords=201326592;
    recordSize=16;
    susn=s;
     
    R.name=new char[recordSize];
   
   ifstream in("DataFile",ios::binary);
   
    for(int i=1;i<=noRecords;i++)
    {
       in.read((char*)&R.usn,4);
       in.read((char*)R.name,recordSize-4);
       if(R.usn==susn)
       {
            cout<<R.usn<<endl;       
             break;     
       }     
    }     
       in.close();  
}
