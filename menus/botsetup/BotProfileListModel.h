#pragma once

#include "BaseModel.h"

class CBotProfileListModel : public CMenuBaseModel
{
public:
	CBotProfileListModel();

	virtual void Update() override;
	virtual int GetColumns() const override;
	virtual int GetRows() const override;
	virtual const char* GetCellText( int line, int column ) override;
};
