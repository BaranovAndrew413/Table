#include<iostream>
#include<string>
using namespace std;
#include"TArrayTable.h"
class TScanTable:public TArrayTable{
public:
	TScanTable(int Size = TabMaxSize) :TArrayTable(Size){};
	virtual bool FindRecord(TKey k) ;//найти запись
	virtual int InsRecord(TKey k, TValue pVal) ;
	virtual int DelRecord(TKey k) ;



};