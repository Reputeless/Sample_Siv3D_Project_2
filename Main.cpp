# include <Siv3D.hpp> // Siv3D v0.6.12
# include "Common.hpp"
# include "Title/Title.hpp"
# include "Game/Game.hpp"

void Main()
{
	const INI ini{ U"config.ini" };

	if (not ini)
	{
		throw Error{ U"config.ini を読み込めませんでした。" };
	}

	const String windowTitle = ini.getOr<String>(U"Window", U"title", U"ERROR");
	const Size windowSize = ini.getOr<Size>(U"Window", U"size", Size{ 800, 600 });

	Window::SetTitle(windowTitle);
	Window::Resize(windowSize);
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	FontAsset::Register(U"Bold", FontMethod::MSDF, 48, Typeface::Bold);

	App manager;
	manager.add<Title>(U"Title");
	manager.add<Game>(U"Game");

	while (System::Update())
	{
		if (not manager.update())
		{
			break;
		}
	}
}
