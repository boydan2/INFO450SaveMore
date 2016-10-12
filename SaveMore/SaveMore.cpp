// ConsoleApplication8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

class BankAccount
{
protected:
	char accountNumber[10];
	double interestRate;
	double balance;
	double price;
public:
	BankAccount()
	{
		price = 0;
	}
	virtual void display() = 0;
	virtual void get_info() = 0;
};

class Book : public BankAccount
{
	int numPages;
public:
	void display()
	{
		printf(" account number: %s\n interest rate: %3.2f\n balance: %3.2f\n price: %3.2f\n pages: %i\n",
			accountNumber, interestRate, balance, price, numPages);
	}
	void get_info()
	{
		cout << "enter account number: ";
		gets_s(accountNumber);
		cout << "enter interest rate: ";
		cin >> interestRate;
		cout << "enter balance: ";
		cin >> balance;
		cout << "enter Price: ";
		cin >> price;
		cout << "enter pages: ";
		cin >> numPages;
		cin.clear();
		cin.ignore();
	}
};

class Audio : public BankAccount
{
	int minutes;
public:
	void display()
	{
		printf(" account number: %s\n interest rate: %3.2f\n balance: %3.2f\n Price: %3.2f\n minutes: %d\n",
			accountNumber, interestRate, balance, price, minutes);
	}
	void get_info()
	{
		cout << "enter account number: ";
		gets_s(accountNumber);
		cout << "enter interest rate: ";
		cin >> interestRate;
		cout << "enter balance: ";
		cin >> balance;
		cout << "enter Price: ";
		cin >> price;
		cout << "enter minutes: ";
		cin >> minutes;
		cin.clear();
		cin.ignore();
	}
};

int main()
{
	BankAccount **bptr;
	int numberPubs = 0;
	char answer[2];

	cout << "How many bank accounts? ";
	cin >> numberPubs;
	cin.clear();
	cin.ignore();

	bptr = new BankAccount *[numberPubs];
	for (int i = 0; i < numberPubs; i++)
	{
		cout << "Book ? or Audio?  enter B for book A for Audio:  ";
		gets_s(answer);
		if (strcmp(answer, "B") == 0)
		{
			bptr[i] = new Book();
			bptr[i]->get_info();
		}
		else if (strcmp(answer, "A") == 0)
		{
			bptr[i] = new Audio();
			bptr[i]->get_info();
		}
		else
		{
			cout << "try again" << endl;
			--i;
		}
	}

	for (int i = 0; i < numberPubs; i++)
	{
		bptr[i]->display();
	}

	return 0;
}
