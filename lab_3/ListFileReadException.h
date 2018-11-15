#include "ListException.h"
class ListFileReadException:public ListException{
public:
    virtual const char* what() const throw(){
        return "ListFileReadException";
    }
};
