#ifndef ITABLE_H
#define ITABLE_H

#include<Engine/include/ideck.h>
#include<Engine/include/iplayer.h>

namespace CardGame{

class ITable{

    IDeck deck;

public:

    ITable(IDeck);


};

}

#endif // ITABLE_H

