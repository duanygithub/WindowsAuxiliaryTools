
// 随机字符生成器.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// C随机字符生成器App:
// 有关此类的实现，请参阅 随机字符生成器.cpp
//

class C随机字符生成器App : public CWinApp
{
public:
	C随机字符生成器App();

// 重写
public:
	virtual BOOL InitInstance();
	static int elsetype;
// 实现

	DECLARE_MESSAGE_MAP()
};

extern C随机字符生成器App theApp;
