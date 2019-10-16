#pragma once

#include "projectInterface/ILogInterface.h"

class LogInterface_MainUI : public ILogInterface
{
public:
	virtual ~LogInterface_MainUI() {}

	virtual void Log(ILogInterface::Level level, const CUtlString& message) override;
	virtual void LogF(ILogInterface::Level level, const char* format, ...) override;
};
