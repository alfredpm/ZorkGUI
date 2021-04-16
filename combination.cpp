#include "combination.h"

Combination::Combination(Item* firstIn, Item* secondIn, bool startFlag, bool reversible, bool destroyOnUse, Item* rItemPtr){
    Status.active=startFlag;
    item1=firstIn;
    item2=secondIn;
    Status.isReversible=reversible;
    Status.isDestroyedOnUse=destroyOnUse;
    craftItem=rItemPtr;
}

bool Combination::usesBoth(Item* firstIn, Item* secondIn){
//    cout << item1->getShortDescription()+" ";
//    cout << item2->getShortDescription()+" ";
//    cout << firstIn->getShortDescription()+" ";
//    cout << secondIn->getShortDescription()+" ";
//    cout << (item1==firstIn)<<" ";
//    cout << (item2==secondIn)<<" ";
//    cout << (item1==secondIn)<<" ";
//    cout << (item2==firstIn)<<" ";
    bool res= (((item1==firstIn) && (item2==secondIn))||((item1==secondIn) && (item2==firstIn)));
    //cout << " Result : "<< res <<endl;
    return res;
}

Item* Combination::onCombine(){
    if (Status.isDestroyedOnUse){
        //delete item1; //Can't do that, vectors include pointers to those
        //delete item2;
    }
    else if (Status.isReversible){
        setFlag(!Status.active);
    }
    else if (Status.active==true){
        cout << "You already did that." << endl;
    } else {
        setFlag(true);
    }
    return craftItem;
}


void Combination::setFlag(bool flagIn){
    Status.active=flagIn;
}

bool Combination::getFlag(){
    return Status.active;
}
