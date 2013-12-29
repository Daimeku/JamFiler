#pragma once
#include "FObject.h"

class DataTree
{
public:
	DataTree(void);
	~DataTree(void);
	DataTree(FObject*);

	void setRoot(FObject*);
	void insertFile(FObject*,FObject*);
	FObject* getRoot();
	void FillTree();
	void inOrder(FObject *);
	void preOrder(FObject *);
	void postOrder(FObject *);
	void rinOrder(FObject*);
	void rpreOrder(FObject *);
	void rpostOrder(FObject*);

	bool deleteFile(FObject *,int); // accepts file number to be deleted and the root
	void modFile(int);
	void fillFile();
	void deleteTree(FObject *);

private:
	FObject *root;
	
};

