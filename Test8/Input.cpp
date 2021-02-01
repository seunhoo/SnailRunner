#include "stdafx.h"
#include "Input.h"

Input::Input()
{
	ZeroMemory(&m_CurrentState, sizeof(m_CurrentState));
	ZeroMemory(&m_PrevState, sizeof(m_PrevState));
}

void Input::Update()
{
	KeyBoardUpdate();
	MouseUpdate();
}

void Input::ButtonDown(bool down)
{
	m_ButtonDown = down;
}

KeyState Input::GetKey(int key)
{
	m_bPrevState = m_PrevState[key];
	m_bCurrntState = m_CurrentState[key];

	if (m_bPrevState == true && m_bCurrntState == true)
		return KeyState::PRESS;
	else if (m_bPrevState == true && m_bCurrntState == false)
		return KeyState::UP;
	else if (m_bPrevState == false && m_bCurrntState == true)
		return KeyState::DOWN;

	return KeyState::NONE;
}

void Input::KeyBoardUpdate()
{
	for (int i = 0; i < 256; i++)
	{
		m_PrevState[i] = m_CurrentState[i];
		m_CurrentState[i] = static_cast<bool>(GetAsyncKeyState(i));
	}
}

void Input::MouseUpdate()
{
	POINT position;
	GetCursorPos(&position);
	ScreenToClient(App::GetInst()->GetHwnd(), &position);

	m_MousePosition.x = static_cast<float>(position.x) + Camera::GetInst()->m_Position.x;
	m_MousePosition.y = static_cast<float>(position.y) + Camera::GetInst()->m_Position.y;

}
