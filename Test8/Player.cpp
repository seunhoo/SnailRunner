#include "stdafx.h"
#include "Player.h"
#include"RankMgr.h"
Player::Player() 
{

	m_Player = Sprite::Create(L"Painting/Player1.png");
	m_Player->SetParent(this);
	SetPosition(100,730);

	m_PlayerWin = Sprite::Create(L"Painting/1.png");
	m_PlayerWin->SetPosition(m_Position.x, m_Position.y);
}

void Player::Update(float deltatime, float time)
{
	
	if (SceneDirector::GetInst()->m_Start == Start::STAGE && m_Position.x <=7950)
	{
		if (INPUT->GetKey('A') == KeyState::DOWN)
		{
			m_Position.x += 1000 * GT;
			
			//m_Rotation += D3DXToRadian(90) * GT;
		}

		if (INPUT->GetKey('D') == KeyState::DOWN)
		{
			m_Position.x += 1000 * GT;
		}
	}
	if (m_Position.x >= 7950)
	{
		RankMgr::GetInst()->PingWin();
	}

}

void Player::Render()
{


	m_Player->Render();

	if (RankMgr::GetInst()->m_Ping == true)
	{
		m_PlayerWin->Render();
	}
}

void Player::OnCollision(Object* obj, std::string tag)
{
}
