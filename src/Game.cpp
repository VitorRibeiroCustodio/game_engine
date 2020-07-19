#include "Game.h"

Game* Game::instance = nullptr;

int WIDTH_SCREEN = 1024;
int HEIGHT_SCREEN = 600;
int allocateChannels = 0;

Game& Game::GetInstance() {
  if (instance == nullptr) {
    instance = new Game("Starting game...", WIDTH_SCREEN, HEIGHT_SCREEN);
  }

  return *instance;
}

Game::Game(std::string title, int width, int height) {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
    SDL_Log("Incapaz de inicializar SDL: %s", SDL_GetError());
    exit(1);
  }

  if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0)
    {
    	SDL_Log("Incapaz de inicializar IMG_Init: %s", SDL_GetError());
    	exit(1);
    }

  if (Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3) == 0)
    {
    	SDL_Log("Incapaz de inicializar Mix_Init: %s", SDL_GetError());
    	exit(1);
    }
	
  if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0)
    {
    	SDL_Log("Incapaz de inicializar Mix_OpenAudio: %s", SDL_GetError());
    	exit(1);
    }

    allocateChannels = Mix_AllocateChannels(32);
  window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}

SDL_Renderer* Game::GetRenderer()
{
	return renderer;
}

void Game::Run() {
  delete instance;
}