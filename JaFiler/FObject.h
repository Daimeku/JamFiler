#pragma once
#include "Date.h"	// to store date objects
#include <string>
#include <iostream>
#include <time.h>

using namespace std;


class FObject
{
private:
	int fileNum;
	string name;		// name variable
	Date* modDate;		//date modified
	Date* creDate;		//date created
	Date* lasDate;		//date last accessed
	Date* lwDate;		//date last writtens
	FObject *left;
	FObject *right;
	

public:
	FObject(void);
	~FObject(void);
	FObject(FObject*);
	FObject(string, Date*, Date*, Date*, Date*);
	void setMD(int, int, int); // mutator for date last modified
	void setCD(int, int, int);// mutator for date created
	void setLD(int, int, int);// mutator for date last acessed
	void setLWD(int, int, int);// mutator for date last written
	void setName(string); // mutator for name
	void toFile(void);
	void setFileNum(int fn);
	void setLeft(FObject*);
	void setRight(FObject*);
	void changeDate(int);


	string getName();
	Date* getMD(); // getters
	Date* getCD();
	Date* getLD();
	Date* getLWD();
	int getFN();
	int getFileNum();
	FObject* getLeft();
	FObject* getRight();
	
	
	void ddate(int);
	void display();
};

