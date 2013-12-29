// JaFiler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FObject.h"
#include "DataTree.h"
#include <time.h>
#include <stdlib.h>



 
DataTree* addFile(DataTree*);
void viewFiles(void);



 
int _tmain(int argc, _TCHAR* argv[])
{
	

	
	system("color 0a");
	ifstream amount("Record.txt", ios::in);	// reading record file
	DataTree *sys = new DataTree();
	

															//testing if tree is filled
	sys->FillTree();
	/*
	cout<<"Tree filled"<<endl;
	sys->inOrder(sys->getRoot());
	cout<<"***********************"<<endl;
	cout<<"End of test"<<endl;
		system("pause");
	*/


	char cont='1';
	while (cont=='1')
	{
		system("cls");
		char i;
		bool f;
		int fn;

		cout<<"*********"<<endl;
		cout<<"main menu"<<endl;
		cout<<"*********"<<endl<<endl;

		cout<<"1...........add file"<<endl;
		cout<<"2...........In order traversal"<<endl;
		cout<<"3...........reversed in order traversal"<<endl;
		cout<<"4...........pre order traversal"<<endl;
		cout<<"5...........reversed pre order traversal"<<endl;
		cout<<"6...........post order traversal"<<endl;
		cout<<"7...........reversed post order traversal"<<endl;
		cout<<"8...........Modify Files"<<endl;
		cout<<"9...........Delete Files"<<endl;
		cout<<"0...........exit"<<endl;


	
		i=cin.get();

		switch(i)
		{
		case '1': sys=addFile(sys);
				break;
		case '2':
			//viewFiles();
			sys->inOrder(sys->getRoot());
			system("pause");
				break;

		case '3': 
					sys->rinOrder(sys->getRoot());
					system("pause");
					break;
		case '4': 
					sys->preOrder(sys->getRoot());
					system("pause");
					break;
		case '5': 
			sys->rpreOrder(sys->getRoot());
			system("pause");
				break;

		case '6': 
			sys->postOrder(sys->getRoot());
			system("pause");
			break;
			
		case'7': 
				sys->rpostOrder(sys->getRoot());
				system("pause");
				break;
		case '8':	cout<<"****************"<<endl;
					cout<<"Modify File"<<endl;
					cout<<"****************"<<endl;
					cout<<"Enter the file number: ";cin>>fn;
					if(!(cin.good()))
					{
						cout<<"Number is not an integer"<<endl;
						cin.clear();
						cout<<"Retry input"<<endl;
						system("pause");
						break;

					}
					sys->modFile(fn);
					system("pause");
				break;
		case '9':	cout<<"****************"<<endl;
					cout<<"Delete file "<<endl;
					cout<<"****************"<<endl;
					cout<<"Enter filenum: "; 
					cin>>fn;
					if(!(cin.good()))
					{
						cout<<"Number is not an integer"<<endl;
						cin.clear();
						cout<<"Retry input"<<endl;
						system("pause");
						break;

					}
					f=sys->deleteFile(sys->getRoot(),fn);
				break;
		case '0': cont='0';
			cout<<"Exiting system"<<endl;
			exit(0);
					break; 

		
		default: cout<<"incorrect input"<<endl;
				break;
		}
	}



	system("pause");
	return 0;
}

DataTree* addFile(DataTree *sys)
{
	
	FObject temp;
	int d,m, y;
	string n;
	srand(time (NULL));
	int fn = rand()%   100000 +1000;
	

	temp.setFileNum(fn);


	cout<<fn<<endl;
	cout<<"Enter File name: ";			// getting file name
	cin>>n;
	fflush(stdin);
	temp.setName(n);

	cout<<"Enter numbers 0-9 only"<<endl;
	system("pause");

	cout<<"****DATE LAST MODIFIED*****"<<endl;
	cout<<"***************************"<<endl;
	temp.ddate(1); // to get date modified
	cout<<"****Date Created***********"<<endl;
	cout<<"***************************"<<endl;
	temp.ddate(2);
	
	cout<<"****DATE LAST ACCESSED*****"<<endl;
	cout<<"***************************"<<endl;
	temp.ddate(3);
	cout<<"****DATE LAST WRITTEN TO***"<<endl;
	cout<<"***************************"<<endl;
	temp.ddate(4);
	cout<<"out";


	temp.toFile();// adding information to file
	sys->deleteTree(sys->getRoot());
	sys->FillTree();
	
	return sys;
	
}




void viewFiles()
{
	ifstream inp("FStore.txt",ios::in);
	
	
	string n;
	int fn, md[3],cd[3],ld[3],lwd[3];

	while(!inp.eof())
	{
		FObject *temp= new FObject();
	inp>>fn>>n;
	inp>>md[0]>>md[1]>>md[2];
	inp>>cd[0]>>cd[1]>>cd[2];
	inp>>ld[0]>>ld[1]>>ld[2];
	inp>>lwd[0]>>lwd[1]>>lwd[2];

	temp->setFileNum(fn);
	temp->setName(n);
	temp->setMD(md[0],md[1],md[2]);
	temp->setCD(cd[0],cd[1],cd[2]);
	temp->setLD(ld[0],ld[1],ld[2]);
	temp->setLWD(lwd[0],lwd[1],lwd[2]);

	temp->display();
	

	}
	
	system("pause");

	
	


}

/*
void randit()
{
	int x;
	srand(time(NULL));

	for (int y=0;y<20;y++)
	{
		x=rand() % 100000 +1000;
		cout<<x<<endl;

	}


}

*/