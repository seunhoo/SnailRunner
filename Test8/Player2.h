#pragma once
class Player2 : public Object	
{
private:
	Sprite* m_Player;
	Sprite* m_PlayerWin;
public:

	Player2();

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

