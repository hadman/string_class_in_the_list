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
    strClass(strClass& another) // КОНСТРУКТОР КОПИРОВАНИЯ
    {

    }
    strClass& operator=(strClass& another) // ПРИСВАИВАНИЕ ОБЪЕКТА
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


    strClass& operator+(char a) // КОНКАТЕНАЦИЯ СОМВОЛА
    {
        this->add(a);
        return *this;
    }

    strClass&operator+(string str) // КОНКАТЕНАЦИЯ СТРОКИ
    {
        for (int i = 0; i < str.length(); ++i) {
            this->add(str[i]);
        }
        return *this;
    }

    strClass&operator+(strClass& another) // КОНКАТЕНАЦИЯ ОБЪЕКТА. не работает если складываем 2 одинаковых объекта
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

    friend ostream& operator <<(ostream& out, const strClass& obj) // ПЕРЕГРУЗКА ПОТОКА
    {
        elem* curr = obj.head;
        if(curr == NULL)
        {
            out << " ";
        }else
        {
            while (curr != NULL)
            {
                out << curr->info;
                curr = curr->ptr;
            }
        }
        return out;
    }

    int length()
    {
        int i=0;
        elem* curr = head;
        if (curr == NULL)
        {
            i = 0;
        }else
        {
            while (curr->ptr != NULL)
            {
                i++;
                curr= curr->ptr;
            }
        }
        return i+1;
    }

};


int main()
{
    strClass str;

    str = str + 'a';
    str = str + 'b';
    str = str + 'c';
    str = str + 'd';
    str = str + "hello";

    cout << "str = " <<  str << endl;
    cout << "length of str = " << str.length() << endl;

    cout << "**********" << endl;
    cout << "**********" << endl;
    return 0;
}