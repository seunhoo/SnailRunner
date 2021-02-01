#pragma once
#define GT App::GetInst()->DeltaTime
#define AT App::GetInst()->Time
class App : public Singleton<App>
{
public:
	int m_Width;
	int m_Height;
	bool m_WindowMode;
	float Time;

	bool Init(int width, int height, bool windowMode);
	void Run();
	void Release();

	float DeltaTime;

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

	bool _CreateWindow();
	bool _CreateRenderer();

	HWND m_Hwnd;

	HWND GetHwnd() { return m_Hwnd; }
};

