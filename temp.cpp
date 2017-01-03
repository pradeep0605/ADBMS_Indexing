#include<iostream>
#include<unistd.h>
#include<fstream>


using namespace std;

int main()
{
  ifstream in("DataFile",ios::binary);

      int i;
      in.seekg(-16,ios::end);
      in.read((char*) &i,4);
      cout<<i<<endl;
  return 0;

}
