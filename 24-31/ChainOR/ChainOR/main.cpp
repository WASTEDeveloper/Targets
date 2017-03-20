#include <iostream>
#include "ChainOfR.h"

using namespace std;

int main() {

	Validation v;
	BankFee b;
	StateFee s;
	Accept a;
	v.add(&b);
	v.add(&s);
	//v.add(&a);
	Operation op(2,normal,10);
	v.handle(&op);
	bool status = op.is_accepted();
	cout << status << " " << op.get_sum() <<endl;
	system("pause");
	return 0;
}