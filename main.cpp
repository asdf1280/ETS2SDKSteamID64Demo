#define _CRT_SECURE_NO_WARNINGS 

#ifdef _WIN32
#  define WINVER 0x0500
#  define _WIN32_WINNT 0x0500
#  include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <string.h>

#include <chrono>
#include <string>

#include "scssdk_telemetry.h"
#include "scssdk_input.h"
#include "eurotrucks2/scssdk_eut2.h"
#include "eurotrucks2/scssdk_telemetry_eut2.h"
#include "amtrucks/scssdk_ats.h"
#include "amtrucks/scssdk_telemetry_ats.h"

#include "include/steam/steam_api.h"

scs_log_t logger;

SCSAPI_RESULT scs_telemetry_init(const scs_u32_t version, const scs_telemetry_init_params_t* const params) {
	if (version != SCS_TELEMETRY_VERSION_1_01) return SCS_RESULT_unsupported;

	const auto vparams = static_cast<const scs_telemetry_init_params_v101_t*>(params);

	logger = vparams->common.log;
	logger(SCS_LOG_TYPE_message, std::format("Steam user id is {}", SteamUser()->GetSteamID().ConvertToUint64()).c_str());

	return SCS_RESULT_ok;
}

SCSAPI_VOID scs_telemetry_shutdown(void)
{
	// Nothing :)
}