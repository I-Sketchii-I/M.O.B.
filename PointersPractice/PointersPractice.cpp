#include "pch.h"
#include <iostream>
#include <string>
#include "time.h"

using namespace std;

int getValue(string *pX, string *pY);
int giveCredits(int *pZ, int y);

int main()
{	
	//variables needed for the code
	string name;
	string status;
	int credits, id, i;
    
	//Welcome message and explanation
	cout << "Welcome Bounty Hunter, to the Mobile Open Bounty Collection System";
	cout << "\nM.O.B. is able to pay out all bounties through it galaxy wide network and pointers!";
	cout << "\n\nTo claim your bounty, simply enter their name and if they are alive or dead.";

	//takes name and bounty status
	cout << "\n\nPlease enter your bounty's name: ";
	cin >> name;
	cout << "\nPlease enter the status of your bounty (alive or dead): ";
	cin >> status;
	
	//pointers for name and bounty status
	string *pName = &name;
	string *pStatus = &status;

	//prints out everything for getValue() and also holds the returned int in vairable 'credits'
	credits = getValue(pName, pStatus);

	//gets number for deposit
	cout << "\n\nEnter your Hunter id number so that we may deposit your credits (11 digits): ";
	cin >> id;

	//pointer for deposit number
	int *pid= &id;

	//prints out everything for giveCredits() and stores the returned pointer in an int variable
	i = giveCredits(pid, credits);
	//prints out the address of the returned pointer
	cout << "\nAddress of Transaction: " << pid;

	system("pause");

}

int getValue(string *pX, string *pY) {
	//seeds random num generator and establishs temp variable for value
	srand(time(NULL));
	int value;

	//prints dereferenced pointer for name and determines the value
	cout << "\nBounty for: " << *pX;
	value = 1000 + (rand() % 100000);
	//if the bounty is dead it is worht half as much
	if (*pY == "dead") {
		value = value / 2;
	}
	//prints value
	cout << "\nValued at: " << value;
	
	return value;
}

int giveCredits(int *pZ, int y) {

	//prints out the account number and the credits awarded, then returns the pointer
	cout << "\n\nAccount #" << *pZ << " has been awarded " << y << " credits";
	return *pZ;
}
