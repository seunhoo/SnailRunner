#include "stdafx.h"
#include "Texture.h"

Texture::Texture()
	:m_pDev(Renderer::GetInst()->GetDevice())
	,m_pTexture(NULL)
{
}

bool Texture::Init(std::wstring fileName)
{
	HRESULT hr = D3DXCreateTextureFromFileEx(m_pDev, fileName.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, NULL, NULL, NULL, &m_pTexture);

	if FAILED(hr)
	{
		MessageBox(0, L"123", MB_OK, 0);
		return false;
	}

	D3DSURFACE_DESC desc;

	m_pTexture->GetLevelDesc(0, &desc);

	m_Size.x = static_cast<float>(desc.Width);
	m_Size.y = static_cast<float>(desc.Height);

	return true;
}
