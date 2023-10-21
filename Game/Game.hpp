# pragma once
# include "../Common.hpp"

// ゲームシーン
class Game : public App::Scene
{
public:

	Game(const InitData& init);

	void update() override;

	void draw() const override;

private:

	Texture m_texture1;

	Texture m_texture2;
};
