#include "stdafx.h"
#include "Object.h"

Object::Object()
	:m_Position(0.f,0.f)
	,m_Rotation(0)
	,m_Visible(true)
	,m_Scale(1.f,1.f)
{
	D3DXMatrixIdentity(&m_wMat);
}

Matrix Object::GetMatrix()
{
	Vec2 RotCenter = Vec2(0, 0);
	RotCenter.x = -Camera::GetInst()->m_Position.x + m_RotationCenter.x;
	RotCenter.y = -Camera::GetInst()->m_Position.y + m_RotationCenter.y;

	D3DXMatrixTransformation2D(&m_wMat, 0, 0, &m_Scale, &RotCenter, m_Rotation, &m_Position);

	if (m_Parent)
		m_wMat *= m_Parent->GetMatrix();

	return m_wMat;
}

void Object::Update(float deltatime, float time)
{
}

void Object::Render()
{
}

void Object::OnCollision(Object* obj, std::string tag)
{
}

void Object::Translate(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Object::Rotate(float r)
{
	m_Rotation += D3DXToRadian(r);
}

void Object::SetScale(float x, float y)
{

	m_Position.x = x;
	m_Position.y = y;
}

void Object::SetPosition(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

