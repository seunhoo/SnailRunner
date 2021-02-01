#pragma once
typedef struct D3DXVECTOR2 Vec2;
typedef struct D3DXMATRIX Matrix;

template<class T>
inline void SafeDelete(T*& x);

#include<d3d9.h>
#include<d3dx9.h>
#include<list>
#include<map>
#include<string>
#include<vector>
#include<time.h>
#include<math.h>
#include<algorithm>
#include<sstream>
#include<stdio.h>
#include<stdlib.h>

#include"Singleton.h"
#include"Renderer.h"
#include"Input.h"
#include"Object.h"
#include"ObjectMgr.h"
#include"Camera.h"
#include"SceneDirector.h"
#include"App.h"
#include"Texture.h"
#include"ResourceMgr.h"
#include"Sprite.h"

template<class T>
inline void SafeDelete(T*& x)
{
	delete x;
	x = static_cast<T*>(0);
}

