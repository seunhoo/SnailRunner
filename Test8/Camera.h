#pragma once
class Camera : public Singleton<Camera>
{
private:
	Matrix mTrans;
	Matrix mScale;
	Matrix mRot;
	Matrix mWorld;


public:

	Vec2 m_Position;
	Vec2 m_Scale;
	float m_Rotation;
	Camera();

	Matrix GetWorld() { return mWorld; }

	void Zoom();
	void Follow(Object* obj);
	void Update(float deltatime, float time);
	void Render();

};

