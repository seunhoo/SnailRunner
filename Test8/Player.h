#pragma once
class Player : public Object	
{
private:
	Sprite* m_Player;
	Sprite* m_PlayerWin;

public:

	Player();

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

