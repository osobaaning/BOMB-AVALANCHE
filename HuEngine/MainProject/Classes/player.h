#pragma once

#include "../HuEngine.h"

class Player {
public:
	void Load();
	void Initialize();
	void Update();
	void OnCollision();
	HE::Math::Rectangle GetCollision();
	HE::Math::Vector3 GetPosition() const { return sprite_.params.pos; }
	void SetInitializePosition();
private:

	HE::Sprite sprite_;
	HE::Sprite collision_sprite_;

	float playerspeed_ = 0.2f;
};