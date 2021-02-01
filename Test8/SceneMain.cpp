#include "stdafx.h"
#include "SceneMain.h"
#include"Player.h"
#include"Player2.h"


SceneMain::SceneMain()
	:m_Time(300)
	,m_StartCheck(true)
	,m_StartTime(5)
{
	m_Main = Sprite::Create(L"Painting/BG1.png");
	m_Main->SetParent(this);

	SetPosition(4100, 1080 / 2);



}

void SceneMain::Update(float deltatime, float time)
{

	if (INPUT->GetKey(VK_F5) == KeyState::DOWN)
	{

		m_StartCheck = false;

	}
	if (m_StartCheck == false)
	{
		m_StartTime -= GT;
	}

	if (m_StartTime < 1)
	{
		SceneDirector::GetInst()->m_Start = Start::STAGE;
		m_StartCheck = true;
		if (m_Time > 0)
		{
			if (INPUT->GetKey('A') == KeyState::DOWN)
			{
				m_Press1++;
			}
			//if (INPUT->GetKey('S') == KeyState::DOWN)
			//{
			//	m_Press1++;

			//}
			if (INPUT->GetKey('D') == KeyState::DOWN)
			{
				m_Press1++;
			}
			//if (INPUT->GetKey('F') == KeyState::DOWN)
			//{
			//	m_Press1++;
			//}


			if (INPUT->GetKey(VK_RIGHT) == KeyState::DOWN)
			{
				m_Press2++;
			}
			if (INPUT->GetKey(VK_LEFT) == KeyState::DOWN)
			{
				m_Press2++;

			}
			//if (INPUT->GetKey('D') == KeyState::DOWN)
			//{
			//	m_Press2++;
			//}
			//if (INPUT->GetKey('F') == KeyState::DOWN)
			//{
			//	m_Press2++;
			//}
			m_Time--;
		}
	}


}

void SceneMain::Render()
{
	m_Main->Render();

	TCHAR szStartTime[32] = L"";


	wsprintf(szStartTime, L" %d", (int)m_StartTime);

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	Matrix matFont;

	D3DXMatrixTranslation(&matFont, 1920 /2, 100, 0);
	Renderer::GetInst()->GetSprite()->SetTransform(&matFont);
	Renderer::GetInst()->GetPressFont()->DrawTextW(Renderer::GetInst()->GetSprite(), szStartTime, 32, NULL, NULL, D3DCOLOR_ARGB(255, 0, 0, 0));

	Renderer::GetInst()->GetSprite()->End();
}
