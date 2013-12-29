#include "stdafx.h"
#include "Date.h"


Date::Date(void)
{
	day=1;
	month=1;
	year=1;
}


Date::~Date(void)
{
}

Date::Date(int d, int m, int y)
{
	day=d;
	month=m;
	year=y;
}

void Date::setDay(int d)
{
	day=d;
}

int Date::getDay()
{
	return day;
}

void Date::setMonth(int m)
{
	month=m;
}

int Date::getMonth()
{
	return month;
}

void Date::setYear(int y)
{
	year=y;
}


int Date::getYear()
{
	return year;
}

void Date::display()
{
	cout<<day<<"/"<<month<<"/"<<year;
}

void Date::toFile()
{
	ofstream tof("FStore.txt",ios::ate);

	tof<<day<<" "<<month<<" "<<year<<" ";
	

}


void Date::getDate()		// method to get the date from the user, can be used to modify the date also
{
	int d,m,y,l=0;

	//int dd,dd2;

	cout<<endl;
	cout<<"Enter the day: ";
	cin>>d;
	cout<<"Enter the month: ";
	cin>>m;
	cout<<"Enter the year: ";
	cin>>y;
	
	while( !(cin.good()))
	{
		cin.clear();
		d=0;
		m=0;
		y=0;
		cout<<"Enter only integers"<<endl;
		cout<<"restart program"<<endl;
		system("pause");
		exit(1);
		
	}
	while((d<1) || (d>31) &&(l<5))
	{
		
		
		cout<<"Incorrect day entered"<<endl;
		cout<<"Enter the day: ";
		cin>>d;
		
	}


	while((d>=31)&&(m==9 || m==4 || m==6 || m==11) && (d<1)) // testing days of the month
	{
		cout<<"Incorrect day for that month"<<endl;
		cout<<"Enter the day: ";
		cin>>d;
	
		
	}

	while((m<1) || (m>12))				// testing for month

	{
		cout<<"Incorrect month entered: "<<endl;
		cout<<"Enter the month: ";
		cin>>m;

	}
		
	if((m==2) && (d>29))			// checking for a leap year
	{
		if((y%4==0) && ((y%100 != 0)  || (y%400 ==0) ))		// leap year conditions
		{
			cout<<"";
		}

		else 
		{
			int j=y;
			while((y==j) && (01<=d<=29))
			{

				cout<<"Year is not a leap year. Please enter a different year"<<endl;
				cout<<"Enter the year: ";
				cin>>y;
			}

		}




		
	}

	day=d;
	month=m;
	year=y;
	




	




}