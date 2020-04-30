#include<iostream>
#include<string>
using namespace std;
#include"Table.h"

enum TDataPos{FIRST_POS, CURRENT_POS,LAST_POS};
class TArrayTable :public TTable
{
protected:
	TRecord *pRecs;
	int TabSize;
	int CurrPos;
public:
	TArrayTable(int Size = TabMaxSize)
	{
		pRecs = new TRecord[Size];
		TabSize = Size;
		DataCount = CurrPos = 0;
	}
	~TArrayTable(){
		delete[]pRecs;
	}
	virtual bool IsFull() const{ return DataCount >= TabSize; }
	int GetTabSize() const{ return TabSize; }
	virtual TKey GetKey(void) const {
		return GetKey(CURRENT_POS);
	}
	virtual TValue GetValue(void) const {
		return GetValue(CURRENT_POS);
	}
	virtual TKey GetKey(TDataPos mode) const;
	virtual TValue GetValue(TDataPos mode) const;
	virtual int Reset() ;
	virtual int GoNext() ;
	virtual int IsEnd() const ;
	virtual int GetCurrentPos(){ return CurrPos; }
	virtual int SetCurrentPos(int pos) ;
	friend TSortTable;
};