/*
 * =====================================================================================
 *
 *       Filename:  cpu_cache_test.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/05/17 13:14:02
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
#include <sys/time.h>

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

void fTest1()
{
	int arr[64][64];
	int iTimes = 10000;
	while(iTimes--)
	{
		for(int i = 0; i < 64; i++)
		{
			for(int j =0; j < 64; j++)
			{
				arr[i][j] = 1;	
			}
		}
	}
}

void fTest2()
{
	int arr[64][64];
	int iTimes = 10000;
	while(iTimes--)
	{
		for(int i = 0; i < 64; i++)
		{
			for(int j =0; j < 64; j++)
			{
				arr[j][i] = 1;	
			}
		}
	}
}

int main(int argc, char** argv)
{	
	uint64_t ullStart = GetCurrentTime();
	fTest1();
	uint64_t ullEnd = GetCurrentTime();
	uint64_t ullDiff1 = ullEnd - ullStart;

	ullStart = GetCurrentTime();
	fTest2();
	ullEnd = GetCurrentTime();
	uint64_t ullDiff2 = ullEnd - ullStart;

	printf("cost time:Test1[%lu], Test2[%lu]\n", ullDiff1, ullDiff2);
	return 0;
}
