#include <iostream>

using namespace std;
struct oneChar
{
    char info;
    struct oneChar* ptr;
};
class strClass
{
private:
    oneChar* head;
public:
    strClass() // Конструктор
    {
        head = NULL;
    }
    ~strClass() // Деструктор
    {

    }
};


int main()
{

    return 0;
}