#include "Engine.h"

int main() {
  auto game = Engine::GetInstance();

  game->Init();
  while (game->IsRunning())
  {
   game->Events();
   game->Update();
   game->Render();
  }
  game->Clean();
  return 0;
}