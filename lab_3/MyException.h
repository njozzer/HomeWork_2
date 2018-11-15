#include <exception>
class MyException:public std::exception{
public:
    virtual const char* what() const throw(){
        return "MyException";
    }
};
