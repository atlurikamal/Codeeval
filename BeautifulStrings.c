#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    int i, j, p,q, t, k=0, d, len,swap=0, c[21][26] = { },temp[26],s[20]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    string a;
    while (getline(stream, a)) {

       c[21][26] = { };
       len = 0;
        printf("\n");
        do
        {
            len++;
        }while( a[len]!= NULL);

            for(i=0; i<26;i++)
        {
            for(j=0; j < len; j++)
            {
                if( a[j]== (65+i) || a[j]==(97+i))
                {
                    c[k][i]++;
                }
            }
		}

     k++;

    }
    printf("\n\n");
    p=k;
    t=0;

for(i=0;i<k;i++)
{
    
    swap=0;
  for(j=0;j<26;j++)
  {
      temp[j]=c[i][j];
  }
  for (j = 0 ; j < ( 26 - 1 ); j++)
  {
    for (q = 0 ; q < (26 - j - 1); q++)
    {
      if (temp[q] > temp[q+1]) 
      {
        swap       = temp[q];
        temp[q]   = temp[q+1];
        temp[q+1] = swap;
      }
    }
  } 
  len=26;
  for(j=25;j>=0;j--)
       {
           s[i]+=temp[j]*len--;
       }
    printf("%d \n",s[i]-1);   
}

    return 0;
}
