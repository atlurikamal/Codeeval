#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <sstream>
using namespace std;

bool os(double xi, double yi, double xj, double yj, double xk, double yk) {// To check whether they //are on the segment or not.
  return (xi <= xk || xj <= xk) && (xk <= xi || xk <= xj) &&
         (yi <= yk || yj <= yk) && (yk <= yi || yk <= yj);
}


char cd(double xi, double yi, double xj, double yj,double xk, double yk) { //To check the direction
  double a = (xk - xi) * (yj - yi);
  double b = (xj - xi) * (yk - yi);
  return a < b ? -1 : a > b ? 1 : 0;
}

int ci(double *b1, double *b2) { //Function to check the intersection.
  char d1 = cd(b2[0], b2[1], b2[2], b2[3], b1[0], b1[1]);
  char d2 = cd(b2[0], b2[1], b2[2], b2[3], b1[2], b1[3]);
  char d3 = cd(b1[0], b1[1], b1[2], b1[3], b2[0], b2[1]);
  char d4 = cd(b1[0], b1[1], b1[2], b1[3], b2[2], b2[3]);
  if ((((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
          ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) ||
         (d1 == 0 && os(b2[0], b2[1], b2[2], b2[3], b1[0], b1[1])) ||
         (d2 == 0 && os(b2[0], b2[1], b2[2], b2[3], b1[2], b1[3])) ||
         (d3 == 0 && os(b1[0], b1[1], b1[2], b1[3], b2[0], b2[1])) ||
         (d4 == 0 && os(b1[0], b1[1], b1[2], b1[3], b2[2], b2[3])))
         return 1;
         else 
         return 0;
}


int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line,cline= { };
     char * cstr;
    while (getline(stream, line)) {
        cline+=line; //Taking input and concatenating to a single string.
            }
           cstr  = new char [cline.length()+1];
             strcpy (cstr, cline.c_str());
             
             	char *token = strtok(cstr, "[](),: ");

     string cpoint[100];
     int i;

	while (token != NULL)
	{
		cpoint[i++] = token;
		token = strtok(NULL, "[](),: ");
	}
int n=i,j;
double point[100];
for(i=0;i<n;i++)
{
    	stringstream geek(cpoint[i]);
    	geek >> point[i];
    
}


double bridges[15][4]; //Making points out of the given values.
for(i=0;i<(n/5);i++)
{
    bridges[i][0]=point[(i*5)+1];
    bridges[i][1]=point[(i*5)+2];
    bridges[i][2]=point[(i*5)+3];
    bridges[i][3]=point[(i*5)+4];
}

int cross [15][15]={ };
int p;
 for (i = 0; i<(n/5) ; i++)
 {
    p=0;
    for (j = 0; (j<(n/5)); j++)
    { 
        if (ci(&bridges[i][0], &bridges[j][0]))
        {
            if(i!=j) //Checking whether a given points intersect or not. 
            cross[i][p++]=j+1; //If so saving its number to track which all bridges do intersect.
        }
    }
}

int safety[15];

for(i=0;i<15;i++)
{
    j=0;
    while(cross[i][j] != 0)
    j++;
    
    safety[i]=j; // It has the safety values of each bridge.
}
int snb=0;
int safebridge[15]; // It has all the list of safest bridges which does not intersect with any of the //other bridges

for(i=0;i<15;i++)
if(safety[i]==0)
safebridge[snb++]=i+1;



int dup[15];
for(i=0;i<15;i++)
{
dup[i]=safety[i];
}


int swap;
for (i= 0 ; i< ( 15 - 1 ); i++)
  {
    for (j = 0 ; j < (15 - i - 1); j++)
    {
      if (dup[j] > dup[j+1]) //Sorting the safety of bridges in ascending order.
      {
        swap       = dup[j];
        dup[j]   = dup[j+1];
        dup[j+1] = swap;
      }
    }
  } 
int k,flag,counter;
for(i=0;i<15;i++)
{
    flag =0;
    if(dup[i]!=0)
    {
        for(p=0;p<15;p++)
        {
            if( dup[i] == safety[p] )
            {
              safety[p]=0;
              counter=p; 
            break;
            }
        }
        for(j=0;j<dup[i];j++)
        {
            for(k=0;k<snb;k++){
                if(safebridge[k]==cross[counter][j])
                {
                    flag=1;
                }
            }
        }
        if( flag == 0 ) //If flag is 0,  the bridges does not intersect with already considered bridges.
        {
            safebridge[snb++]= p+1;
        }
        
    }
}

for (i= 0 ; i< ( snb - 1 ); i++)
  {
    for (j = 0 ; j < (snb - i - 1); j++)
    {
      if (safebridge[j] > safebridge[j+1]) 
      { //Sorting the Final selected bridges.
        swap       = safebridge[j];
        safebridge[j]   = safebridge[j+1];
        safebridge[j+1] = swap;
      }
    }
  } 

for(i=0;i<snb;i++)
{
    printf("%d\n",safebridge[i]);
}
   return 0;
}