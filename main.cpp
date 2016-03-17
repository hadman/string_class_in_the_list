#include <iostream>

using namespace std;
struct elem
{
    char info;
    struct elem* ptr;
};
class strClass
{
private:
    elem* head;
public:
    strClass() // Конструктор
    {
        head = NULL;
    }
    ~strClass() // Деструктор
    {

    }
    void add(char a)
    {
        elem* curr = head; // запоминаем
        elem* e = new elem; // выделяем память под структуру
        e -> info = a;
        if(curr == NULL) // если строка была пустой
        {
            head = e;
            head -> ptr = NULL; // указатель на конец строки
        } else
        {
            while(curr->ptr != NULL) // ищем последний элемент списка
            {
                curr = curr -> ptr;
            }
            curr -> ptr = e;
            e->ptr = NULL; // теперь e - последний элемент списка
        }
    }
    void printStr()
    {
        elem* curr = head; // запоминаем
        if(curr == NULL) // если строка была пустой
        {
            cout << "string is EMPTY!" << endl;
        } else
        {
            while(curr->ptr != NULL) // ищем последний элемент списка
            {
                cout << curr->info;
                curr = curr -> ptr;
            }
            cout << curr->info;
            cout << endl;
        }
    }
};


int main()
{
    strClass str;
    str.printStr();
    str.add('a');
    str.add('b');
    str.add('c');
    str.add('d');
    str.printStr();
    return 0;
}