#pragma once
enum class Start
{
	NONE,
	STAGE
};
class SceneDirector : public Singleton<SceneDirector>,public Object
{
private:
	Object* m_CurrentScene;

public:

	Start m_Start;

	SceneDirector();

	void Update(float deltatime, float time);
	void Render();
	void ChangeScene(Object* obj);
};

