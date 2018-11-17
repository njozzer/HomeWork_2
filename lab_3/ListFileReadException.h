#include "ListException.h"
#ifndef LIST_FILE_READ_EXCEPTION_H
#define LIST_FILE_READ_EXCEPTION_H

class ListFileReadException:public ListException{
public:
    virtual const char* what() const throw(){
        return "ListFileReadException";
    }
};
#endif
