/*
 * =====================================================================================
 *
 *       Filename:  CHttpPare.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/27/17 14:06:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef CHTTP_PARE_H
#define CHTTP_PARE_H
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

class CHttpPare
{
	public:
		CHttpPare();
		virtual ~CHttpPare();
		int PareHttp(const char* pHttpReq);
		const char* GetBody() {return m_aszBody;}
		const char* GetHost() {return m_aszHost;}
		//====other item
	private:
		char m_aszBody[1024*1024];
		char m_aszHost[1024];
		//char* m_aszBody;
		//char* m_aszHost;
};
#endif
