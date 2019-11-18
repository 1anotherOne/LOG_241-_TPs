/****************************************************************************
**
** Classe TeamImageSizeCalculator
** Author: p482457
** Date: 25-oct-2019
**
****************************************************************************/

#include "TeamImageSizeCalculator.h"
#include "TeamMember.h"
#include "TeamMemberRole.h"
#include "Team.h"

//
#include "AbsTeamComponent.h"
//

TeamImageSizeCalculator::TeamImageSizeCalculator(void)
	: m_totalSize(0)
{
}

void TeamImageSizeCalculator::processTeamMember(TeamMember & member)
{
	// Recuperer la taille de l'image en bytes
	// Utiliser QImage::sizeInBytes (pour Qt5.10 et plus) ou
	//          QImage::byteCount (pour Qt5.9 et moins)
	m_totalSize += member.getImage().sizeInBytes();
}

void TeamImageSizeCalculator::processTeamMemberRole(TeamMemberRole & member)
{
	// Deleguer la recuperation de la taille de l'image au membre
	//m_totalSize += member.getMember().getImage().sizeInBytes();

	member.getMember().accept(*this);
	//TeamMember* theMember = dynamic_cast<TeamMember*>(member.getMember().clone());
	//processTeamMember(*theMember);
}

void TeamImageSizeCalculator::processTeam(Team & team)
{
	// Pour traiter une equipe, on itere sur tous les membres
	for (auto it = team.begin(); it != team.end();++it) {
		it->accept(*this);
	}
}

size_t TeamImageSizeCalculator::getTotalSize(void) const
{
	// Retourner la taille totale calculee
	return m_totalSize;
}

void TeamImageSizeCalculator::clearTotalSize(void)
{
	// Reinitialiser a zero la taille totale calculee
	m_totalSize = 0;
}
