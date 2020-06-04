#include<iostream>
#include<string>
using namespace std;
typedef int TKey;
typedef string TValue;

class TRecord{
protected: TKey Key;
		   TValue Value;
		   virtual void Print(ostream &os) { os << Key << " " << Value; }

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