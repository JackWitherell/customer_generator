#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

char easytolower(char in) {
	if (in <= 'Z' && in >= 'A') {
		return in - ('Z' - 'z');
	}
	return in;
}

string getEmail(string firstName, string lastName, vector<string> emailEndings, vector<string> dictionary) {
	string email = "4";
	string last = lastName;
	string firstl = " ";
	string randword = "0";
	switch (rand() % 10) {
	case 0:                                        //ONE CASE  = FirstnameLastname
		email = firstName;
		email.append(lastName);
		break;
	case 1:                                        //TWO CASES = firstnamelastname
	case 2:
		email = firstName;
		email[0] = easytolower(email[0]);

		lastName[0] = easytolower(lastName[0]);
		email.append(last);
		break;
	case 3:                                        //ONE CASE  - f.lastname
		email = firstName;
		email = easytolower(email[0]);
		email.append(".");
		lastName[0] = easytolower(lastName[0]);
		email.append(last);
		break;
	case 4: 
	case 5:
		email = firstName;
		email = easytolower(email[0]);
		email.append(".");
		lastName[0] = easytolower(lastName[0]);
		email.append(last);
		last = rand() % 30 + 69;
		email.append(last);
		break;
	case 6:
	case 7:
		while (easytolower(randword[0]) != easytolower(lastName[0])) {
			randword = dictionary[rand() % dictionary.size()];
		}
		email = firstName;
		email.append(randword);
		break;
	case 8:
		while (easytolower(randword[0]) != easytolower(firstName[0])) {
			randword = dictionary[rand() % dictionary.size()];
		}
		email = randword;
		email.append(lastName);
		break;
	case 9:
		while (easytolower(randword[0]) != easytolower(firstName[0])) {
			randword = dictionary[rand() % dictionary.size()];
		}
		email = randword;
		while (easytolower(randword[0]) != easytolower(lastName[0])) {
			randword = dictionary[rand() % dictionary.size()];
		}
		email.append(randword);
		last = rand() % 30 + 69;
		email.append(last);
		break;
	}
	email.append("@");
	email.append(emailEndings[rand() % emailEndings.size()]);
	return email;

}

int main() {
	srand(time(NULL));
	int randomNumber = 55;
	ifstream lastnamefile("dist.all.last");
	vector <string> lastnames;
	while (!lastnamefile.eof()) {
		string hold;
		getline(lastnamefile, hold, ' ');
		for (int b = 1; b<hold.length(); b++) {
			hold[b] = easytolower(hold[b]);
		}
		lastnames.push_back(hold);
		getline(lastnamefile, hold, '\n');
	}
	lastnamefile.close();

	ifstream firstnamefemfile("dist.all.last");
	vector <string> firstnamefems;
	while (!firstnamefemfile.eof()) {
		string hold;
		getline(firstnamefemfile, hold, ' ');
		for (int b = 1; b<hold.length(); b++) {
			hold[b] = easytolower(hold[b]);
		}
		firstnamefems.push_back(hold);
		getline(firstnamefemfile, hold, '\n');
	}
	firstnamefemfile.close();

	ifstream firstnamemenfile("dist.all.last");
	vector <string> firstnamemens;
	while (!firstnamemenfile.eof()) {
		string hold;
		getline(firstnamemenfile, hold, ' ');
		for (int b = 1; b<hold.length(); b++) {
			hold[b] = easytolower(hold[b]);
		}
		firstnamemens.push_back(hold);
		getline(firstnamemenfile, hold, '\n');
	}
	firstnamemenfile.close();

	ifstream emails("email.list");
	vector<string> emailEndings;
	while (!emails.eof()) {
		string hold;
		getline(emails, hold, '\n');
		emailEndings.push_back(hold);
	}
	emails.close();

	ifstream dictwords("american-english");
	vector <string> dictionary;
	while (!dictwords.eof()) {
		string hold;
		getline(dictwords, hold, '\n');
		for (int b = 1; b<hold.length(); b++) {
			hold[b] = easytolower(hold[b]);
		}
		if (hold.length()>2) {
			if (hold[hold.length() - 2] != '\'') {
				dictionary.push_back(hold);
			}
		}
	}
	dictwords.close();

	string firstName = "Jason";
	string lastName = "Bourne";
	int people;
	cout << "How many customers are we generating? ";
	cin >> people;
	vector<string> months;
	months.push_back("JAN");
	months.push_back("FEB");
	months.push_back("MAR");
	months.push_back("APR");
	months.push_back("MAY");
	months.push_back("JUN");
	months.push_back("JUL");
	months.push_back("AUG");
	months.push_back("SEP");
	months.push_back("OCT");
	months.push_back("NOV");
	months.push_back("DEC");
	int leadernum = 2000;
	ofstream outfile("newDescSQLInsertsMember.sql");
	ofstream ouffile("newDescSQLInsertsEmail.sql");
	ofstream ougfile("newDescSQLInsertsMemberInterest.sql");
	ofstream ounfile("newDescSQLDefineIndividual.sql");
	ofstream oudfile("newDescSQLDefineManagement.sql");
	if (outfile.is_open()) {
		int i = 1;
		while (i<people) {
			lastName = lastnames[rand() % lastnames.size()];
			if ((rand() % 2) == 1) {
				firstName = firstnamemens[rand() % firstnamemens.size()];
			}
			else {
				firstName = firstnamefems[rand() % firstnamefems.size()];
			}
			outfile << "insert into Member"<<endl<<"  values (" << i+999 << ", '" << firstName << "', '" << lastName << "', ";
			/*for (int j = 0; j<7; j++) {
				outfile << rand() % 10;
				if (j == 2) {
					outfile << "-";
				}
			}
			outfile << "', ";
			randomNumber = rand() % 3;
			if (randomNumber == 1) {
				outfile << "null";
			}
			else {
				outfile << "'" << getEmail(firstName, lastName, emailEndings, dictionary) << "'";
			}
			randomNumber = rand() % 100001;
			outfile << ", " << rand() % (randomNumber + 1) << ", " << randomNumber << ");\n";
			*/
			randomNumber = (rand() % 6);
			if(randomNumber!=0){
				ouffile << endl<<"insert into MemberEmail" << endl << "  values (";
				string email = getEmail(firstName, lastName, emailEndings, dictionary);
				ouffile << i + 999 << ", '" << email << "');";
				if (randomNumber == 4) {
					string tempemail = getEmail(firstName, lastName, emailEndings, dictionary);
					if (tempemail != email) {
						ouffile <<endl <<"insert into MemberEmail" << endl << "  values (";
						ouffile << i + 999 << ", '" << tempemail << "');";
					}
				}

			}
			randomNumber = (rand() % 6);
			
			ougfile << endl << "insert into MemberInterest" << endl << "  values (";
			int aa = (rand() % 19) + 4000;
			ougfile << i + 999 << ", " << aa << ");";
			if (randomNumber == 4) {
				int bb = (rand()%19)+4000;
				if (aa != bb) {
					ougfile << endl << "insert into MemberEmail" << endl << "  values (";
					ougfile << i + 999 << ", " << bb << ");";
				}
			}
			randomNumber = rand() % 20;
			if (randomNumber != 0) {
				ounfile << endl << "insert into Individual" << endl << "  values(";
				ounfile << i + 999 << ", " << (280<(rand() % 288)?1:0) << ", " << (rand() % 13)+6000 << ");";
			}
			else {
				oudfile << endl << "insert into Management" << endl << "  values(";
				oudfile << leadernum++ << ", " << i + 999 << ");";
			}


			randomNumber = (rand() % 28) + 1;
			outfile << "'" << (randomNumber < 10 ? "0" : "") << randomNumber << "-" << months[(rand() % 12)] << "-" << (rand() % 100) + 1910 << "');"<<endl;
			i++;
		}
	}
	else { cout << "file can't be opened"; }
	outfile.close();
	ouffile.close();
	ougfile.close();
	cin.get();
	cin.get();
}
