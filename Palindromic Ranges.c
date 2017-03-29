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
    string line, l[20],r[20];
    int i=0,j,pos;
    while (getline(stream, line)) { //Reading the file line by line.
      // cout<<line<<endl;
        
           j=i;
        i++;
        pos = line.find(" "); // Separating the values.
        l[j]= line.substr(0,pos);
        r[j]= line.substr(pos+1);
    }
    
  /*  for(i=0;i<20;i++){
        cout<<l[i]<<"----"<<r[i]<<endl;
    }*/
    
        int left[20],right[20];
for(i=0;i<20;i++)
{
      //  cout<<l[i];
    	stringstream geek(l[i]);
    	geek >> left[i]; // Converting the values into integer from strings.
    //	std::cout <<"--"<< left[i] << std::endl;
}

for(i=0;i<20;i++)
{
      //  cout<<r[i];
    	stringstream geek(r[i]);
    	geek >> right[i];
    	//std::cout <<"----" <<right[i] << std::endl;
}
int mat[20][50]={ 0 } ; // Defining the matrix
int size[20];
for(i=0;i<20;i++){
    size[i]=(right[i]-left[i])+1;
}
int num,k;
for(i=0;i<20;i++){
    num = left[i];
    for(j=0;j<size[i];j++){
        int temp=0;
        k = num ;
        while(k){  // Checking whether the number is palindrome or not.
            temp = temp * 10;
            temp = temp + (k % 10);
            k = k/10;
        }
        if(temp == num)
          mat[i][j] = 1;
       // cout<< mat[i][j] << " ";
            num++;
    }

    cout<<endl;
}
int flag=0;
for(i=0;i<20;i++){
    flag =0;
    for(j=0;j<size[i];j++){
        pos=0;
        for(k=j;k<size[i];k++){
            if(mat[i][k]==1)  //Checking whether the number is interesting palindrome //or not.
            pos++;
            
             if(pos%2==0)
        flag++;
        }
        
    }
    cout<<flag<<endl; //Printing the values.
}
    return 0;
} 
