#include "Object.h"
#include "Keyboard.h"
#include "main.h"
#include "Config.h"

#include <iostream>

void Keyboard::keyPressCb(unsigned char key, INT32 x, INT32 y)
{
    static Vector4 move_left(-10, 0, 0);
    static Vector4 move_right(10, 0, 0);
    static Vector4 move_up(0, 10, 0);
    static Vector4 move_down(0, -10, 0);
    static Vector4 move_in(0, 0, -10);
    static Vector4 move_out(0, 0, 10);
#if (DEBUG == TRUE)
    std::cout << "Press(" << key2str(key) << ")" << std::endl;
#endif
    switch (key)
    {
    case press::t:
        Globals::curr_obj->spinToggle();
        break;
    case press::x:
        Globals::curr_obj->applyForce(move_left);
        break;
    case press::X:
        Globals::curr_obj->applyForce(move_right);
        break;
    case press::y:
        Globals::curr_obj->applyForce(move_down);
        break;
    case press::Y:
        Globals::curr_obj->applyForce(move_up);
        break;
    case press::z:
        Globals::curr_obj->applyForce(move_in);
        break;
    case press::Z:
        Globals::curr_obj->applyForce(move_out);
        break;
    case press::r:
        Globals::curr_obj->reset();
        break;
    case press::o:
        Globals::curr_obj->rotateZ(5);
        break;
    case press::O:
        Globals::curr_obj->rotateZ(-5);
        break;
    case press::s:
        Globals::curr_obj->addScale(-0.01);
        break;
    case press::S:
        Globals::curr_obj->addScale(0.01);
        break;
    case press::b:
        Globals::curr_obj = Globals::curr_obj->obj_type == Object::ObjectType::Cube ?
            (Object*)&Globals::ball : (Object*)&Globals::cube;
        break;
    case press::h:
        Globals::curr_obj->applyForce(Vector4(rand() % 300, rand() % 300, rand() % 300));
    }
    Globals::curr_obj->print();
}

std::string Keyboard::key2str(UINT8 key)
{
    switch (key)
    {
    case press::t: return "t";
    case press::x: return "x";
    case press::X: return "X";
    case press::y: return "y";
    case press::Y: return "Y";
    case press::z: return "z";
    case press::Z: return "Z";
    case press::r: return "r";
    case press::o: return "o";
    case press::O: return "O";
    case press::s: return "s";
    case press::S: return "S";
    case press::b: return "b";
    case press::h: return "h";
    default: return "Unkown key!";
    }
}