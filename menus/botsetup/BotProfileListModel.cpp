#include "BotProfileListModel.h"

CBotProfileListModel::CBotProfileListModel() :
	CMenuBaseModel()
{
}

void CBotProfileListModel::Update()
{
	// TODO: Generate info in the table.
}

int CBotProfileListModel::GetColumns() const
{
	return 1;
}

int CBotProfileListModel::GetRows() const
{
	// TODO: Dependant on loaded profiles.
	return 2;
}

const char* CBotProfileListModel::GetCellText( int line, int column )
{
	// TODO: Get from profiles.

	return line == 0 ? "Bot 1" : "Bot 2";
}
