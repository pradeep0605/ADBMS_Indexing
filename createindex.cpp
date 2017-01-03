#include<iostream>
#include<fstream>
#include "string.cpp"

using namespace std;



class indexEntry
{
     public:
     
     unsigned int usn;
     unsigned int pointer;
     
     indexEntry()
     {
        usn=pointer=0;
     }    
};


int main()
{
	   int i=1;
	   unsigned int indexSize=201326592;
	   String fileName=(char*)"DataFile";
           unsigned int fileSize=0;
	   while(indexSize>128)
	   {
	       cout<<"Index size:"<<indexSize<<endl;
	       unsigned int blockIncrement=0;
	       String s=String(5);
	       s=i;
	       ifstream in(fileName.str,ios::binary);
	       in.seekg(0,ios::end);
	       fileSize=in.tellg();
	       in.seekg(0,ios::beg);
	       cout<<"File size:"<<fileSize<<endl;
               strcat(s.str,".index");
	       ofstream out(s.str,ios::binary);
               unsigned int usn=0;
               unsigned int count=0;
               while(blockIncrement<=fileSize)
               {
		       in.read((char*)  &usn,4);
		       count++;
		       out.write((char*) &usn,4);
		       out.write((char*) &blockIncrement,4);
		       if(count%1000==0)
		         out.flush();
		       in.seekg(blockIncrement,ios::beg);
		       blockIncrement+=1024;
               }
               if(i==1)
               indexSize/=64;
               else
                indexSize/=128;
               strcpy(fileName.str,s.str);
               i++;
               cout<<"Number of index entries:"<<count<<endl<<endl<<endl;
	   }
}

