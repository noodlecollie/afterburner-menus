#include <cstdarg>
#include <memory>
#include "logInterface_mainui.h"
#include "enginecallback_menu.h"
#include "utlstring.h"

#define PREFIX_WARNING "^3Warning:^7 "
#define PREFIX_ERROR "^1Error:^7 "

// Eww, non-const char pointers again...

void LogInterface_MainUI::Debug(const CUtlString& message)
{
	Con_DPrintf(const_cast<char*>(message.String()));
}

void LogInterface_MainUI::Message(const CUtlString& message)
{
	Con_Printf(const_cast<char*>(message.String()));
}

void LogInterface_MainUI::Warning(const CUtlString& message)
{
	Con_Printf(PREFIX_WARNING "%s", message.String());
}

void LogInterface_MainUI::Error(const CUtlString& message)
{
	Con_Printf(PREFIX_ERROR "%s", message.String());
}

void LogInterface_MainUI::DebugF(const char* format, ...)
{
	std::unique_ptr<char> message(new char[MAX_MESSAGE_LENGTH]);
	va_list args;

	va_start(args, format);
	V_vsnprintf(message.get(), MAX_MESSAGE_LENGTH, format, args);
	va_end(args);

	Con_DPrintf(message.get());
}

void LogInterface_MainUI::MessageF(const char* format, ...)
{
	std::unique_ptr<char> message(new char[MAX_MESSAGE_LENGTH]);
	va_list args;

	va_start(args, format);
	V_vsnprintf(message.get(), MAX_MESSAGE_LENGTH, format, args);
	va_end(args);

	Con_Printf(message.get());
}

void LogInterface_MainUI::WarningF(const char* format, ...)
{
	std::unique_ptr<char> message(new char[MAX_MESSAGE_LENGTH]);
	va_list args;

	va_start(args, format);
	V_vsnprintf(message.get(), MAX_MESSAGE_LENGTH, format, args);
	va_end(args);

	Con_Printf(PREFIX_WARNING "%s", message.get());
}

void LogInterface_MainUI::ErrorF(const char* format, ...)
{
		std::unique_ptr<char> message(new char[MAX_MESSAGE_LENGTH]);
	va_list args;

	va_start(args, format);
	V_vsnprintf(message.get(), MAX_MESSAGE_LENGTH, format, args);
	va_end(args);

	Con_Printf(PREFIX_ERROR "%s", message.get());
}
