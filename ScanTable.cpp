#include<iostream>
#include<string>
using namespace std;
#include"ScanTable.h"
bool TScanTable::FindRecord(TKey k){
	int i;
	for ( i = 0; i < DataCount; i++)
		if (pRecs[i].Key == k) break;
		Efficiency += 1 + i;
		if (i < DataCount){
			CurrPos = i;
			return true;
		}
		return false;
	
}
int TScanTable::InsRecord(TKey k, TValue pVal){
}
int TScanTable::DelRecord(TKey k){

}