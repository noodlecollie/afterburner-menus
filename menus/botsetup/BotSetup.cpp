#include "Framework.h"
#include "Table.h"
#include "BotProfileListModel.h"
#include "Field.h"
#include "BotProfileImage.h"

class CMenuBotSetup: public CMenuFramework
{
public:
	CMenuBotSetup();

protected:
	virtual void _Init() override;
	virtual void _VidInit() override;

private:
	static constexpr int RIGHT_EDGE_MARGIN = 30;
	static constexpr int BOTTOM_EDGE_MARGIN = 80;
	static constexpr int LIST_TOP_OFFSET = 200;
	static constexpr int LIST_SPACING = 300;
	static constexpr int LEFT_MARGIN = 200;
	static constexpr int LIST_WIDTH = 250;

	static constexpr int CENTRAL_CONTROL_SPACING = 15;
	static constexpr int PREVIEW_TOP_OFFSET = LIST_TOP_OFFSET + 32;
	static constexpr int PREVIEW_LIST_LEFT_SPACING = (LIST_SPACING - CBotProfileImage::IMAGE_WIDTH) / 2;
	static constexpr int NAME_BOX_WIDTH = 208;
	static constexpr int NAME_BOX_LEFT_SPACING = (LIST_SPACING - NAME_BOX_WIDTH) / 2;

	static constexpr int MAX_BOT_NAME_LENGTH = 32;

	void RecalculateDimensions();

	void AddButtonPressed();
	void RemoveButtonPressed();

	CMenuTable m_BotProfileList;
	CBotProfileListModel m_BotProfileListModel;

	CMenuTable m_InGameBotList;
	CBotProfileListModel m_InGameBotListModel;
	CBotProfileImage m_SelectedBotImage;
	CMenuField m_SelectedBotName;
	CMenuPicButton m_AddButton;
	CMenuPicButton m_RemoveButton;

	int m_iSidePadding;
};

static CMenuBotSetup uiBotSetup;

CMenuBotSetup::CMenuBotSetup() :
	CMenuFramework("CMenuBotSetup"),
	m_iSidePadding(0)
{
}

void CMenuBotSetup::_Init()
{
	AddItem(background);

	m_BotProfileList.SetCharSize(QM_SMALLFONT);
	m_BotProfileList.SetupColumn(0, L("Available"), 1.0f);
	m_BotProfileList.SetModel(&m_BotProfileListModel);
	AddItem(m_BotProfileList);

	m_InGameBotList.SetCharSize(QM_SMALLFONT);
	m_InGameBotList.SetupColumn(0, L("In Game"), 1.0f);
	m_InGameBotList.SetModel(&m_InGameBotListModel);
	AddItem(m_InGameBotList);

	AddItem(m_SelectedBotImage);

	m_SelectedBotName.iMaxLength = MAX_BOT_NAME_LENGTH;
	AddItem(m_SelectedBotName);

	m_AddButton.SetNameAndStatus(L("Add"), L("Add selected bot to the game."));
	m_AddButton.onReleased = VoidCb(&CMenuBotSetup::AddButtonPressed);
	m_AddButton.iFlags |= QMF_GRAYED;
	AddItem(m_AddButton);

	m_RemoveButton.SetNameAndStatus(L("Remove"), L("Remove selected bot from the game."));
	m_RemoveButton.onReleased = VoidCb(&CMenuBotSetup::RemoveButtonPressed);
	m_RemoveButton.iFlags |= QMF_HIDDEN;
	AddItem(m_RemoveButton);

	AddButton(L("Done"), nullptr, PC_DONE, VoidCb(&CMenuBotSetup::Hide));
}

void CMenuBotSetup::_VidInit()
{
	RecalculateDimensions();

	m_BotProfileList.SetRect(LEFT_MARGIN + m_iSidePadding, LIST_TOP_OFFSET, LIST_WIDTH, -BOTTOM_EDGE_MARGIN);
	m_InGameBotList.SetRect(LEFT_MARGIN + m_iSidePadding + LIST_WIDTH + LIST_SPACING, LIST_TOP_OFFSET, LIST_WIDTH, -BOTTOM_EDGE_MARGIN);

	const int profileListRightEdge = m_BotProfileList.pos.x + m_BotProfileList.size.w;
	m_SelectedBotImage.SetCoord(profileListRightEdge + PREVIEW_LIST_LEFT_SPACING, PREVIEW_TOP_OFFSET);

	const int botImageBottomEdge = m_SelectedBotImage.pos.y + m_SelectedBotImage.size.h;
	m_SelectedBotName.SetRect(profileListRightEdge + NAME_BOX_LEFT_SPACING,
							  botImageBottomEdge + CENTRAL_CONTROL_SPACING,
							  NAME_BOX_WIDTH,
							  m_SelectedBotName.size.h);

	const int botNameBottomEdge = m_SelectedBotName.pos.y + m_SelectedBotName.size.h;
	m_AddButton.SetCoord(profileListRightEdge + (LIST_SPACING / 2) - 25,
						 botNameBottomEdge + CENTRAL_CONTROL_SPACING);
	m_RemoveButton.SetCoord(profileListRightEdge + (LIST_SPACING / 2) - 50,
						 botNameBottomEdge + CENTRAL_CONTROL_SPACING);
}

void CMenuBotSetup::RecalculateDimensions()
{
	Size screenLogicalSize(ScreenWidth / uiStatic.scaleX, ScreenHeight / uiStatic.scaleY);

	// Side padding is the distance between the hard left margin and the lists.
	// This is calculated by taking the margin/lists/central area/right margin away from the total width
	// and dividing the remaining area by 2.
	m_iSidePadding = (screenLogicalSize.w - LEFT_MARGIN - (2 * LIST_WIDTH) - LIST_SPACING - RIGHT_EDGE_MARGIN) / 2;

	if ( m_iSidePadding < 0 )
	{
		m_iSidePadding = 0;
	}
}

void CMenuBotSetup::AddButtonPressed()
{
}

void CMenuBotSetup::RemoveButtonPressed()
{
}

void UI_BotSetup_Precache()
{
}

void UI_BotSetup_Menu()
{
	uiBotSetup.Show();
}

ADD_MENU(menu_botsetup, UI_BotSetup_Precache, UI_BotSetup_Menu);
