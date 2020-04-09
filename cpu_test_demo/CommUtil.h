/*
 * =====================================================================================
 *
 *       Filename:  CommUtil.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/07/17 19:06:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef COMM_UTIL_H
#define COMM_UTIL_H
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

inline int ILGetDayTime()
{
	return time(NULL) % 86400;
}

int GetDayTime();
void ReplaceTail(const char* pFlag, char* pStr);
void InitMem(void* pBuf, int iSize);

#endif
