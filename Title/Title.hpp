# pragma once
# include "../Common.hpp"

// タイトルシーン
class Title : public App::Scene
{
public:

	Title(const InitData& init);

	void update() override;

	void draw() const override;

private:

	Rect m_startButton{ Arg::center(640, 480), 400, 80 };

	Rect m_quitButton{ Arg::center(640, 580), 400, 80 };
};
