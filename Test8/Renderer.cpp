#include "stdafx.h"
#include "Renderer.h"

bool Renderer::Init(int width, int height, bool windowMode)
{
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS pp = {};
	pp.BackBufferWidth = width;
	pp.BackBufferHeight = height;
	pp.BackBufferFormat = D3DFMT_A8R8G8B8;
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pp.Windowed = windowMode;

	HRESULT hr = m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, App::GetInst()->GetHwnd(), D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &m_pDevice);

	if FAILED(hr)
		return false;


	D3DXFONT_DESC fontinfo;

	ZeroMemory(&fontinfo, sizeof(D3DXFONT_DESC));
	fontinfo.Width = 50.f;
	fontinfo.Height = 100.f;
	fontinfo.Weight = FW_NORMAL;
	fontinfo.CharSet = HANGUL_CHARSET;
	lstrcpy(fontinfo.FaceName, L"¸¼Àº °íµñ");
	D3DXCreateFontIndirect(m_pDevice, &fontinfo, &m_pFont);




	D3DXCreateSprite(m_pDevice, &m_pSp);

	return true;
}

void Renderer::Release()
{
	m_pDevice->Release();
	m_pD3D->Release();
	m_pSp->Release();
}

void Renderer::Begin()
{
	m_pDevice->BeginScene();
	m_pDevice->Clear(0, 0, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255),1.f, 0);
}

void Renderer::End()
{
	m_pDevice->EndScene();
	m_pDevice->Present(0, 0, 0, 0);
}
