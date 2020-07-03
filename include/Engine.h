#ifndef ENGINE_H
#define ENGINE_H

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
  private:
    bool isRunning;
    static Engine* instace;
};

#endif