#include "MyException.h"
class ListException:public MyException{
public:
    virtual const char* what() const throw(){
        return "ListException";
    }
};
