#include<iostream>
using namespace std;
template <class TKey, class TValue>
class TRecord{
protected: TKey Key;
		   TValue Value;
public:
	TRecord(){}
	TRecord(TKey k){ Key = k; }
	TRecord(TKey k, TValue Val){
		Key = k;
		Value = Val;
	}
	void SetKey(TKey k){ Key = k; }
	TKey GetKey(void){ return Key; }
	void SetValue(TValue p){ Value = p; }
	TValue GetValue(){ return Value; }
	virtual int operator==(const TRecord &tr){ return Key == tr.Key; }
	virtual int operator!=(const TRecord &tr){ return Key != tr.Key; }
	virtual int operator>(const TRecord &tr){ return Key <tr.Key; }
	virtual int operator<(const TRecord &tr){ return Key > tr.Key; }
	friend class TArrayTable;
	friend class TScanTable;
	friend class TSortTable;




};