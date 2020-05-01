#include<iostream>
#include<string>
using namespace std;
#include"TSortTable.h"
TSortTable::TSortTable(const TScanTable &tab){
	*this = tab;
}
TSortTable & TSortTable::operator=(const TScanTable &tab){
	if (pRecs != NULL){
		delete[]pRecs;
		delete[]pBuff;
		pRecs = NULL;
	}
	TabSize = tab.GetTabSize();
	DataCount = tab.GetDataCount();
	pRecs = new TRecord[TabSize];
	pBuff = new TRecord[TabSize];
	for (int i = 0; i < DataCount; i++){
		pRecs[i] = tab.pRecs[i];
	}
	SortData();
	CurrPos = 0;
	return *this;
}
bool TSortTable::FindRecord(TKey k){
	int i;
	for (i = 0; i < DataCount; i++)
		if (pRecs[i].Key == k) break;
	Efficiency += 1 + i;
	if (i < DataCount){
		CurrPos = i;
		return true;
	}
	return false;

}
int TSortTable::InsRecord(TKey k, TValue pVal){
}
int TSortTable::DelRecord(TKey k){

}