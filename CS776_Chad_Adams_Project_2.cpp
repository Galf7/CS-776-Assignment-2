#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

double eval(int *key);
void modify(int *key,int size,int start,int end);

int main()
{
  int size = 150;
  int key[size];
  double fit = 0;
  double nfit = 0;
  int start = 0;
  int end = 0;
  int iter = 0;

  srand(time(NULL));//initialize random seed
  for(iter = 0; iter < size; iter++)
  {
    key[iter] = rand() % 2;
  }
  
  iter = 0;
  fit = eval(key);
  cout << "starting fitness = " << fit << endl;
  
  while(iter < 50000)
  {
    start = rand() % size;
    end = start + (rand() % (size-start));
    
    modify(key,size,start,end);
        
    nfit = eval(key);
    
    if(nfit >= fit)
    {
      fit = nfit;
    }
    else
    {
      modify(key,size,start,end);
    }
    iter++;
  }
  
  cout << endl << "ending fitness = " << fit << endl << "ending key: ";
  for(iter = 0;iter < size-1;iter++)
  {
    cout << key[iter] << ",";
  }
  cout << key[iter] << endl;
  
  return 0;
}

void modify(int *key,int size,int start,int end)
{
  for(int iter = start;iter < end;iter++)
  {
    key[iter] = 1 - key[iter];
  }
}
