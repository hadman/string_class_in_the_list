#include <iostream>

using namespace std;
struct elem {
    char info;
    struct elem *ptr;
};


//ввести указатель на конец
//метод линейного поиска подстроки х 2 для объекта и строки
//метод копирования с какого-то символа по указанную длину
//отдельно написать метод: найти все вхождения и заменить
// перегрузить в обе стороны

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
    strClass(string str) // КОНСТРУКТОР
    {
        head = NULL;
        for (int i = 0; i < str.length(); ++i) {
            add(str[i]);
        }
    }

    strClass(char a) // КОНСТРУКТОР
    {
        head = NULL;
        add(a);
    }

    ~strClass() // ДЕСТРУКТОР .РАБОТАЕТ
    {
        elem *prev = head; // 1-й узел
        if (prev != NULL) // если список уже не нулевой
        {
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
    }

    strClass(const strClass &another) // КОНСТРУКТОР КОПИРОВАНИЯ. РАБОТАЕТ
    {
        head = NULL;
        elem* curr = another.head;
        while (curr != NULL)
        {
            add(curr->info);
            curr = curr->ptr;
        }
    }

    strClass &operator=(strClass another) // ПРИСВАИВАНИЕ ОБЪЕКТА. РАБОТАЕТ
    {
        if (head == another.head) // самоприсваивание
        {
            return *this;
        }
        elem* curr = head;
        elem* currAnother = another.head;
        elem*prev;
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
                if(curr == NULL) // если another > this
                {
                    while (currAnother != NULL)
                    {
                        add(currAnother->info);
                        currAnother = currAnother->ptr;
                    }
                }

            } else // удаляем список this
            {
                if(head != NULL) // если он уже не пустой
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
        int i = 1;
        elem* curr = head;
        elem*prev;
            while (curr != NULL && i <= 1)
            {
//                curr->info=a;
                prev = curr; // запоминам предыдущий
                curr = curr->ptr;
                i++;
                //cout << "while" << endl;
            }
            if (curr != NULL) // если остались свободные узлы
            {
                prev->ptr = NULL; // теперь он последний
                prev = curr;
                curr = curr->ptr;
                while (curr != NULL) {
                    //cout << "prev " << prev->info << endl;
                    delete[] prev; // удаляем предыдущий узел
                    prev = curr;
                    curr = curr->ptr;
                }
                //cout << "prev " << prev->info << endl;
                delete[] prev;
            }
            if (head == NULL)
            {
                add(a);
                //cout << "head = NULL" << endl;
            }else
                if (curr == NULL)
                {
                    head->info=a;
                   // cout << "curr = NULL" << endl;
                }
//        elem *prev = head; // 1-й узел
//        if (prev != NULL)
//        {
//            elem *curr = prev->ptr; // 2-й узел
//            while (curr != NULL)
//            {
//                //cout << "prev = "<< prev->info << endl;
//                delete[] prev; // удаляем предыдущий узел
//                prev = curr;
//
//                curr = curr->ptr;
//            }
//            //cout << "prev = "<< prev->info << endl;
//            delete[] prev; // удаляем последний узел
//            head = NULL; // зануляем список
//        }
//        add(a);
    }

    strClass &operator=(string str) // ПРИСВАИВАНИЕ СТРОКИ.РАБОТАЕТ
    {
        int i=0;
        elem* curr = head;
        elem*prev;
//        if(curr != NULL) // если список не пустой
//        {
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
                    prev->ptr = NULL; // теперь он последний
                    prev = curr;
                    curr = curr->ptr;
                    while (curr != NULL) {
                        //cout << "prev " << prev->info << endl;
                        delete[] prev; // удаляем предыдущий узел
                        prev = curr;
                        curr = curr->ptr;
                    }
                    //cout << "prev " << prev->info << endl;
                    delete[] prev;
                }
                if (curr == NULL)
                {
                    while (i < str.length()) {
                        add(str[i]);
                        i++;
                    }
                }
            }else // если строка пуста
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



    strClass operator+(char a) // КОНКАТЕНАЦИЯ СИМВОЛА. РАБОТАЕТ
    {
        strClass tmp(*this); // создаем копию
        tmp.add(a);
//        cout << "obj= " << tmp << endl;
        return tmp;
    }

    strClass operator+(string str) // КОНКАТЕНАЦИЯ СТРОКИ. РАБОТАЕТ
    {
        strClass tmp(*this); // создаем копию
        for (int i = 0; i < str.length(); ++i) {
            tmp.add(str[i]);
        }
//        cout << "obj= " << tmp << endl;
//        cout << "obj adress= " << tmp.head << endl;
        return tmp;
    }

    strClass operator+(strClass &another) // КОНКАТЕНАЦИЯ ОБЪЕКТА. РАБОТАЕТ
    {
        strClass tmp(*this); // создаем копию
//        cout << "head = " << head << endl;
//        cout << "head another = " << another.head << endl;
        elem *currAnother = another.head;
        if (currAnother == NULL) // если объект пустой
        {
            return *this;
        } else // если объект не пустой
        {
            while (currAnother != NULL) {
                tmp.add(currAnother->info);
                currAnother = currAnother->ptr;
            }
        }
        return tmp;
    }

    friend ostream &operator<<(ostream &out, const strClass &obj) // ПЕРЕГРУЗКА ПОТОКА
    {
        //cout << "memory OBJ = " << obj.head << endl;
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

    // поик подстроки -2
   //выделение подстроки

};


int main() {
    strClass str("HEllo World");
    strClass str1 ( str + ' ' + "****" + ' '  + str);
    str =  ' '  + str1;

    cout << "**********" << endl;



    cout << "str = " << str << "; length = " << str.length() << endl;
    cout << "**********" << endl;

    cout << "str1 = " << str1 << "; length = " << str1.length() << endl;
    cout << "**********" << endl;

    return 0;
}