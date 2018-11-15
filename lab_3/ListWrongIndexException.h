#include "ListException.h"
class ListWrongIndexException:public ListException{
public:
    virtual const char* what() const throw(){
        return "ListWrongIndexException";
    }
};
