/*
 * =====================================================================================
 *
 *       Filename:  CommUtil.cpp
 *
 *    Description:  i
 *
 *        Version:  1.0
 *        Created:  09/07/17 19:00:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include "CommUtil.h"
#define  likely(x)        __builtin_expect(!!(x), 1) 
#define  unlikely(x)      __builtin_expect(!!(x), 0) 

int GetDayTime()
{
	return time(NULL) % 86400;
}

void ReplaceTail(const char* pFlag, char* pStr)
{
	char* pPos = strstr(pStr, pFlag);
	if(pPos != NULL)
	{
		*pPos = '\0';
	}
}

void InitMem(void* pBuf, int iSize)
{
	if(pBuf != NULL)
	{
		memset(pBuf, 0, iSize);
	}
}

//褰撳墠鏃堕棿锛堝崟浣嶏細姣??绉掞級
uint64_t GetCurrentTime()
{        
	timeval tv;
	memset(&tv, 0, sizeof(tv));

	if (0 != gettimeofday(&tv, NULL))
	{ 
		return 0;
	}

	uint64_t ullTime = (uint64_t)tv.tv_sec * (uint64_t)1000 + tv.tv_usec/1000;
	return ullTime;
};   


