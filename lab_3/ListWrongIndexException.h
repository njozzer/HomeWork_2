#include "ListException.h"
#ifndef LIST_WRONG_INDEX_EXCEPTION_H
#define LIST_WRONG_INDEX_EXCEPTION_H

class ListWrongIndexException:public ListException{
public:
    virtual const char* what() const throw(){
        return "ListWrongIndexException";
    }
};
#endif
