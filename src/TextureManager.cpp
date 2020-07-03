#include "TextureManager.h"

TextureManager* TextureManager::instace;

TextureManager::TextureManager() {
  if (this->instace != nullptr) {
    std::cout << "Error..." <<std::endl;
  }
}

TextureManager* TextureManager::GetInstance() {
  if (TextureManager::instace != nullptr) {
    return TextureManager::instace;
  }

  return TextureManager::instace = new TextureManager();
}

bool TextureManager::Load(std::string id, std::string filename)
{
  SDL_Surface* surface = IMG_Load(filename.c_str());

  if (surface == nullptr) {
    SDL_Log("Failed to load image: %s", SDL_GetError());
    return false;
  }

  SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);

  if (texture == nullptr) {
    SDL_Log("Failed to load texture: %s", SDL_GetError());
    return false;
  }

  _textureMap[id] = texture;
  return true;
}

void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE)
{
  SDL_Rect srcRect = {0, 0, width, height};
  SDL_Rect dstRect = {x, y, width, height};
  SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), _textureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void TextureManager::Drop(std::string id)
{
  SDL_DestroyTexture(_textureMap[id]);
  _textureMap.erase(id);
}

void TextureManager::Clean()
{
  std::map<std::string, SDL_Texture*>::iterator it;
  for (it = _textureMap.begin(); it != _textureMap.end(); it++)
    SDL_DestroyTexture(it->second);

  _textureMap.clear();
}
