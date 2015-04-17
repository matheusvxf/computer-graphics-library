#ifndef _CUBE_H_
#define _CUBE_H_

#include "Object.h"
#include "DataType.h"
#include "Matrix4.h"

#include <string>

class Cube : public Object
{
protected:
    double halfEdgeSize;

public:
    Cube();   // Constructor
    void update();
	void render();
};

#endif

