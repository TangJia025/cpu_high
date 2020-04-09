/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/29/17 17:15:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "CommUtil.h"
#include "CHttpPare.h"
#include "CAgentRuleV1.h"


int main()
{
	const char* pHttpReq = "GET test\r\nHost:www.test.com\r\n\r\nhello word!";
	const char* pszIp = "10.10.10.10";	
	CAgentRule *pRuleCtrl = CAgentRule::Instance();
	pRuleCtrl->ReadRules();
	char aszHost[1024];
	while(GetDayTime() > 100)
	{
		CHttpPare objHttp;
		objHttp.PareHttp(pHttpReq);
		const char* pHost = objHttp.GetHost();
		bool bProtect = pRuleCtrl->ShouldProtect(pszIp, pHost);
		//TODO
		strncpy(aszHost, pHost, strlen(pHost));
		ReplaceTail("\r\n", aszHost);
		usleep(1000);
	}
	return 0;
}

