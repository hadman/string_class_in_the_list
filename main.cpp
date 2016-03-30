#include <iostream>


using namespace std;
struct elem {
    char info;
    struct elem *ptr;
};


// ввести указатель на конец                                    OK
// метод линейного поиска подстроки х 2 для объекта и строки    OK
// метод копирования с какого-то символа по указанную длину     OK
// отдельно написать метод: найти все вхождения и заменить
// перегрузить в обе стороны


class strClass {
private:
    elem *head;
    elem *tail;
    void add(char a) {
        elem *e = new elem; // выделяем память под структуру
        e->info = a;
        e->ptr = NULL;

        if(tail == NULL)
        {
            head = e;
            tail = head;
        } else
        {
            tail->ptr=e;
            tail = tail->ptr; // хвост указывает на только что добавленный
        }
    }


public:

    strClass() // КОНСТРУКТОР
    {
        head = NULL;
        tail = NULL;
    }
    strClass(string str) // КОНСТРУКТОР
    {
        head = NULL;
        tail = NULL;
        for (int i = 0; i < str.length(); ++i) {
            add(str[i]);
        }
    }

    strClass(char a) // КОНСТРУКТОР
    {
        head = NULL;
        tail = NULL;
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
        tail = NULL;
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
                        //cout << "prev " << prev->info << endl;
                        delete[] prev; // удаляем предыдущий узел
                        prev = curr;
                        curr = curr->ptr;
                    }
                    //cout << "prev " << prev->info << endl;
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

    friend strClass operator+(string str, strClass& obj); // КОНКАТЕНАЦИЯ СТРОКИ.

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

    strClass Copy(int a, int len) // КОПИРОВАНИЕ ПОДСТРОКИ. РАБОТАЕТ
    {
        strClass tmp;
        elem* curr = head;
        int i=0;
        while (curr != NULL && i < a + len) // поиск
        {
            if(i >= a)
            {
                tmp.add(curr->info);
            }
            i++;
            curr = curr->ptr;
        }

        return tmp;
    }

    int search(string needle) // Поиск string в strClass. РАБОТАЕТ
    {
        elem* curr = head;
        int j;
        if(curr != NULL && needle.length() != 0 && needle.length() <= this->length()) // если стог и иголка не нулевые, иголка меньше стога
        {
            int i = 0;
            do
            {
                elem* tmp = curr;
                j = 0;
                //cout << "tmp->info = " << tmp->info << endl;
                while(tmp->info == needle[j]) // идем по needle
                {
                    j++;
                    if (tmp->ptr == NULL)
                    {
                        break;
                    }
                    tmp=tmp->ptr;
                }
                if (j == needle.length())
                {
                    return i;
                }
                curr = curr->ptr;
                i++;
            }while(i < (this->length()-needle.length()));
        }
        return -1;
    }

    int search(strClass needle) // Поиск strClass в strClass. РАБОТАЕТ
    {
        elem* currH = head;
        int j;
        elem* currN;
        if(currH != NULL && needle.length() != 0 && needle.length() <= this->length()) // если стог и иголка не нулевые, иголка меньше стога
        {
            int i = 0;
            do
            {
                elem* tmp = currH;
                j = 0;
                currN = needle.head;
                //cout << "tmp->info = " << tmp->info << endl;
                while(tmp->info == currN->info) // идем по needle
                {
                    j++;
                    if (tmp->ptr == NULL || currN->ptr == NULL)
                    {
                        break;
                    }
                    tmp=tmp->ptr;
                    currN=currN->ptr;
                }
                if (j == needle.length())
                {
                    return i;
                }
                currH = currH->ptr;
                i++;
            }while(i < (this->length()-needle.length()));
        }
        return -1;
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

strClass operator+(string str, strClass& obj) // КОНКАТЕНАЦИЯ СТРОКИ.
{
    string tmpStr=str;
    elem* curr = obj.head;
    while (curr != NULL)
    {
        tmpStr += curr->info; // посимвольно записываем в string
        curr = curr->ptr;
    }
    //cout << "tmp = " << tmpStr << endl;
    strClass tmp(tmpStr);
    return tmp;
}

strClass searchAndReplace(strClass& obj, strClass& seach, strClass& replace)
{
    strClass tmp(obj);
    strClass left;
    strClass right(tmp);
    if (right.search(seach) != -1)
    {
        int i = right.search(seach);
        strClass left = right.Copy(0,i);
        //cout << "left = " << left << endl;
        strClass right = tmp.Copy(i+seach.length(), tmp.length()-(i+seach.length()));
        //cout << "right = " << right << endl;
        if (right.search(seach) != -1)
        {
            right = searchAndReplace(right,seach,replace);
            //cout << "new right = " << right << endl;
            tmp = left + replace + right;
        } else
        {
            tmp = left + replace + right;
        }
    }else
    {
        return tmp;
    }
    return tmp;
}


int main() {

    strClass str("hello World");
    strClass s("d");
    strClass r("a");

    cout << "seaach rep = " << searchAndReplace(str,s,r) << endl;

    cout << str.search("d") << endl;

    cout << "str = " << str << "; length = " << str.length() << endl;
    cout << "**********" << endl;
    //string needle = "l";
//    cout << "search = " << str.search(str1) << endl;

    return 0;
}