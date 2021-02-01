#pragma once
class SceneMain : public Object
{
private:

	Sprite* m_Main;

public:

	SceneMain();


	int m_Press1;
	int m_Press2;

	bool m_TimeCheck;

	int m_GameTime;
	int m_Time;


	bool m_StartCheck;

	float m_StartTime;


	void Update(float deltatime, float time);
	void Render();
};

