#include "Engine.h"


Engine* Engine::instace;

Engine::Engine() {
  if (this->instace != nullptr) {
    std::cout << "Error..." <<std::endl;
  }
}

Engine* Engine::GetInstance() {
  if (Engine::instace != nullptr) {
    return Engine::instace;
  }

  return Engine::instace = new Engine();
}

bool Engine::Init()
{
  if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
    SDL_Log("Failed to initialize SDL", SDL_GetError());
    return false;
  }
  
  _window = SDL_CreateWindow("GameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, 0);
  if (_window == nullptr) {
    SDL_Log("Failed to create window", SDL_GetError());
    return false;
  }

  _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (_renderer == nullptr) {
    SDL_Log("Failed to create renderer", SDL_GetError());
    return false;
  }

  return _isRunning = true;
}

bool Engine::Clean()
{

}

void Engine::Quit()
{
  _isRunning = false;
}

void Engine::Update()
{

}

void Engine::Render()
{
  SDL_SetRenderDrawColor(_renderer, 124, 218, 254, 255);
  SDL_RenderPresent(_renderer);
}

void Engine::Events()
{
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type)
  {
  case SDL_QUIT:
      Quit();
    break;
  
  default:
    break;
  }
}

bool Engine::IsRunning()
{
  return _isRunning;
}