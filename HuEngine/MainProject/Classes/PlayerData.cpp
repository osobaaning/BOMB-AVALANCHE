//
// PlayerData.cpp
//

#include "PlayerData.h"

using namespace HE;

void PlayerData::Load()
{

	score_headline_.params.style = Font::AddFontStyle("Fonts/CALIST.ttf");
	score_text_.params.style = Font::AddFontStyle("Fonts/CALIST.ttf");



	RenderingPath->AddFont(&score_headline_, 100);
	RenderingPath->AddFont(&score_text_, 100);

;
}

void PlayerData::Initialize()
{

	score_ = 0;

	score_headline_.SetText(L"SCORE");
	score_headline_.params.posX = 0.0f;
	score_headline_.params.posY = 0.0f;
	score_headline_.params.size = 64;
	score_headline_.params.color = Color(255, 255, 255);

	score_text_.SetText(std::to_string(score_));
	score_text_.params.posX = 210.0f;
	score_text_.params.posY = 0.0f;
	score_text_.params.size = 64;
	score_text_.params.color = Color(255, 0, 0);



}

void PlayerData::SetScore(int score)
{
	score_ = score;
	score_text_.SetText(std::to_string(score_));
}

