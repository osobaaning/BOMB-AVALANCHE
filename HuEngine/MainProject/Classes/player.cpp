//
// player.cpp
//

#include "player.h"

using namespace HE;


void Player::Load()
{
	sprite_ = Sprite("player.png");
	RenderingPath->AddSprite(&sprite_, 0);
	RenderingPath->AddSprite(&collision_sprite_, 1);
}

void Player::Initialize()
{
	sprite_.params.siz = Math::Vector2(50.0f, 50.0f);

	sprite_.params.pos = Math::Vector2(600.0f, 675.0f);




}

void Player::Update()
{


	Math::Vector2 direction;
	if (InputSystem.Keyboard.isPressed.Right)
		direction += Math::Vector2(1, 0);
	if (InputSystem.Keyboard.isPressed.Left)
		direction += Math::Vector2(-1, 0);
	
	direction.Normalize();

	auto prev_pos = sprite_.params.pos;

	sprite_.params.pos += direction * 576.0f * Time.deltaTime;

	const float RIGHT_LIMIT = RenderingPath->GetLogicalWidth() - sprite_.params.siz.x;

	sprite_.params.pos.x = std::clamp(sprite_.params.pos.x, 0.0f, RIGHT_LIMIT);

		}
Math::Rectangle Player::GetCollision()
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

	collision_sprite_.params.color = Color(0, 255, 0);
	collision_sprite_.params.opacity = 0.0f;

	return collision;

}


void Player::OnCollision()
{
	SetInitializePosition();
}

void Player::SetInitializePosition()
{
	sprite_.params.pos = Math::Vector2(
		(RenderingPath->GetLogicalWidth() - sprite_.params.siz.x) / 2.0f,
		RenderingPath->GetLogicalHeight() - sprite_.params.siz.y
	);
}


