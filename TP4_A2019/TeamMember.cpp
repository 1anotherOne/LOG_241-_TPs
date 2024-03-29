/****************************************************************************
**
** Classe TeamMember
** Author: p482457
** Date: 25-oct-2019
**
****************************************************************************/

#include "TeamMember.h"

// Define class static members
TeamComponentContainer TeamMember::m_emptyContainer;

TeamMember::TeamMember(std::string name, const QImage & photo)
{
	m_name = name;
	m_image = photo;
}

TeamMember::TeamMember(const TeamMember & mdd)
{
	// A Completer: constructeur de copie
	this->m_name = mdd.m_name;
	this->m_image = mdd.m_image;
}

TeamMember * TeamMember::clone(void) const
{
	// A Completer (cr�er un nouvel objet identique a this)
	// return new TeamMember(std::string(this->m_name), QImage(this->m_image));
	return new TeamMember(*this);
}

const QImage & TeamMember::getImage(void) const
{
	return m_image;
}

QImage & TeamMember::getImage(void)
{
	// A Completer
	return m_image;
}

std::string TeamMember::getName(void) const
{
	// A Completer
	return m_name;
}

void TeamMember::setName(std::string name)
{
	// A Completer
	m_name = name;
}

AbsTeamComponent& TeamMember::addTeamComponent(const AbsTeamComponent&)
{
    // Truc pour que le code compile. Rien � changer
	return *(*(m_emptyContainer.begin()));
}

TeamComponentIterator TeamMember::begin()
{
	// A Completer
	return TeamComponentIterator(m_emptyContainer.begin());
}

TeamComponentIterator_const TeamMember::cbegin() const
{
	// A Completer
	return TeamComponentIterator_const(m_emptyContainer.begin());
}

TeamComponentIterator_const TeamMember::cend() const
{
	// A Completer
	return TeamComponentIterator_const(m_emptyContainer.end());
}

TeamComponentIterator TeamMember::end()
{
	// A Completer
	return TeamComponentIterator(m_emptyContainer.end());
}

void TeamMember::deleteTeamComponent(TeamComponentIterator_const)
{
	// Rien a faire, un membre ne peut pas avoir d'enfants
}

