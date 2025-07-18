//
// bomb.cpp
//

#include "bomb.h"

using namespace HE;

Math::Rectangle Bomb::GetCollision()
{
	Math::Rectangle collision;
	collision.x = (long)sprite_.params.pos.x;
	collision.y = (long)sprite_.params.pos.y;
	collision.width = (long)sprite_.params.siz.x;
	collision.height = (long)sprite_.params.siz.y;

	collision_sprite_.params.pos.x = (float)collision.x;
	collision_sprite_.params.pos.y = (float)collision.y;
	collision_sprite_.params.siz.x = (float)collision.width;
	collision_sprite_.params.siz.y = (float)collision.height;



	return collision;
}

void Bomb::Load()
{

	sprite_ = Sprite("bomb.png");
	//RenderingPath->AddSprite(&sprite_, -50);


	//RenderingPath->AddSprite(&collision_sprite_, 1);

}
void Bomb::AddScene()
{
	RenderingPath->AddSprite(&sprite_, -50);
}

void Bomb::Initialize(Math::Vector2 initial, float drop_speed)
{

	sprite_.params.siz = Math::Vector2(50.0f, 50.0f);
	sprite_.params.pos = initial;
	sprite_.params.enableDrawRect(Rectf(
		0, 0, sprite_.params.siz.x, sprite_.params.siz.y
	));

	SetInitialPosition();

	collision_sprite_.params.color = Color(0, 255, 0);
	collision_sprite_.params.opacity = 0.0f;

	drop_speed_ = drop_speed;
}

void Bomb::Update()
{
	sprite_.params.pos.y += (100.0f + drop_speed_) * Time.deltaTime;

}

void Bomb::OnCollision()
{

}



void Bomb::SetInitialPosition()
{
	const int osobaaning = Random::GetRandom(0, 2);
	switch (osobaaning)
	{
	case 0:
		sprite_.params.pos.x = Random::GetRandom(0.0f, 615.0f - sprite_.params.siz.x);
		break;
	case 1:
		sprite_.params.pos.x = Random::GetRandom(615.0f, 1280.0f - sprite_.params.siz.x);
		break;
	}
	sprite_.params.pos.y = Random::GetRandom(-240.0f, -120.0f);
	drop_speed_ = Random::GetRandom(0.0f, 500.0f);
}