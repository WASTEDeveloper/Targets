#include "stdafx.h"
#include "Observer.h"

void ConcrSubscriber::HandleNotify()
{
	std::cout << "received";
}

ConcrSubscriber::~ConcrSubscriber()
{

}

Post::Post()
{
	newsname = "Forbes";
	subs.reserve(10);
}

void Post::AddSub(Subscriber * added)
{
	subs.push_back(added);
}

void Post::RemoveSub(Subscriber * removed)
{
	std::vector<Subscriber *>::iterator it;
	it = subs.begin();
	while (it != subs.end() || *it == removed)
	{
			it++;
	}
	
	if(subs.end() != it)
		subs.erase(it);
}

void Post::Notify()
{

	std::vector<Subscriber *>::iterator it = subs.begin();
	unsigned int i = 1;
	while (it != subs.end())
	{
			std::cout << "Subscriber #" << i << " ";
			subs[i]->HandleNotify();
			std::cout << " " << newsname << std::endl;
			it++;
			i++;
			std::cout << std::endl;
	}
}

void Post::SetName(std::string initName)
{
	newsname = initName;
}

Subscriber * Post::GetSub(unsigned int index)
{
	Subscriber * sub = nullptr;
	index -= 1;
	try
	{
		sub = subs.at(index);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n';
	}
	return sub;
}

std::string Post::GetName() const
{
	return newsname;
}

Subscriber::Subscriber(Post * npost)
{
	post = npost;
	post->AddSub(this);
}

Subscriber::~Subscriber()
{
	post->RemoveSub(this);
}
