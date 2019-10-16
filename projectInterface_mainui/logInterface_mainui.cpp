#include <cstdarg>
#include <memory>
#include "logInterface_mainui.h"
#include "enginecallback_menu.h"
#include "utlstring.h"

#define PREFIX_WARNING "^3Warning:^7 "
#define PREFIX_ERROR "^1Error:^7 "

void LogInterface_MainUI::Log(ILogInterface::Level level, const CUtlString& message)
{
	switch ( level )
	{
		case ILogInterface::Level::Debug:
		{
			Con_DPrintf(const_cast<char*>(message.String()));
			break;
		}

		case ILogInterface::Level::Warning:
		{
			Con_Printf(PREFIX_WARNING "%s", message.String());
			break;
		}

		case ILogInterface::Level::Error:
		{
			Con_Printf(PREFIX_ERROR "%s", message.String());
			break;
		}

		default:
		{
			Con_Printf(const_cast<char*>(message.String()));
			break;
		}
	}
}

void LogInterface_MainUI::LogF(ILogInterface::Level level, const char* format, ...)
{
	std::unique_ptr<char> message(new char[MAX_MESSAGE_LENGTH]);
	va_list args;

	va_start(args, format);
	V_vsnprintf(message.get(), MAX_MESSAGE_LENGTH, format, args);
	va_end(args);

	switch ( level )
	{
		case ILogInterface::Level::Debug:
		{
			Con_DPrintf(message.get());
			break;
		}

		case ILogInterface::Level::Warning:
		{
			Con_Printf(PREFIX_WARNING "%s", message.get());
			break;
		}

		case ILogInterface::Level::Error:
		{
			Con_Printf(PREFIX_ERROR "%s", message.get());
			break;
		}

		default:
		{
			Con_Printf(message.get());
			break;
		}
	}
}
