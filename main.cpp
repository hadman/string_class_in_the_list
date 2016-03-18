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
public:
    strClass() // Конструктор
    {
        head = NULL;
    }
    ~strClass() // Деструктор
    {

    }

    strClass& operator=(strClass& another) // присваивание объекта
    {
        if(head == another.head) // самоприсваивание
        {
            return *this;
        }

        elem* head = new elem;
        elem* curr = another.head;

        while (curr != NULL)
        {
            this->add(curr->info);
            curr = curr->ptr;
        }
        return *this; // возвращаем голову нового списка
    }


    strClass& operator+(char a) // конкатенация символа
    {
        this->add(a);
        return *this;
    }

    strClass&operator+(string str) // конкатенация строки
    {
        for (int i = 0; i < str.length(); ++i) {
            this->add(str[i]);
        }
        return *this;
    }

    strClass&operator+(strClass& another) // конкатенация объекта
    {
        elem* curr = another.head;
        if(curr == NULL) // если объект пустой
        {
            return *this;
        }else // если объект не пустой
        {
            while (curr != NULL)
            {
                this->add(curr->info);
                curr = curr->ptr;
            }
        }
        return *this;
    }

    void printStr()
    {
        //cout << "head = " << head << endl;
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
    strClass str2;

    str = str + 'a';
    str = str + 'b';
    str = str + 'c';
    str = str + 'd';
    str = str + "hello";


    str2 = str2 + " World";
    str = str + str2;

    cout << "stringClass Str = ";
    str.printStr();

    cout << "stringClass Str2 = ";
    str2.printStr();

    cout << "**********" << endl;
    cout << "**********" << endl;
    return 0;
}