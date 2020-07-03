#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

class Engine {
  public:
    static Engine* GetInstance();
    Engine();
    bool Init();
    bool Clean();
    void Quit();
    void Update();
    void Render();
    void Events();
    bool IsRunning();
    inline SDL_Renderer* GetRenderer(){ return _renderer; }
  private:
    bool _isRunning;
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    static Engine* instace;
};

#endif