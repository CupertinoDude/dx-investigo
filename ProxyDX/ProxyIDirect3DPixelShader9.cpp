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
#include "ProxyIDirect3DPixelShader9.h"
#include "ProxyIDirect3DDevice9.h"

using std::string;

ProxyIDirect3DPixelShader9::ProxyIDirect3DPixelShader9(IDirect3DPixelShader9* _original, ProxyIDirect3DDevice9* proxyDevice, const std::string& resourceName) :
	InvestigoResource(proxyDevice, resourceName),
	original(_original)
{
}

ProxyIDirect3DPixelShader9::~ProxyIDirect3DPixelShader9()
{
	GetProxyDevice()->ClearPixelShader(this);
}

/*** IUnknown methods ***/
HRESULT __stdcall ProxyIDirect3DPixelShader9::QueryInterface(REFIID riid, void** ppvObj) 
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

ULONG __stdcall ProxyIDirect3DPixelShader9::AddRef()
{
	return original->AddRef();
}

ULONG __stdcall ProxyIDirect3DPixelShader9::Release()
{
	ULONG count = original->Release();
	if (count == 0)
	{
		original = NULL;
		delete this;
	}

	return count;
}

HRESULT __stdcall ProxyIDirect3DPixelShader9::GetDevice(IDirect3DDevice9** ppDevice)
{
	proxyDevice	->AddRef();
	*ppDevice = proxyDevice;
	return S_OK;
}

HRESULT __stdcall ProxyIDirect3DPixelShader9::GetFunction(void*p,UINT* pSizeOfData)
{
	return original->GetFunction(p,pSizeOfData);
}

