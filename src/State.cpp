#include "State.h"

State::State()
{
    quitRequested = false;
}

State::~State()
{

}

void State::LoadAssets()
{
	bg.Open("assets/img/1tree.png");
}

void State::Update(float dt)
{
	if(SDL_QuitRequested())
	{
		quitRequested = true;
	}
}

void State::Render()
{
	bg.Render(0, 0);
}

bool State::QuitRequested()
{
	return quitRequested;
}