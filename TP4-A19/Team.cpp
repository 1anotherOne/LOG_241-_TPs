#include "Team.h"
#include "TeamMember.h"

Team::Team(std::string name)
{
	// A Completer
	m_name = name;
}

Team::Team(const Team & mdd) 
{
	// A Completer (constructeur de copie)
	m_name = mdd.m_name;
	m_image = mdd.m_image;
	m_members = mdd.m_members;
}

Team * Team::clone(void) const
{
	// A Completer (créer un nouvel objet identique a this)
	return new Team(*this);
}

const QImage & Team::getImage(void) const
{
	// A Completer
	return m_image;
}

QImage & Team::getImage(void)
{
	// A Completer
	return m_image;
}

std::string Team::getName(void) const
{
	// A Completer
	return m_name;
}

void Team::setName(std::string name)
{
	// A Completer
	m_name = name;
}

AbsTeamComponent& Team::addTeamComponent(const AbsTeamComponent & member)
{
	// A Completer: Ajouter un nouvel element dans la liste et le clonant et
	// retrourner une reference a l'objet insere dans la liste
	if (dynamic_cast<Team*>(member.clone())) {
		m_members.insert(m_members.begin(), std::make_unique<Team>(member.getName()));
	}
	else {
		m_members.insert(m_members.begin(), std::make_unique<TeamMember>(member.getName(), member.getImage()));
	}
	return *member.clone();
}

TeamComponentIterator Team::begin()
{
	// A Completer
	return m_members.begin();
}

TeamComponentIterator_const Team::cbegin() const
{
	// A Completer
	return m_members.begin();
}

TeamComponentIterator_const Team::cend() const
{
	// A Completer
	return m_members.end();
}

TeamComponentIterator Team::end()
{
	// A Completer
	return m_members.end();
}

void Team::deleteTeamComponent(TeamComponentIterator_const child)
{
	// A Completer: eliminer de la liste l'element indique par l'iterateur
	for (auto it = m_members.begin(); it != m_members.end(); ++it) {
		if (it == child) {
			m_members.erase(it);
		}
	}
}

void Team::deleteAllComponents(void)
{
	// A Completer : vider la liste et les attributs membres
	m_members.clear();
}
