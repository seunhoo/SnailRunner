#pragma once
class Object
{
public:

	Object();

	std::string m_Tag;

	Matrix m_wMat;
	Matrix GetMatrix();

	RECT m_Collision;

	Object* m_Parent;
	Vec2 m_RotationCenter;
	
	Vec2 m_Size, m_Scale, m_Position;

	float m_Rotation;

	int m_Layer, A, R, G, B;

	bool m_Visible, m_Destroy;


public:

	virtual void Update(float deltatime, float time);
	virtual void Render();
	virtual void OnCollision(Object* obj, std::string tag);


	void Translate(float x, float y);
	void Rotate(float r);
	void SetScale(float x, float y);
	void SetPosition(float x, float y);
	void SetParent(Object* obj) { m_Parent = obj; }
	void SetDestroy(bool destroy) { m_Destroy = destroy; }
	bool GetDestroy() { return m_Destroy; }
};
