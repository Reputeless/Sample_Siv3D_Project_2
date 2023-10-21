# include "Title.hpp"

Title::Title(const InitData& init)
	: IScene{ init }
{

}

void Title::update()
{
	if (m_startButton.leftClicked())
	{
		changeScene(U"Game");
	}

	if (m_quitButton.leftClicked())
	{
		System::Exit();
	}
}

void Title::draw() const
{
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	const Font& font = FontAsset(U"Bold");

	font(U"Siv3D Game").drawAt(120, Vec2{ 640, 200 }, ColorF{ 0.96 });

	m_startButton.draw(ColorF{ 0.96 });
	font(U"Start").drawAt(m_startButton.center(), ColorF{ 0.2 });
	if (m_startButton.mouseOver())
	{
		m_startButton.drawFrame(2, 0, ColorF{ 0.2 });
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	m_quitButton.draw(ColorF{ 0.96 });
	font(U"Quit").drawAt(m_quitButton.center(), ColorF{ 0.2 });
	if (m_quitButton.mouseOver())
	{
		m_quitButton.drawFrame(2, 0, ColorF{ 0.2 });
		Cursor::RequestStyle(CursorStyle::Hand);
	}
}

