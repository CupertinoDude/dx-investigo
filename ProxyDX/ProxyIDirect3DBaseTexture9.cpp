﻿//Copyright (C) 2012 Ashley Davis
//
//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated 
//documentation files (the "Software"), to deal in the Software without restriction, including without limitation 
//the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, 
//and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE 
//WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
//HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#include "ProxyIDirect3DBaseTexture9.h"
#include "ProxyIDirect3DDevice9.h"

using std::string;

ProxyIDirect3DBaseTexture9::ProxyIDirect3DBaseTexture9(IDirect3DBaseTexture9* _original, ProxyIDirect3DDevice9* proxyDevice, const std::string& resourceName) :
    InvestigoResource(proxyDevice, resourceName),
	original(_original)
{
}

ProxyIDirect3DBaseTexture9::~ProxyIDirect3DBaseTexture9()
{
	GetProxyDevice()->ClearTexture(this);
}

/*** IUnknown methods ***/
HRESULT __stdcall  ProxyIDirect3DBaseTexture9::QueryInterface(REFIID riid, void** ppvObj) 
{
	*ppvObj = NULL;

    if (riid == __uuidof(Investigo::IResource))
    {
        AddRef();
        *ppvObj = static_cast<Investigo::IResource*>(this);
        return S_OK;
    }

	HRESULT result = original->QueryInterface(riid, ppvObj);
	if (result == S_OK)
	{
		*ppvObj = this;
	}

	return result;
}

ULONG __stdcall  ProxyIDirect3DBaseTexture9::AddRef()
{
	return original->AddRef();
}

ULONG __stdcall  ProxyIDirect3DBaseTexture9::Release()
{
	ULONG count = original->Release();
	if (count == 0)
	{
		original = NULL;
		delete this;
	}

	return count;
}

/*** IDirect3DBaseTexture9 methods ***/
HRESULT __stdcall  ProxyIDirect3DBaseTexture9::GetDevice(IDirect3DDevice9** ppDevice)
{
	proxyDevice->AddRef();
	*ppDevice = proxyDevice;
	return S_OK;
}

HRESULT __stdcall  ProxyIDirect3DBaseTexture9::SetPrivateData(REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags)
{
	return original->SetPrivateData(refguid,pData,SizeOfData,Flags);
}

HRESULT __stdcall  ProxyIDirect3DBaseTexture9::GetPrivateData(REFGUID refguid,void* pData,DWORD* pSizeOfData)
{
	return original->GetPrivateData(refguid,pData,pSizeOfData);
}

HRESULT __stdcall  ProxyIDirect3DBaseTexture9::FreePrivateData(REFGUID refguid)
{
	return original->FreePrivateData(refguid);
}

DWORD __stdcall  ProxyIDirect3DBaseTexture9::SetPriority(DWORD PriorityNew)
{
	return original->SetPriority(PriorityNew);
}

DWORD __stdcall  ProxyIDirect3DBaseTexture9::GetPriority()
{
	return original->GetPriority();
}

void __stdcall  ProxyIDirect3DBaseTexture9::PreLoad()
{
	return original->PreLoad();
}

D3DRESOURCETYPE __stdcall  ProxyIDirect3DBaseTexture9::GetType()
{
	return original->GetType();
}

DWORD __stdcall  ProxyIDirect3DBaseTexture9::SetLOD(DWORD LODNew)
{
	return original->SetLOD(LODNew);
}

DWORD __stdcall  ProxyIDirect3DBaseTexture9::GetLOD()
{
	return original->GetLOD();
}

DWORD __stdcall  ProxyIDirect3DBaseTexture9::GetLevelCount()
{
	DX_RECORD_API_CALL(IDirect3DBaseTexture9, GetLevelCount);
	return original->GetLevelCount();
}

HRESULT __stdcall  ProxyIDirect3DBaseTexture9::SetAutoGenFilterType(D3DTEXTUREFILTERTYPE FilterType)
{
	return original->SetAutoGenFilterType(FilterType);
}

D3DTEXTUREFILTERTYPE __stdcall  ProxyIDirect3DBaseTexture9::GetAutoGenFilterType()
{
	return original->GetAutoGenFilterType();
}

void __stdcall  ProxyIDirect3DBaseTexture9::GenerateMipSubLevels()
{
	DX_RECORD_API_CALL(IDirect3DBaseTexture9, GenerateMipSubLevels);
	return original->GenerateMipSubLevels();
}


