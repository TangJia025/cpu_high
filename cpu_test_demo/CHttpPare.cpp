/*
 * =====================================================================================
 *
 *       Filename:  CHttpPare.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/27/17 13:56:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include "CommUtil.h"
#include "CHttpPare.h"

CHttpPare::CHttpPare()
{
	memset(m_aszHost, 0, sizeof(m_aszHost));
	memset(m_aszBody, 0, sizeof(m_aszBody));
}

CHttpPare::~CHttpPare()
{
}


int CHttpPare::PareHttp(const char* pHttpReq)
{
	int iTimes = 10;
	while(iTimes--)
	{
		//host
		const char* pTmp = strstr(pHttpReq, "\r\nHost:");
		if(pTmp != NULL)
		{
			InitMem(m_aszHost, sizeof(m_aszHost));
			const char* pStart = pTmp + 7;
			const char* pEnd = strstr(pStart, "\r\n");
			int iHostLen = pEnd - pStart;	
			memcpy(m_aszHost, pStart, iHostLen);
			m_aszHost[iHostLen] = '\0';
		}
		//body
		const char* pHeadEnd = strstr(pHttpReq, "\r\n\r\n");
		if(pHeadEnd != NULL)
		{
			InitMem(m_aszBody, sizeof(m_aszBody));
			const char* pBodyStart = pHeadEnd + 4;
			int iBodyLen = strlen(pBodyStart);
			memcpy(m_aszBody, pBodyStart, iBodyLen);
			m_aszBody[iBodyLen] = '\0';
		}
	}
	return 0;
}

#if 0
const char* GetHttpCookie(const char* pHttpReq)
{
	static char aszCookie[1024*1024];
	memset(aszCookie, 0, sizeof(aszCookie));
	const char* pItemStart = strstr(pHttpReq, "\r\ncookie:");
	if(pItemStart != NULL)
	{
		const char* pBodyStart = pHeadEnd + 4;
		memcpy(aszBody, pBodyStart, strlen(pBodyStart));
		//printf("body:%s\n", aszBody);
		return aszBody;
	}
	return NULL;

}
#endif

