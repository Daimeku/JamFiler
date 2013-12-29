#include "stdafx.h"
#include "FObject.h"


FObject::FObject(void)
{
	name="john doe";
	
	modDate= new Date();
	creDate= new Date();
	lasDate= new Date();
	lwDate= new Date();
	


	left=NULL;
	right=NULL;


}

FObject::FObject(FObject *c)
{
	
	name=c->getName();
	fileNum=c->getFileNum();
	
	modDate= c->getMD();
	creDate= c->getCD();
	lasDate= c->getLD();
	lwDate= c->getLWD();
	left=c->getLeft();
	right=c->getRight();


}

FObject::~FObject(void)
{
}


FObject::FObject(string n, Date *md, Date *cd, Date *ld, Date *lwd)
{
	name=n;
	modDate=md;
	creDate=cd;
	lasDate=ld;
	lwDate=lwd;
	left=NULL;
	right=NULL;

}

								//MUTATORS

void FObject::setMD(int d, int m, int y)
{
	modDate->setDay(d);
	modDate->setMonth(m);
	modDate->setYear(y);

}

void FObject::setCD(int d, int m, int y)
{
	creDate->setDay(d);
	creDate->setMonth(m);
	creDate->setYear(y);

}

void FObject::setLD(int d, int m, int y)
{
	lasDate->setDay(d);
	lasDate->setMonth(m);
	lasDate->setYear(y);

}

void FObject::setLWD(int d, int m, int y)
{
	lwDate->setDay(d);
	lwDate->setMonth(m);
	lwDate->setYear(y);
}

void FObject::setName(string n)
{
	name=n;
}

void FObject::setFileNum(int fn)
{
	fileNum=fn;
}

void FObject::setLeft(FObject* l){
	left=l;
}

void FObject::setRight(FObject *r){
	right=r;
}



								//ACCESSORS

string FObject::getName()
{
	return name;
}

int FObject::getFileNum()
{
	return fileNum;
}

Date* FObject::getMD()
{
	return modDate;
}

Date* FObject::getCD()
{
	return creDate;
}

Date* FObject::getLD()
{
	return lasDate;
}

Date* FObject::getLWD()
{
	return lwDate;
}

int FObject::getFN()
{
	return fileNum;
}

FObject* FObject::getLeft()
{
	return left;
}
FObject* FObject::getRight(){
	return right;
}


void FObject::toFile()
{

	//	int md[3], cd[3],ld[3],lwd[3];	// arrays to store dates

	ofstream out("FStore.txt",ios::app);
	

	out<<fileNum<<" ";
	out<<name<<" ";
	out<<modDate->getDay()<<" "<<modDate->getMonth()<<" "<<modDate->getYear()<<" ";	// storing date last modified

	out<<creDate->getDay()<<" "<<creDate->getMonth()<<" "<<creDate->getYear()<<" "; // storing date created

	out<<lasDate->getDay()<<" "<<lasDate->getMonth()<<" "<<lasDate->getYear()<<" ";// storing date last accessed

	out<<lwDate->getDay()<<" "<<lwDate->getMonth()<<" "<<lwDate->getYear()<<" "<<endl;	// storing date last written




}


void FObject::ddate(int t)
{
	switch(t)
	{
	case 1: modDate->getDate();
			break;
	case 2: creDate->getDate();
			break;
	case 3: lasDate->getDate();
			break;
	case 4: lwDate->getDate();
			break;
	default: cout<<"Invalid input in ddate(int)";
			break;
	}

}


void FObject::display()
{
	cout<<endl<<endl;
	/*
	cout<<"\t\t";
	cout<<fileNum<<" "<<name<<" ";
	modDate->display();cout<<" ";
	creDate->display();cout<<" ";
	lasDate->display();cout<<" ";
	lwDate->display();cout<<" "<<endl;
	*/
	cout<<"**************************"<<endl;
	cout<<"Filenum: "<<fileNum<<endl;
	cout<<"File name: "<<name<<endl;
	cout<<"Date modified: ";modDate->display(); cout<<endl;
	cout<<"Date created: ";creDate->display() ; cout<<endl;
	cout<<"Last accessed: ";lasDate->display(); cout<<endl;
	cout<<"Last written to: ";lwDate->display(); cout<<endl;
	cout<<"**************************"<<endl;


}

void FObject::changeDate(int x)	// to change the date x determines which date is being changed
{

	int d,m,y;

	cout<<"Enter the day(dd): "; cin>>d;
	cout<<"Enter the month(mm): "; cin>>m;
	cout<<"Enter the year(yyyy): "; cin>>y;

}