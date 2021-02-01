#include "stdafx.h"
#include "Player3.h"
#include"RankMgr.h"
Player3::Player3()
{

	m_Player = Sprite::Create(L"Painting/Player3.png");
	m_Player->SetParent(this);
	SetPosition(100, 540);

	m_PlayerWin = Sprite::Create(L"Painting/1.png");
	m_PlayerWin->SetParent(this);
	m_PlayerWin->SetPosition(m_Position.x, m_Position.y);
}

void Player3::Update(float deltatime, float time)
{

	if (SceneDirector::GetInst()->m_Start == Start::STAGE && m_Position.x <= 7950)
	{
		m_Position.x += 200 * GT;
		
		if (m_Position.x >= 1030 && m_Position.x <=7200 )
		{
			Camera::GetInst()->Follow(this);
		}
		if (m_Position.x >= 7200)
		{
			Camera::GetInst()->Follow(nullptr);
		}
	}
	if (m_Position.x >= 7950)
	{
		RankMgr::GetInst()->RockWin();
	}


}

void Player3::Render()
{


	m_Player->Render();

	if (RankMgr::GetInst()->m_Rock == true)
	{
		m_PlayerWin->Render();
	}
}
