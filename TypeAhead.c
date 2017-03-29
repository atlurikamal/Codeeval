#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <sstream>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line,num[40],data[40];
    int i=0,j;
    while (getline(stream, line)) { 
        j=i;
        i++;
        num[j]= line.substr(0,1); //Splitting the number from the input and storing it in a different array
        data[j]= line.substr(2); //Splitting the strings from the input and storing them in a different //array.
    }
    
    int number[40];
for(i=0;i<40;i++) // Converting the Num(string type) to number type
{
    	stringstream geek(num[i]);
    	geek >> number[i];
}
    
    string msg[100];
char str[] ="Mary had a little lamb its fleece was white as snow And everywhere that Mary went the lamb was sure to go It followed her to school one day which was against the rule It made the children laugh and play to see a lamb at school And so the teacher turned it out but still it lingered near And waited patiently about till Mary did appear Why does the lamb love Mary so the eager children cry Why Mary loves the lamb you know the teacher did reply"; //content

  char * pch;
  i=0;
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
      msg[i++]=pch;
    pch = strtok (NULL, " ,.-");
  } //Removing all the spaces and storing each string separately in an array.

  int count =i;
  
        for(i=0;i<40;i++){ //Running the loop for 40 times as there are 40 different inputs.
            
  int p=0,k;
  string temp;
  int stringcount=0;
            
        string arr[30];
        int rep[30]={ };
        for(j=0;j<(count-number[i]+2);j++){ //Running the loop for searching the string. The num-2 is //because,we have to check the searching string with the all possible combinations. 
            string search={ };
        for(k=0;k<(number[i]-1);k++){ //The possible string are generated.
            search=search+msg[j+k];
            if(k!=number[i]-2)
            search = search + " ";
        }
        if(search.compare(data[i])==0){ //The strings are compared and if they string count is //incremented.
            temp=msg[j+k];
            stringcount++;
        int flag =1,place;
        if(p==0){ // If it is the first time the string is found , the next word is stored directly.
        arr[p]=temp; 
        rep[p]++;
        p++;
        } else
        {
         for(int l=0;l<p;l++)
         { //If not, the word is searched in the array and it is incremented. 
             flag =1;
            if(temp.compare(arr[l])==0){
                rep[l]++;
                break;
            }else{
                flag=0;
            }
         }

         if(flag==0) // if not found, the word is added to the string.
         {
             arr[p]=temp;
             rep[p]++;
             p++;
         }
         }
        }
        }   
        for (k= 0 ; k< ( p - 1 ); k++) //The array’s  are sorted depending upon their frequencyin the //decreasing order.
  {
          int swapi;
            string swaps;
    for (int q = 0 ; q < (p - k - 1); q++)
    {
      if (rep[q] < rep[q+1]) 
      {
        swapi       = rep[q]; swaps = arr[q];
        rep[q]   = rep[q+1]; arr[q] = arr[q+1];
        rep[q+1] = swapi; arr[q+1] = swaps;
      }
    }
  }
        for(k=0;k<p;k++){
            double x = static_cast<double>(rep[k])/stringcount; //Finally they are printed.
             std::cout<<arr[k]<<",";
             printf("%.3lf",x);
             if(k<p-1)
             printf(";");
        }cout<<endl;
        }
    return 0;
}
