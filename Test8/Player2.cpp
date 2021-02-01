#include "stdafx.h"
#include "Player2.h"
#include"RankMgr.h"
Player2::Player2()
{

	m_Player = Sprite::Create(L"Painting/Player2.png");
	m_Player->SetParent(this);
	SetPosition(100,900);

	m_PlayerWin = Sprite::Create(L"Painting/1.png");
	m_PlayerWin->SetPosition(m_Position.x, m_Position.y);
}

void Player2::Update(float deltatime, float time)
{

	if(SceneDirector::GetInst()->m_Start == Start::STAGE && m_Position.x <=7950) 
	{
		if (INPUT->GetKey(VK_RIGHT) == KeyState::DOWN)
		{
			m_Position.x += 1000 * GT;
		}
		if (INPUT->GetKey(VK_LEFT) == KeyState::DOWN)
		{
			m_Position.x += 1000 * GT;
		}
	}
	if (m_Position.x >= 7950)
	{
		RankMgr::GetInst()->KyWin();
	}


}

void Player2::Render()
{

	m_Player->Render();
	if (RankMgr::GetInst()->m_Ky == true)
	{

	}
}

void Player2::OnCollision(Object* obj, std::string tag)
{
}
