#include <iostream>
#include <string.h>
#include <fstream>
#include<time.h>


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



int main()
{
    unsigned int noRecords=0;
    int recordSize=0;
    cout<<"Enter the number of records:";
    cin>>noRecords;
    cout<<"Enter the record size:";
    cin>>recordSize;
    record R;
    
    ofstream out("DataFile",ios::binary);
    R=record(0,recordSize-4);
    
    for(int i=0;i<noRecords;i++)
    {
          R.usn=i;
         out.write((char*) &R.usn,4);
         out.write((char*) R.name, recordSize-4);
         if((i%100) == 0)
         out.flush();
    }
    cout<<"last one:"<<R.usn<<endl;
   	out.close();    
}

