#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <map>
#include "Engine.h"

// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
// #include <SDL2/SDL_mixer.h>
// #include <SDL2/SDL_ttf.h>

class TextureManager {
  public:
    static TextureManager* GetInstance();
    TextureManager();
    bool Load(std::string id, std::string filename);
    void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip);
    void Drop(std::string id);
    void Clean();
  private:
    std::map<std::string, SDL_Texture*> _textureMap;
    static TextureManager* instace;
};

#endif