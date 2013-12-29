#include "stdafx.h"
#include "DataTree.h"


DataTree::DataTree(void)
{
	root=NULL;
}


DataTree::~DataTree(void)
{
}

DataTree::DataTree(FObject *r)
{
	root= r;

}

void DataTree::setRoot(FObject *r)
{
	root=r;
}

FObject* DataTree::getRoot()
{
	return root;
}


void DataTree::insertFile(FObject *r,FObject *f)
						  
{


	if(r==NULL)
	{
		setRoot(f);
		//r=f;
	}
	else{

		if(f->getFileNum() <= r->getFileNum())
		{
			if(r->getLeft()==NULL) 
				r->setLeft(f);
			else
				insertFile(r->getLeft(),f);
		}
		else
		{
			if(r->getRight()==NULL)
				r->setRight(f);
			else
				insertFile(r->getRight(),f);
		}
}
}


	void DataTree::FillTree(void)	// to populate the tree based on the txt file
	{
		ifstream inp("FStore.txt",ios::in);		
		root=NULL;
	
	string n;
	int fn, md[3],cd[3],ld[3],lwd[3];


	while(!inp.eof())		// while not at the end of the file, populate the temp object
	{
		FObject *temp= new FObject();

	inp>>fn>>n;
	inp>>md[0]>>md[1]>>md[2];
	inp>>cd[0]>>cd[1]>>cd[2];
	inp>>ld[0]>>ld[1]>>ld[2];
	inp>>lwd[0]>>lwd[1]>>lwd[2];

	//cout<<"Info read"<<endl;


	temp->setFileNum(fn);
	temp->setName(n);
	temp->setMD(md[0],md[1],md[2]);
	temp->setCD(cd[0],cd[1],cd[2]);
	temp->setLD(ld[0],ld[1],ld[2]);
	temp->setLWD(lwd[0],lwd[1],lwd[2]);
	

	if (temp->getFileNum() == 0)
		root=NULL;
	//cout<<"OBject stored"<<endl;
	//temp->display();
	insertFile(root,temp);	// add the node to the binary tree
	//cout<<"File inserted"<<endl;
/*
	cout<<"**************************"<<endl;
	cout<<"Test data"<<endl;
	cout<<"fnum: "<<fn<<"name: "<<n<<endl;
	cout<<"****************************"<<endl;

	system("pause");
*/
	}

}

	//*************************************TRAVERSALS*********************************************

	void DataTree::inOrder(FObject *f)
	{
		if(f!=NULL)
		{
			inOrder(f->getLeft());
			f->display();
			inOrder(f->getRight());
		}

	}

	void DataTree::rinOrder(FObject *f)
	{
		if(f!=NULL)
		{
			rinOrder(f->getRight());
			f->display();
			rinOrder(f->getLeft());

		}
	}

	void DataTree::preOrder(FObject *f)
	{
		if(f!=NULL)
		{
			f->display();
			preOrder(f->getLeft());
			preOrder(f->getRight());
		}

	}

	void DataTree::rpreOrder(FObject *f)
	{
		if(f!=NULL)
		{

			rpreOrder(f->getRight());
			rpreOrder(f->getLeft());
			f->display();
		}


	}

	void DataTree::postOrder(FObject *f)
	{
		if(f!=NULL)
		{
			postOrder(f->getLeft());
			postOrder(f->getRight());
			f->display();

		}

	}

	void DataTree::rpostOrder(FObject *f)
	{
		if(f!=NULL)
		{
			f->display();
			rpostOrder(f->getRight());
			rpostOrder(f->getLeft());
		}

	}



	bool DataTree::deleteFile(FObject *r,int fn)
	{


		FObject *curr = new FObject();
		FObject *par = new FObject();
		bool found= false;

		curr=r;

		while(curr!=NULL){    // while the current file isnt null



			if(curr->getFileNum() !=fn)		// if the current filenum doesnt match the one being searched for
			{
				if(fn <= curr->getFileNum())	// if the filenum  being searched for is less than the current one
				{
					par=curr;					// parfent becomes the current file and 
					curr=curr->getLeft();
				}
				else     // if the filenum being searched for is greater than the current one
				{
					par=curr;
					curr=curr->getRight();
				}

			}
			else // if the current filenum actually matches the one being searched for
			{
				found=true;
				cout<<"file found"<<endl;
				system("pause");
				break;	// break from the while loop
			}

			
		}
		
		
		if(found==false)			// if the file isnt found
		{
			cout<<"File not Found"<<endl;
			return false;

		}

		if(curr==root)				// root
		{
			cout<<"The root cannot be deleted"<<endl;
			system("pause");

			
			
			 return false;
		}

		if(curr->getLeft() == NULL && curr->getRight()==NULL)
		{
			if(par->getLeft() == curr)
				par->setLeft(NULL);
			else
				par->setRight(NULL);

			delete curr;
		}
		
		if(curr->getLeft() != NULL && curr->getRight()==NULL)	// if there is a left child and no right child
		{
			if(par->getRight() == curr)
				par->setRight(curr->getLeft());
			else
				par->setLeft(curr->getLeft());

			delete curr;

		}

		if(curr->getRight() != NULL && curr->getLeft() == NULL)	// if there is a right and no left child
		{
			if(par->getRight()==curr)
				par->setRight(curr->getRight());
			else
				par->setLeft(curr->getRight());

			delete curr;

		}
		
		/*
		
		if(curr->getLeft() !=NULL && curr->getRight() != NULL) // if there is a left and right child
		{
			 
			FObject *test= new FObject();

			test=curr->getLeft();

			if( (test->getLeft() == NULL) && (test->getRight() == NULL) )
			{
				test->setLeft(curr->getLeft());
				
				curr=test;
				delete test;
			}
			
			else
			{
				FObject *llcurr= new FObject();
				FObject *llcurrp = new FObject();
				FObject *stor = new FObject();
				FObject *stor2 = new FObject();


				llcurrp= test;
				llcurr=llcurrp->getLeft();

				while(llcurr->getRight() != NULL)
				{
					llcurrp=llcurr;
					llcurr=llcurr->getRight();
				}

				//llcurr->setRight(curr->getRight());
				
				
				
				if(llcurr->getRight() != NULL)
					insertFile(llcurr->getRight(),curr->getRight());
				else
					llcurr->setRight(curr->getRight());
					


				stor= curr->getRight();
				stor2= curr->getLeft();
				FObject *kl = new FObject();
				kl=stor2;


			


				curr=llcurr;

				llcurrp->setLeft(NULL);
				
				delete llcurr;

				//insertFile(root,stor);

				



			}
			
		
		}
		*/
		
		
		return true;
		

		
	}

	void DataTree::modFile(int fn)
	{
		bool found=false;
		Date *d = new Date();
		FObject *curr = new FObject();
		FObject *par = new FObject();
		curr=root;

		//searching for the file by comparing filenums
		while(curr!=NULL)
		{
			if(curr->getFileNum() !=fn)
			{
				if(fn< curr->getFileNum())
				{
					par=curr;
					curr=curr->getLeft();
				}
				else
				{
					par=curr;
					curr=curr->getRight();
				}
				


			}
			else
			{
				found=true;
				break;
			}

		}


		//after file is found

		if(found==true)
		{
			char x; // for selection of the part of the file to be modified
			string n;
			int d,m,y;

			cout<<"FILE NUMBER: "<<curr->getFileNum()<<endl<<endl;

			cout<<"1. Modify file name"<<endl;
			cout<<"2. Modify date last modified"<<endl;
			cout<<"3. Modify date created"<<endl;
			cout<<"4. Modify date last accessed"<<endl;
			cout<<"5. Modify date last written to"<<endl;
			cout<<"choice: "<<endl;
			cin>>x;

			switch(x)				// switch to determine what part of the file to modify and execute the modifications
			{
			case '1': cout<<"Enter the new filename: ";
					cin>>n;
					curr->setName(n);
					cout<<"Filename Changed!"<<endl;
					break;
			case '2': 
					cout<<"Changing the date last modified"<<endl;
					curr->getMD()->getDate();
					cout<<"Date changed"<<endl;
					break;
					
			case '3': 
					cout<<"Changing date created"<<endl;
					curr->getCD()->getDate();
					cout<<"Date changed"<<endl;
					break;
			case '4':
					cout<<"Changing date last accessed"<<endl;
					curr->getLD()->getDate();
					cout<<"Date changed"<<endl;
					break;
			case '5': 
				cout<<"Changing date last written to"<<endl;
				curr->getLWD()->getDate();
				cout<<"Date changed"<<endl;
				break;

			default:
				cout<<"That was not a valid option"<<endl;
				break;



					

			}
		}
		else
		{
			cout<<"File not found"<<endl;
			

		}



	}

	void DataTree::deleteTree(FObject *r)
	{
		if(r!=NULL)
		{
			deleteTree(r->getLeft());
			deleteTree(r->getRight());
			delete r;



		}

	}
	void DataTree::fillFile()
	{
		ofstream out("FStore.txt",ios::trunc);

		

	}