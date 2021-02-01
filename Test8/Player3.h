#pragma once
class Player3 : public Object
{
private:
	Sprite* m_Player;
	Sprite* m_PlayerWin;

public:

	Player3();

	void Update(float deltatime, float time);
	void Render();

};

