#include <iostream>

using namespace std;
struct elem {
    char info;
    struct elem *ptr;
};

class strClass {
private:
    elem *head;

    void add(char a) {
        elem *curr = head; // запоминаем
        elem *e = new elem; // выделяем память под структуру
        e->info = a;
        if (curr == NULL) // если строка была пустой
        {
            head = e;
            head->ptr = NULL; // указатель на конец строки
        } else {
            while (curr->ptr != NULL) // ищем последний элемент списка
            {
                curr = curr->ptr;
            }
            curr->ptr = e;
            e->ptr = NULL; // теперь e - последний элемент списка
        }
    }

public:
    strClass() // КОНСТРУКТОР
    {
        head = NULL;
    }

    ~strClass() // ДЕСТРУКТОР
    {
        elem *prev = head; // 1-й узел
        elem *curr = prev->ptr; // 2-й узел
        while (curr != NULL)
        {
            //cout << "prev = "<< prev->info << endl;
            delete[] prev; // удаляем предыдущий узел
            prev = curr;

            curr = curr->ptr;
        }
        //cout << "prev = "<< prev->info << endl;
        delete[] prev; // удаляем последний узел
        head = NULL; // зануляем список
    }

    strClass(strClass &another) // КОНСТРУКТОР КОПИРОВАНИЯ. рпботает неправильно
    {
        elem *head = new elem;
        elem *curr = another.head;

        while (curr != NULL) {
            this->add(curr->info);
            curr = curr->ptr;
        }
    }

    strClass &operator=(strClass &another) // ПРИСВАИВАНИЕ ОБЪЕКТА.
    {
        if (head == another.head) // самоприсваивание
        {
            return *this;
        }
        elem* curr = head;
        elem* currAnother = another.head;
        elem*prev;
        if(curr != NULL) // если this непуста
        {
            if(currAnother != NULL) // если another непуста
            {
                while (curr != NULL && currAnother != NULL)
                {
                    curr->info=currAnother->info;
                    prev = curr; // запоминам предыдущий
                    curr = curr->ptr;
                    currAnother = currAnother->ptr;
                }
                if (curr != NULL) // если остались свободные узлы
                {
                    prev->ptr=NULL; // теперь он последний
                    prev = curr;
                    curr = curr->ptr;
                    while (curr != NULL)
                    {
                        cout << "prev " << prev->info << endl;
                        delete[] prev; // удаляем предыдущий узел
                        prev = curr;
                        curr = curr->ptr;
                    }
                    cout << "prev " << prev->info << endl;
                    delete[] prev;
                }
            } else // удаляем список this
            {
                prev = head; // 1-й узел
                curr = prev->ptr; // 2-й узел
                while (curr != NULL)
                {
                    cout << "prev = "<< prev->info << endl;
                    delete[] prev; // удаляем предыдущий узел
                    prev = curr;

                    curr = curr->ptr;
                }
                cout << "prev = "<< prev->info << endl;
                delete[] prev; // удаляем последний узел
                head = NULL; // зануляем список
            }
        }
    }

    strClass &operator=(char a) // ПРИСВАИВАНИЕ СИМВОЛА
    {

        if(head != NULL)
        {


            elem *prev = head->ptr; // 2-й узел
            elem *curr = prev->ptr; // 3-й узел

            head->info = a;
            head->ptr = NULL;

            while (curr != NULL)
            {
                //cout << "prev " << prev->info << endl;
                delete[] prev; // удаляем предыдущий узел
                prev = curr;
                curr = curr->ptr;
            }
            //cout << "prev " << prev->info << endl;
            delete[] prev;
        }
    }

    strClass &operator=(string str) // ПРИСВАИВАНИЕ СТРОКИ
    {
        int i=0;
        elem* curr = head;
        elem*prev;
        if(curr != NULL) // если список не пустой
        {
            if(str.length()!=0) // если строка не пустая
            {
                while (curr != NULL && i < str.length())
                {
                    curr->info=str[i];
                    prev = curr; // запоминам предыдущий
                    curr = curr->ptr;
                    i++;
                }
                if (curr != NULL) // если остались свободные узлы
                {
                    prev->ptr=NULL; // теперь он последний
                    prev = curr;
                    curr = curr->ptr;
                    while (curr != NULL)
                    {
                        //cout << "prev " << prev->info << endl;
                        delete[] prev; // удаляем предыдущий узел
                        prev = curr;
                        curr = curr->ptr;
                    }
                    //cout << "prev " << prev->info << endl;
                    delete[] prev;
                }
            }else // если список не пуст, а строка пуста
            {
                prev = head; // 1-й узел
                curr = prev->ptr; // 2-й узел
                while (curr != NULL)
                {
                    //cout << "prev = "<< prev->info << endl;
                    delete[] prev; // удаляем предыдущий узел
                    prev = curr;

                    curr = curr->ptr;
                }
                //cout << "prev = "<< prev->info << endl;
                delete[] prev; // удаляем последний узел
                head = NULL; // зануляем список
            }
        }
    }


    strClass &operator+(char a) // КОНКАТЕНАЦИЯ СИМВОЛА
    {
        this->add(a);
        return *this;
    }

    strClass &operator+(string str) // КОНКАТЕНАЦИЯ СТРОКИ
    {
        for (int i = 0; i < str.length(); ++i) {
            this->add(str[i]);
        }
        return *this;
    }

    strClass &operator+(strClass &another) // КОНКАТЕНАЦИЯ ОБЪЕКТА. не работает если складываем 2 одинаковых объекта
    {
        elem *curr = another.head;
        if (curr == NULL) // если объект пустой
        {
            return *this;
        } else // если объект не пустой
        {
            while (curr != NULL) {
                this->add(curr->info);
                curr = curr->ptr;
            }
        }
        return *this;
    }

    friend ostream &operator<<(ostream &out, const strClass &obj) // ПЕРЕГРУЗКА ПОТОКА
    {
        elem *curr = obj.head;
        if (curr == NULL) {
            out << " ";
        } else {
            while (curr != NULL) {
                out << curr->info;
                curr = curr->ptr;
            }
        }
        return out;
    }

    int length() {
        int i = 0;
        elem *curr = head;
        if (curr == NULL) {
            return 0;
        } else {
            while (curr->ptr != NULL) {
                i++;
                curr = curr->ptr;
            }
        }
        return i + 1;
    }

};


int main() {
    strClass str;

    str = str + 'a';
    str = str + 'b';
    str = str + 'c';
    str = str + 'd';
    str = str + "hello";

    strClass str2;

    cout << "str = " << str << endl;
    cout << "length of str = " << str.length() << endl;
    cout << "**********" << endl;


    cout << "str2 = " << str2 << endl;
    cout << "length of str2 = " << str2.length() << endl;


//    cout << "str2 = " << str2 << endl;




    cout << "**********" << endl;
    return 0;
}