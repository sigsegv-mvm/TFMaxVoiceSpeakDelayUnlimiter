/**
 * SM Extension: TFMaxVoiceSpeakDelayUnlimiter
 * Written by sigsegv
 *
 * Distributed under the terms of the Simplified BSD License
 * (see LICENSE file for details)
 */

#ifndef _INCLUDE_SOURCEMOD_EXTENSION_CONFIG_H_
#define _INCLUDE_SOURCEMOD_EXTENSION_CONFIG_H_

/**
 * @file smsdk_config.h
 * @brief Contains macros for configuring basic extension information.
 */

/* Basic information exposed publicly */
#define SMEXT_CONF_NAME			"TFMaxVoiceSpeakDelayUnlimiter"
#define SMEXT_CONF_DESCRIPTION	"Remove the min/max limits on convar tf_max_voice_speak_delay (added in the Jungle Inferno update)."
#define SMEXT_CONF_VERSION		"20171110-1"
#define SMEXT_CONF_AUTHOR		"sigsegv"
#define SMEXT_CONF_URL			"https://github.com/sigsegv-mvm/TFMaxVoiceSpeakDelayUnlimiter/"
#define SMEXT_CONF_LOGTAG		"TF_MVSD_UNLIMITER"
#define SMEXT_CONF_LICENSE		"Simplified BSD"
#define SMEXT_CONF_DATESTRING	__DATE__

/** 
 * @brief Exposes plugin's main interface.
 */
#define SMEXT_LINK(name) SDKExtension *g_pExtensionIface = name;

/**
 * @brief Sets whether or not this plugin required Metamod.
 * NOTE: Uncomment to enable, comment to disable.
 */
#define SMEXT_CONF_METAMOD		

/** Enable interfaces you want to use here by uncommenting lines */
//#define SMEXT_ENABLE_FORWARDSYS
//#define SMEXT_ENABLE_HANDLESYS
//#define SMEXT_ENABLE_PLAYERHELPERS
//#define SMEXT_ENABLE_DBMANAGER
//#define SMEXT_ENABLE_GAMECONF
//#define SMEXT_ENABLE_MEMUTILS
//#define SMEXT_ENABLE_GAMEHELPERS
//#define SMEXT_ENABLE_TIMERSYS
//#define SMEXT_ENABLE_THREADER
//#define SMEXT_ENABLE_LIBSYS
//#define SMEXT_ENABLE_MENUS
//#define SMEXT_ENABLE_ADTFACTORY
//#define SMEXT_ENABLE_PLUGINSYS
//#define SMEXT_ENABLE_ADMINSYS
//#define SMEXT_ENABLE_TEXTPARSERS
//#define SMEXT_ENABLE_USERMSGS
//#define SMEXT_ENABLE_TRANSLATOR
//#define SMEXT_ENABLE_ROOTCONSOLEMENU

#endif // _INCLUDE_SOURCEMOD_EXTENSION_CONFIG_H_
