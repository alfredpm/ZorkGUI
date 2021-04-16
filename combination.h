#ifndef COMBINATION_H
#define COMBINATION_H
#include "item.h"

class Combination
{
private :
    Item* item1;
    Item* item2;
    struct {                                //Stores all bools in Status, more space-efficiently than in separate bools,
        unsigned int active : 1;                   // not necessary, may not be as efficient computation-wise
        unsigned int isReversible : 1;
        unsigned int isDestroyedOnUse : 1;
    } Status ;

    Item* craftItem;
    //Currently all combination give the same feedback when they are performed.
    //onSwitchOn and onSwitchOff could be displayed in the function setFlag
    //string onSwitchOn;    //Would contain the text displayed when the combination happens and flag becomes true.
    //string onSwitchOff;   //Would contain the text displayed when the combination happens and flag becomes false. (eg. unlocking door)
public:
    Combination(Item* firstIn, Item* secondIn, bool startFlag=false, bool reversible=false, bool destroyOnUse=true, Item* itemPtr=0);

    ~Combination();

    bool usesBoth(Item* firstIn, Item* secondIn);
    Item* onCombine();
    void setFlag(bool flagIn);
    bool getFlag();
};

#endif // COMBINATION_H
