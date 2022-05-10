#ifndef FILEZILLA_ENGINE_ENGINE_OPTIONS_HEADER
#define FILEZILLA_ENGINE_ENGINE_OPTIONS_HEADER

#include "optionsbase.h"

// The engine of FileZilla 3 can be configured using a few settings.

enum engineOptions : unsigned int
{
	OPTION_USEPASV,			// Use passive mode unless overridden by
	                                // server settings
	OPTION_LIMITPORTS,
	OPTION_LIMITPORTS_LOW,
	OPTION_LIMITPORTS_HIGH,
	OPTION_LIMITPORTS_OFFSET,
	OPTION_EXTERNALIPMODE,		/* External IP Address mode for use in active mode
	                                   Values: 0: ask operating system
	                                           1: use provided IP
	                                           2: use provided resolver
	                                 */
	OPTION_EXTERNALIP,
	OPTION_EXTERNALIPRESOLVER,
	OPTION_LASTRESOLVEDIP,
	OPTION_NOEXTERNALONLOCAL,	// Don't use external IP address if connection is
	                                // coming from a local unroutable address
	OPTION_PASVREPLYFALLBACKMODE,
	OPTION_TIMEOUT,
	OPTION_LOGGING_DEBUGLEVEL,
	OPTION_LOGGING_RAWLISTING,

	OPTION_FZSFTP_EXECUTABLE,	// full path to fzsftp executable
	OPTION_FZSTORJ_EXECUTABLE,

	OPTION_ALLOW_TRANSFERMODEFALLBACK, // If PORT fails, allow PASV and vice versa

	OPTION_RECONNECTCOUNT,
	OPTION_RECONNECTDELAY,

	OPTION_SPEEDLIMIT_ENABLE,
	OPTION_SPEEDLIMIT_INBOUND,
	OPTION_SPEEDLIMIT_OUTBOUND,
	OPTION_SPEEDLIMIT_BURSTTOLERANCE,

	OPTION_PREALLOCATE_SPACE,

	OPTION_VIEW_HIDDEN_FILES,

	OPTION_PRESERVE_TIMESTAMPS,

	OPTION_SOCKET_BUFFERSIZE_RECV,
	OPTION_SOCKET_BUFFERSIZE_SEND,

	OPTION_FTP_SENDKEEPALIVE,

	OPTION_FTP_PROXY_TYPE,
	OPTION_FTP_PROXY_HOST,
	OPTION_FTP_PROXY_USER,
	OPTION_FTP_PROXY_PASS,
	OPTION_FTP_PROXY_CUSTOMLOGINSEQUENCE,

	OPTION_SFTP_KEYFILES,
	OPTION_SFTP_COMPRESSION,

	OPTION_PROXY_TYPE,
	OPTION_PROXY_HOST,
	OPTION_PROXY_PORT,
	OPTION_PROXY_USER,
	OPTION_PROXY_PASS,

	OPTION_LOGGING_FILE,
	OPTION_LOGGING_FILE_SIZELIMIT,
	OPTION_LOGGING_SHOW_DETAILED_LOGS,

	OPTION_SIZE_FORMAT,
	OPTION_SIZE_USETHOUSANDSEP,
	OPTION_SIZE_DECIMALPLACES,

	OPTION_TCP_KEEPALIVE_INTERVAL,

	OPTION_CACHE_TTL,

	OPTION_MIN_TLS_VER,

	OPTIONS_ENGINE_NUM
};

unsigned int FZC_PUBLIC_SYMBOL register_engine_options();

inline optionsIndex mapOption(engineOptions opt)
{
	static unsigned int const offset = register_engine_options();

	auto ret = optionsIndex::invalid;
	if (opt < OPTIONS_ENGINE_NUM) {
		return static_cast<optionsIndex>(opt + offset);
	}
	return ret;
}

#endif