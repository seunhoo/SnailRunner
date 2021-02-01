#include "stdafx.h"
#include "SceneDirector.h"

SceneDirector::SceneDirector() : m_Start(Start::NONE)
{
}

void SceneDirector::Update(float deltatime, float time)
{
	Camera::GetInst()->Update(deltatime, time);
	INPUT->Update();
	ObjMgr->Update(deltatime, time);
	if (m_CurrentScene)
		m_CurrentScene->Update(deltatime, time);
}

void SceneDirector::Render()
{
	ObjMgr->Render();
	if (m_CurrentScene)
		m_CurrentScene->Render();
}

void SceneDirector::ChangeScene(Object* obj)
{
	if (m_CurrentScene)
		SafeDelete(m_CurrentScene);

	m_CurrentScene = obj;

}
