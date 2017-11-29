#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main() {
	int times = 131; //how many things to insert
	string tableName = "Project"; //name of table
	int id = 9000;
	int numOfLeaders = 35;
	vector<string> list;

	ofstream outfile("newMiscSQLInsertsProject.sql");
	ofstream ouzfile("newMiscSQLInsertsProjectInterest.sql");
	if (outfile.is_open()){
		for (int i = 0; i < list.size(); i++) {
			outfile << endl << "insert into " << tableName << endl;
			outfile << "  values (" ;
			//List things to be inserted here

			outfile << id++ << ", '" << list[i]<<"', "<<(rand()%612)+1000<<", "<<(rand()%25)+3000;
			int randNum = rand() % 6;
			ouzfile << endl << "insert into ProjectInterest" << endl << "  values(";
			ouzfile << id - 1 << ", " << (rand() % 19) + 4000 << ");";
			if (randNum > 3) {
				ouzfile << endl << "insert into ProjectInterest" << endl << "  values(";
				ouzfile << id - 1 << ", " << (rand() % 19) + 4000 << ");";
			}
			//Close
			outfile << ");" << endl;

		}

	}
	outfile.close();
	ouzfile.close();

}