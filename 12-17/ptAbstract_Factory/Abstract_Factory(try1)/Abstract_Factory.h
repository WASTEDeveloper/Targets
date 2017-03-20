#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>

class Subtitles;
class English;
class French;

class Distributor {
public:
	virtual English* EnglishSubs() = 0;
	virtual French* FrenchSubs() = 0;
};

class DistributorA:public Distributor {
public:
	English* EnglishSubs() override;
	French* FrenchSubs() override;
};

class DistributorB :public Distributor {
public:
	English* EnglishSubs() override;
	French* FrenchSubs() override;
};

class Subtitles {
public:
	virtual std::string get_subs(std::string) = 0;
};

class English :public Subtitles {
	std::string content;
public:
	English(std::string = "");
	std::string get_subs(std::string) override;
};

class French :public Subtitles {
	std::string content;
public:
	French(std::string );
	std::string get_subs(std::string) override;
};