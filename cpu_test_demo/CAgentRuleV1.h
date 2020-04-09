#ifndef  CAGENTRULE_INC
#define  CAGENTRULE_INC
#include <stdint.h>
#include <string>
#include <map>

using namespace std;
typedef struct
{
	uint8_t aszServerIp[32];
	uint8_t ucOptType;	
} tHostRule;
typedef struct
{	
	uint16_t usRuleCnt;
	tHostRule astRule[100];
} tAgentRuleData;

class CAgentRule
{
public:
	static CAgentRule* Instance();
	virtual ~CAgentRule();
    //bool InitAgentRule(const char* pszHost, const char* pszUser, const char* pszPass, const char* pszDb, uint32_t uPort=3306);
    int ReadRules();
	bool ShouldProtect(const char* szIp, const char* szHost);
private:
	CAgentRule();
private:
	std::map<string, tAgentRuleData> m_mapRule;
};

#endif   /* ----- #ifndef CAGENTRULE_INC  ----- */

