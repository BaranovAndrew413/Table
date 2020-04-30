
#include"Table.h"

enum TDataPos{FIRST_POS, CURRENT_POS,LAST_POS};
class TArrayTable :public TTable
{
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
	virtual 
};