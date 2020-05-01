#include<iostream>
#include<string>
using namespace std;
#include"ScanTable.h"
enum TSortMethod{SELECT_SORT,QUICK_SORT};
class TSortTable :public TScanTable{
private:
	TRecord *pBuff;
	TSortMethod SortMethod;
	void SortData();
	void SelectSort();
	void QuickSort();
	void QuickSorter(int first,int last);
public:
	TSortTable(int Size = TabMaxSize) :TScanTable(Size){
		pBuff = new TRecord[DataCount];
	}
	~TSortTable(){
		delete[]pBuff;
	}
	TSortTable(const TScanTable &tab);
	TSortTable & operator=(const TScanTable &tab);
	TSortMethod GetSortMethod(){ return SortMethod; }
	void SetSortMethod(TSortMethod sm){ SortMethod = sm; }
	virtual bool FindRecord(TKey k);//найти запись
	virtual int InsRecord(TKey k, TValue pVal);
	virtual int DelRecord(TKey k);
};