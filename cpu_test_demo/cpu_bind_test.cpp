/*
 * =====================================================================================
 *
 *       Filename:  cpu_bind_test.cpp
 *
 *    Description:  :
 *
 *        Version:  1.0
 *        Created:  09/05/17 11:06:07
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
#include <sched.h>
#include <unistd.h> /*  sysconf */
#include <time.h>


int BindCpu(int iCPUid)
{
	cpu_set_t mask;	
	CPU_ZERO(&mask);
	CPU_SET(iCPUid, &mask);
	if (sched_setaffinity(0, sizeof(cpu_set_t), &mask) == -1) 
	{ 
		printf("father sched_setaffinity cpu %d!\n", iCPUid);
		return 1;
	}
	return 0;
}
void fChildren(int id)
{
	while(1)
	{
		printf("Children_%d!\n", id);
		sleep(1);
	}
}

void fFatcher()
{
	while(1)
	{
		printf("Father!\n");
		sleep(1);
	}
}

int main(int argc, char** argv)
{
	int iChiNum = atoi(argv[1]);
	if(iChiNum > 16)
	{
		printf("process too many!\n");
		return 0;
	}
	while(iChiNum--)
	{
		int pid = fork();
		if( pid == 0)
		{
			BindCpu(iChiNum+1);
			fChildren(iChiNum+1);
			return 0;
		}
	}
	//father
	BindCpu(0);
	fFatcher();
	return 0;
}
