#include <string>
#include "SDL_include.h"

class Sprite
{
public:
	Sprite();
	Sprite(std::string file);
	~Sprite();
	void Open(std::string file);
	void SetClip (int x, int y, int w, int h);
	void Render (int x, int y);
	int GetWidth();
	int GetHeight();
	bool isOpen();

private:

	SDL_Texture* texture;
	int width;
	int height;
	SDL_Rect clipRect;
};