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
	if (IsFull()) {
		return TabFull;
	}
	else {
		int temp = FindRecord(k);
		for (int i = DataCount; i > CurrPos; i--)
			pRecs[i] = pRecs[i - 1];
		pRecs[CurrPos].Key = k;
		pRecs[CurrPos].Value = pVal;
		DataCount++;
	}
}
int TSortTable::DelRecord(TKey k){
	bool temp = FindRecord(k);
	for (int i = CurrPos; i < DataCount - 1; i++)
		pRecs[i] = pRecs[i + 1];
	DataCount--;
	return TabCorrect;

}