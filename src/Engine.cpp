#include <iostream>
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
  isRunning = true;
}

bool Engine::Clean()
{

}

void Engine::Quit()
{

}

void Engine::Update()
{
  std::cout << "Updating..." <<std::endl;
}

void Engine::Render()
{

}

void Engine::Events()
{

}

bool Engine::IsRunning()
{
  return isRunning;
}