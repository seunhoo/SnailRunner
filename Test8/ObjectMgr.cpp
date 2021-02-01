#include "stdafx.h"
#include "ObjectMgr.h"

void ObjectMgr::Update(float deltatime, float time)
{
	DeleteCheck();
	for (auto& iter : m_Obejcts)
		(iter)->Update(deltatime, time);
}

void ObjectMgr::Render()
{
	m_Obejcts.sort(stLISTsort());

	for (const auto& iter : m_Obejcts)
	{
		(iter)->Render();
	}


}

void ObjectMgr::Release()
{
	for (auto& iter : m_Obejcts)
		SafeDelete(iter);

	m_Obejcts.clear();
}

void ObjectMgr::DeleteCheck()
{
	for (auto iter = m_Obejcts.begin(); iter != m_Obejcts.end();)
	{
		if ((*iter)->GetDestroy())
		{
			Object* temp = (*iter);
			iter = m_Obejcts.erase(iter);
			SafeDelete(temp);
		}
		else
			++iter;
	}
	
}

void ObjectMgr::CollideCheck(Object* obj, std::string tag)
{
	for (auto& iter : m_Obejcts)
	{
		if (iter->m_Tag == tag)
		{
			RECT rect;
			if (IntersectRect(&rect, &obj->m_Collision, &iter->m_Collision))
			{
				(iter)->OnCollision(obj, obj->m_Tag);
				obj->OnCollision(iter, iter->m_Tag);
				
			}
		}
	}
}

void ObjectMgr::KeepObject(Object* obj, std::string tag)
{
	if (obj)
	{
		m_Obejcts.push_back(obj);
		obj->m_Tag = tag;
	}
}

void ObjectMgr::RemoveObject(Object* obj)
{
	if (obj)
		obj->SetDestroy(true);
}
