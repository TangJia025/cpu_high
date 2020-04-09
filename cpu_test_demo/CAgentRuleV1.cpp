#include "CAgentRuleV1.h"
#include <stdlib.h>
#include <iostream> 
#include <fstream>
#include <map>
#include <string>
#include <string.h>
#include <arpa/inet.h> 

using namespace std;
#define LOG_L3(fmt, args...) do{printf(fmt, ## args);} while(0)
#define LOG_ERROR(fmt, args...) do{printf(fmt, ## args);} while(0)
const uint32_t MAX_AGENT_RULE_NUM = 10000; 
enum MATCH_TYPE
{
	MATCH_TYPE_ALL = 1,
	MATCH_TYPE_POSTFIX = 2,
	MATCH_TYPE_PREFIX = 3,
};

CAgentRule::CAgentRule()
{
}

CAgentRule* CAgentRule::Instance()
{
	static CAgentRule s_cmdManager;
	return &s_cmdManager;
}
CAgentRule::~CAgentRule()
{
}
int CAgentRule::ReadRules()
{
	string strLine;
	ifstream infileips("rule.txt");
	char strip[32], strOptType[8], strHost[1024];
	while(std::getline(infileips, strLine))
	{
		sscanf(strLine.c_str(), "%s %s %s", strHost, strip, strOptType);  
		tHostRule stRule;
		memset(&stRule, 0, sizeof(stRule));
		strncpy((char*)stRule.aszServerIp, strip, sizeof(stRule.aszServerIp) - 1);	
		stRule.ucOptType = atoi(strOptType);
		map<string, tAgentRuleData>::iterator it = m_mapRule.find(strHost);
		if(it == m_mapRule.end())
		{
			tAgentRuleData stAgentRule;
			memset(&stAgentRule, 0, sizeof(stAgentRule));
			stAgentRule.usRuleCnt = 1;
			stAgentRule.astRule[0] = stRule;
			m_mapRule.insert(pair<string, tAgentRuleData>(strHost, stAgentRule));
		}
		else
		{
			uint16_t usRuleCnt = it->second.usRuleCnt;
			it->second.astRule[usRuleCnt] = stRule;
			it->second.usRuleCnt++;
		}
	}
	printf("conf num:%d\n", m_mapRule.size());
	return 0;
}


bool CAgentRule::ShouldProtect(const char* szIp, const char* szHost)
{
	int iTimes = 500;
	while(iTimes--)
	{
		int iLenIp = strlen(szIp);
		map<string, tAgentRuleData>::iterator it = m_mapRule.find(szHost);
		if(it != m_mapRule.end())
		{
			uint16_t usRuleCnt = it->second.usRuleCnt;
			for(int i = 0; i < usRuleCnt; i++)
			{
				if(0==strncasecmp((const char*)it->second.astRule[i].aszServerIp, szIp, iLenIp) 
						&& it->second.astRule[i].ucOptType == 1)
				{
					return true;	
				}
			}
		}
	}
	return false;
}
