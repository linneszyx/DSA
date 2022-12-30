#include<bits/stdc++.h>
using namespace std;
void findSubsets(char *input,char *output,int i,int j){
//base case

if(input[i]=='\0') {
	output[j]='\0';
	if(output[0]=='\0'){
		cout<<"[]";
	}
	cout<<"["<<output<<"]"<<",";
	return;
}
//recursive case
//Include the ith letter
output[j]=input[i];
findSubsets(input,output,i+1,j+1);
//Exclusive the ith letter
//Overwriting
findSubsets(input,output,i+1,j);

}
int main(){
char input[100];
char output[100];
cin>>input;    
findSubsets(input,output,0,0);
return 0;
}
