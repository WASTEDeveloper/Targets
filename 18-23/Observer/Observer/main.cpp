#include "stdafx.h"
#include <iostream>
#include "Observer.h"

using namespace std;

int main()
{
	Post * myPost = new Post();
	myPost->SetName("Washington Post");
	ConcrSubscriber * subJohn = new ConcrSubscriber(myPost);

	myPost->SetName("Wikileaks");
	ConcrSubscriber * subObama = new ConcrSubscriber(myPost);

	myPost->SetName("123");

	Subscriber * expect = myPost->GetSub(2);

	system("pause");
	return 0;
}