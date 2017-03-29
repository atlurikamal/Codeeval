#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line,num[20],data[20];
    int i=0,j;
    while (getline(stream, line)) {
        j=i;
        i++;
        std::size_t pos = line.find(";");
        num[j]= line.substr(0,pos);  // We split them into two different arrays.
        data[j]= line.substr(pos+1);
    }
    
    
int number[25];
for(i=0;i<20;i++)
{ // Converting them into integers.
    	stringstream geek(num[i]);
    	geek >> number[i];
}
char *cstr;
int dn[20][100] = { },len[20];
string cpoint[100];
int p,q=0;
for(i=0;i<20;i++)
{
    p=0;
    q=0;
 cstr  = new char [data[i].length()+1];
 strcpy (cstr, data[i].c_str());
 char *token = strtok(cstr, " ");
while (token != NULL)
	{
		cpoint[p++] = token;
		token = strtok(NULL, " ");
	}
	int d;
	for(d=0;d<p;d++)
	{
	    q++;
	    stringstream geek(cpoint[d]);
    	geek >> dn[i][d];
	}
	len[i]=q;
}
int sum=0,ans=0,k,l;
for(i=0;i<20;i++){ //For 20 inputs, we run 20 iterations.
    ans=0; //For every new sample the ans is set to 0.
    for(j=0;j<len[i];j++){
        for(k=0;k<(len[i]-number[i]+1);k++){
            sum=0;
            for(l=0;l<number[i];l++){
            sum=dn[i][k+l]+sum;
            }
            if(sum>=ans){ //If the local sum is greater than the ans then the value is stored in the ans.
            ans=sum;
            }
        }
    }
    printf("%d\n",ans); // Finally we print the answer.
}
    return 0;
}
