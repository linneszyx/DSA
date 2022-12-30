#include<bits/stdc++.h>
using namespace std;
bool compare(string a,string b){
	if(a.length()==b.length()){
		return a<b; //lexicographically
	}
	return a.length()<b.length();
}
void findSubsets(char *input,char *output,int i,int j,vector<string> &ls){
//base case

if(input[i]=='\0') {
	output[j]='\0';
	string temp(output);
	ls.push_back(temp);
	return ;
}
//recursive case
//Include the ith letter
output[j]=input[i];
findSubsets(input,output,i+1,j+1,ls);
//Exclusive the ith letter
//Overwriting
findSubsets(input,output,i+1,j,ls);
}

int main(){
char input[100];
char output[100];
vector<string> ls;
cin>>input;    
findSubsets(input,output,0,0,ls);
sort(ls.begin(),ls.end(),compare);
for(auto x : ls) {
	cout<<x<<",";
}
return 0;
}
