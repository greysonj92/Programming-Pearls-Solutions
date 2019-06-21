#include<iostream>
#include<string>
#include<set>
#include<time.h>

using namespace std;

 unsigned long bigrand() {

	

	string randomN;
	int a = rand();
	int b = rand();
	string stringA, stringB;

	stringA = to_string(a);
	stringB = to_string(b);

	randomN.append(stringA);
	randomN.append(stringB);

	return stoul(randomN);

	
	
}


 //supposed to generate 30 random bits, as opposed to the 15 that rand() generates
 unsigned long bigrand2() {
	 

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

 void gensets(int m, int n) {
	 set<int> S;
	 while (S.size() < m)
		 S.insert(bigrand2() % n);
	 set<int>::iterator i;
	 for (i = S.begin(); i != S.end(); i++)
		 cout << *i << "\n";
 }

int main() {
	
	srand(time(NULL));
	int i = 10000;
	gensets(10000, 1000000);

	system("pause");
	return 0;
}