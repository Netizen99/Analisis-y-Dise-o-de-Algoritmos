#include <iostream>
using namespace std;

int gVect[100]; // Buffer to save the elementsint gnCount; 
int gnCount; 

void Insert(int elem){
  if( gnCount < 100 )          // we can only insert if there is 
  gVect[gnCount++] = elem;
  }

int main() {
  for(int i=0;i<100;i++)
    {
      Insert(i);
      cout<<" " <<i;
    }
}

