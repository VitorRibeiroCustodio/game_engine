#ifndef IOBJECT_H
#define IOBJECT_H

#include <iostream>
#include "Vector2D.h"


class IObject {
  public:
    virtual void Draw()=0;
    virtual void Update(float dt)=0;
    virtual void Clean()=0;
};

#endif
