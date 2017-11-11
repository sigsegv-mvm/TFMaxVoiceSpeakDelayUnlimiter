/**
 * SM Extension: TFMaxVoiceSpeakDelayUnlimiter
 * Written by sigsegv
 *
 * Distributed under the terms of the Simplified BSD License
 * (see LICENSE file for details)
 */

#ifndef _CONVARUNLIMITER_H_
#define _CONVARUNLIMITER_H_

/* pesky compiler warnings, always trying to ruin fun things... */
#ifdef _MSC_VER
#define _ALLOW_KEYWORD_MACROS
#endif

/* access protections are for losers! */
#define private public
#define protected public
#include <convar.h>
#undef private
#undef protected

class ConVarUnlimiter
{
public:
	ConVarUnlimiter(ConVar *p_convar) : m_pConVar(p_convar) {}
	
	/* non-copyable, non-assignable */
	ConVarUnlimiter(const ConVarUnlimiter&)            = delete;
	ConVarUnlimiter& operator=(const ConVarUnlimiter&) = delete;
	
	void RemoveLimits()
	{
		if (m_bUnlimited) return;
		
		/* backup the current limits */
		m_bHasMin = m_pConVar->GetMin(m_fMinVal);
		m_bHasMax = m_pConVar->GetMax(m_fMaxVal);
		
		/* and then disable them */
		m_pConVar->m_pParent->m_bHasMin = false;
		m_pConVar->m_pParent->m_bHasMax = false;
		
		m_bUnlimited = true;
	}
	
	void RestoreLimits(bool clamp = true)
	{
		if (!m_bUnlimited) return;
		
		/* restore the backed-up old limits */
		m_pConVar->m_pParent->m_bHasMin = m_bHasMin;
		m_pConVar->m_pParent->m_bHasMax = m_bHasMax;
		m_pConVar->m_pParent->m_fMinVal = m_fMinVal;
		m_pConVar->m_pParent->m_fMaxVal = m_fMaxVal;
		
		/* if requested: clamp the current value to ensure it's within the limits */
		if (clamp) {
			if (m_bHasMin && m_pConVar->GetFloat() < m_fMinVal) {
				m_pConVar->SetValue(m_fMinVal);
			}
			if (m_bHasMax && m_pConVar->GetFloat() > m_fMaxVal) {
				m_pConVar->SetValue(m_fMaxVal);
			}
		}
		
		m_bUnlimited = false;
	}
	
	ConVar *GetConVar() const { return m_pConVar; }
	bool IsUnlimited() const { return m_bUnlimited; }
	
private:
	ConVar *m_pConVar;
	bool m_bUnlimited = false;
	
	bool m_bHasMin;
	bool m_bHasMax;
	float m_fMinVal;
	float m_fMaxVal;
};

#endif
