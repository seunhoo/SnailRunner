#include "stdafx.h"
#include "Stage.h"
#include"SceneMain.h"
#include"Player.h"
#include"Player2.h"
#include"Player3.h"
Stage::Stage()
{

	ObjMgr->KeepObject(new SceneMain(), "Scene");
	ObjMgr->KeepObject(new Player(), "Player");
	ObjMgr->KeepObject(new Player2(), "Player2");
	ObjMgr->KeepObject(new Player3(), "Player3");
}

void Stage::Update(float deltatime, float time)
{
}

void Stage::Render()
{
}
