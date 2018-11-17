#include "MyException.h"
#ifndef LIST_EXCEPTION_H
#define LIST_EXCEPTION_H
class ListException:public MyException{
public:
    virtual const char* what() const throw(){
        return "ListException";
    }
};
#endif
