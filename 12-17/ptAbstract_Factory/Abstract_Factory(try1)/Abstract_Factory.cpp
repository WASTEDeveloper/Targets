#include "stdafx.h"
#include "Abstract_Factory.h"

English* DistributorA::EnglishSubs()
{
	return new English("DistributorA");
}

French* DistributorA::FrenchSubs()
{
	return new French("DistributorA");
}

English* DistributorB::EnglishSubs()
{
	return new English("DistributorB");
}

French* DistributorB::FrenchSubs()
{
	return new French("DistributorB");
}

English::English(std::string input)
{
	content = "Happy timespending!" + input + " wishes you good luck! ";
}

std::string English::get_subs(std::string filmTitle)
{
	return (content + filmTitle);
}

French::French(std::string input)
{
	content = "Sans espoir, j'espere." + input + " dires vous: \"Profite de votre temps!\" ";
}

std::string French::get_subs(std::string filmTitle)
{
	return (content + filmTitle);
}
