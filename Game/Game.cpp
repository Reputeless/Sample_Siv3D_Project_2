# include "Game.hpp"

Game::Game(const InitData& init)
	: IScene{ init }
{
	m_texture1 = Texture{ U"asset/image1.png", TextureDesc::Mipped };
	m_texture2 = Texture{ U"asset/image2.png", TextureDesc::Mipped };
}

void Game::update()
{
	if (MouseL.down())
	{
		changeScene(U"Title");
	}
}

void Game::draw() const
{
	Scene::SetBackground(ColorF{ 0.3, 0.4, 0.5 });

	m_texture1.scaled(0.3).rotated(Scene::Time() * 60_deg).drawAt(200, 200);

	m_texture2.scaled(0.15).rotated(Scene::Time() * 60_deg).drawAt(600, 200);
}
