#pragma once


#include "../HuEngine.h"


class Bomb {
public:

	void Load();
	void Initialize(HE::Math::Vector2 initial, float drop_speed);
	void Update();
	void OnCollision();
	HE::Math::Rectangle GetCollision();
	void SetInitialPosition();
	HE::Math::Vector3 GetPosition() const { return sprite_.params.pos; };
	void AddScene();

private:
	HE::Sprite sprite_;
	HE::Sprite collision_sprite_;
	float drop_speed_;
};