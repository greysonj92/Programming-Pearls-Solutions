#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include<time.h>

using namespace std;


 //supposed to generate 30 random bits, as opposed to the 15 that rand() generates
 unsigned long bigrand() {
	 

	 //generates empty array of size 30
	 int number[30];
	 for (int i = 0; i < 30; i++) {
		 number[i] = 0;
	 }

	 //calls rand(), if less than half of rand max value bit stays 0, if greater, bit goes to 1
	 for (int i = 0; i < 30; i++) {
		 if (rand() > 16383) number[i] = 1;
	 }

	 //converts the array of bits into an unsigned int
	 unsigned long bin=0;
	 int multiplier = 1;
	 for (int i = 29; i >= 0; --i) {
		 bin += (multiplier * number[i]);
		 multiplier *= 2;


	 }
	 return bin;
 }

 //code from book, modified to output numbers to text file instead of cout
 void gensets(int m, int n, ofstream &inputfile) {
	 set<int> S;
	 while (S.size() < m)
		 S.insert(bigrand() % n);
	 set<int>::iterator i;
	 for (i = S.begin(); i != S.end(); i++)
		 inputfile << *i << "\n";
 }

 //takes an array initialized as zeros as input, performs a bitmap sort, returns the array
 void bitmapsort(int &input) {

 }

int main() {
	
	//generates the list of random numbers and writes them to a file
	srand(time(NULL));
	ofstream outputfile;
	outputfile.open("Sortedlist.txt");
	cout << "Enter the amount of random integers you want:";
	int numberofintegers;
	cin >> numberofintegers;
	cout << "Enter the top value of the random integers:";
	int topvalue;
	cin >> topvalue;
	gensets(numberofintegers, topvalue, outputfile);
	outputfile.close();

	system("pause");
	return 0;
}