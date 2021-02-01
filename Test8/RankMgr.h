#pragma once
class RankMgr : public Singleton<RankMgr>
{

public:


	RankMgr();

	bool m_Rock;
	bool m_Ping;
	bool m_Ky;


	void GetWin();

	void RockWin() { m_Rock = true; }
	void PingWin() { m_Ping = true; }
	void KyWin() { m_Ky = true; }
};

