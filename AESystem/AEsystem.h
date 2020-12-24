//********************************************************************************************************
//文件名:                                       AEsystem.h
//版本:                                         1.0
//目的及主要功能:                               整个程序的头文件
//创建日期:                                     2020.9.4
//修改日期:                                     2020.9.6 
//作者:                                         贾晟浩
//修改者:                                       贾晟浩  
//联系方式:
//********************************************************************************************************

// AEsystem.h: AEsystem 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CAEsystemApp:
// 有关此类的实现，请参阅 AEsystem.cpp
//

class CAEsystemApp : public CWinAppEx
{
public:
	CAEsystemApp() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

	CView* m_pcvOldView;
	CView* m_pcvNewView;
public:
	CView* SwitchView();
};

extern CAEsystemApp theApp;
