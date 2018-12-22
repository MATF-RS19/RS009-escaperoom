#include "headers/key.h"

Key::Key(qint16 id, QPixmap bg) :
    _id(id)
{
    setPixmap(bg);
}

Key::~Key(){

}
