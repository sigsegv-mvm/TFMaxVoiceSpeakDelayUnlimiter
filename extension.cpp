/**
 * SM Extension: TFMaxVoiceSpeakDelayUnlimiter
 * Written by sigsegv
 *
 * Distributed under the terms of the Simplified BSD License
 * (see LICENSE file for details)
 */

#include "extension.h"

TFMaxVoiceSpeakDelayUnlimiter g_Extension;
SMEXT_LINK(&g_Extension);

/* interface ptrs */
ICvar *icvar = nullptr;

/* convar ptrs */
ConVar *tf_max_voice_speak_delay = nullptr;

/* global state */
std::unique_ptr<ConVarUnlimiter> tf_max_voice_speak_delay_unlimiter = nullptr;

bool TFMaxVoiceSpeakDelayUnlimiter::SDK_OnMetamodLoad(ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
	GET_V_IFACE_CURRENT(GetEngineFactory, icvar, ICvar, CVAR_INTERFACE_VERSION);
	
	GET_CONVAR(tf_max_voice_speak_delay);
	
	tf_max_voice_speak_delay_unlimiter = std::make_unique<ConVarUnlimiter>(tf_max_voice_speak_delay);
	tf_max_voice_speak_delay_unlimiter->RemoveLimits();
	
	return true;
}

bool TFMaxVoiceSpeakDelayUnlimiter::SDK_OnMetamodUnload(char *error, size_t maxlen)
{
	if (tf_max_voice_speak_delay_unlimiter != nullptr) {
		tf_max_voice_speak_delay_unlimiter->RestoreLimits();
	}
	
	return true;
}
