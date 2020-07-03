#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main(int argc, char** argv) {
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
    cout << "Working" << endl;
  }
  return 0;
}