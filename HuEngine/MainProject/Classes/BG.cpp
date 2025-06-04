//
// BG.cpp
//

#include "BG.h"

using namespace HE;

void BG::Load()
{
	sprite_ = Sprite("Haikei.png");
	RenderingPath->AddSprite(&sprite_, -100);
}

void BG::Initialize()
{
	sprite_.params.siz = sprite_.GetTextureSize() * 3.0f;
	sprite_.params.pos = Math::Vector2(640.0f, 360.0f);
	sprite_.params.pivot = Math::Vector2(0.5f, 0.5f);
	sprite_.params.rotation = XMConvertToRadians(0.0f);
}

void BG::Update()
{
}