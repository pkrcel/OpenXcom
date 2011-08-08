#include "RuleResearchProject.h"

namespace OpenXcom
{

RuleResearchProject::RuleResearchProject(const std::wstring & name, int cost) : _name(name), _cost(cost)
{
}

bool RuleResearchProject::isAvailable () const
{
	std::vector<RuleResearchProject *>::const_iterator iter = _dependencys.begin ();
	while (iter != _dependencys.end ())
	{
		if (!(*iter)->isDiscovered())
			return false;
		iter++;
	}

	return true;
}

void RuleResearchProject::addDependency (RuleResearchProject * rp)
{
	_dependencys.push_back(rp);
}

bool RuleResearchProject::isDiscovered () const
{
	return _discovered;
}

int RuleResearchProject::getCost() const
{
	return _cost;
}

void RuleResearchProject::setDiscovered (bool b)
{
	_discovered = b;
}

const std::wstring & RuleResearchProject::getName () const
{
	return _name;
}

}
