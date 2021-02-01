#include "stdafx.h"
#include "RankMgr.h"

RankMgr::RankMgr()
	:m_Rock(false)
	,m_Ky(false)
	,m_Ping(false)
{
}

void RankMgr::GetWin()
{
	if (m_Rock == true && m_Ky == false && m_Ping == false)
	{

	}
	else if (m_Ky == true && m_Rock == false && m_Ping == false)
	{

	}
	else if (m_Ping == true && m_Ky == false && m_Rock == false)
	{

	}
}
