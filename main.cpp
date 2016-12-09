#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

char easytolower(char in){
	if(in<='Z' && in>='A'){
		return in-('Z'-'z');
	}
	return in;
}

string getEmail(string firstName, lastName){
	int randomNumber=55;
	vector<string> emailEndings;
	
}

int main(){
	srand (time.(NULL));
	int randomNumber=rand()%10+1;//1-10
	ifstream lastnamefile("dist.all.last");
	vector <string> lastnames;
	while(!lastnamefile.eof()){
		string hold;
		lastnamefile>>hold;
		getline(lastnamefile,hold,' ');
		for (int b=1;b<hold.length();b++){
			hold[b]=easytolower(hold[b]);
		}
		lastnames.push_back(hold);
		getline(lastnamefile,hold,'\n');
	}
	
	string firstName;
	string lastName;
	int i=1;
	int people;
	cout<<"How many customers are we generating?";
	cin>>people;
	ofstream outfile("customers.txt");
	if (outfile.is_open()){
		while (i<people){
			outfile<<"insert into customer\nvalues ("<<i<<", '"<<firstName<<" "<<lastName<<"', '";
			for (int j=0;j<7;j++){
				outfile<<randomNumber;
				if (j==3){cout<<"-";}
			}
			outfile<<"', ";
			if (randNumber<.3){
				outfile<<"null";
			}
			else{
				outfile<<"'"<<getEmail(firstName,lastName)<<"'";
			}
			cout<<", 100, 1000);\n";
			i++;
		}
	}
	else{cout<<"file can't be opened";}
}
