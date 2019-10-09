#include "BotProfileImage.h"

CBotProfileImage::CBotProfileImage() : CMenuBaseItem()
{
}

void CBotProfileImage::Init()
{
	CMenuBaseItem::Init();

	SetSize(IMAGE_WIDTH, IMAGE_HEIGHT);
}

void CBotProfileImage::Draw()
{
	UI_FillRect(m_scPos, m_scSize, uiPromptBgColor);
	UI_DrawString(font, m_scPos, m_scSize, L("Bot preview goes here"), colorBase, m_scChSize, QM_CENTER, ETF_SHADOW);
}

const HIMAGE& CBotProfileImage::Image() const
{
	return m_hImage;
}
