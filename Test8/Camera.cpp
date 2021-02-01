#include "stdafx.h"
#include "Camera.h"

Camera::Camera()
{
	Zoom();
}

void Camera::Zoom()
{
	m_Position = Vec2(0.f, 0.f);
	m_Scale = Vec2(1.f, 1.f);
	m_Rotation = 0.f;
	Follow(nullptr);
}

void Camera::Follow(Object* obj)
{
	if (obj != nullptr)
	{
		m_Position.x = obj->m_Position.x - App::GetInst()->m_Width/2;
		m_Position.y = obj->m_Position.y - App::GetInst()->m_Height/2;
	}
}

void Camera::Update(float deltatime, float time)
{
}

void Camera::Render()
{
	D3DXMatrixRotationZ(&mRot, D3DXToRadian(m_Rotation));
	D3DXMatrixTranslation(&mTrans, -m_Position.x, -m_Position.y, 1.f);
	D3DXMatrixScaling(&mScale,m_Scale.x,m_Scale.y,1.f);

	mWorld = mTrans * mRot * mScale;
}
