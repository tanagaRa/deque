#include "deque.h"
#include <stdlib.h>
#include <time.h>

int main() {
    system("cls");
    int check = 1;
    while (check == 1) {
        CDeque <int> ideq, ideq1;
        CDeque <double> ddeq, ddeq1;
        CDeque <const char* > chdeq, chdeq1;
        srand(time(NULL));
        std::cout<<"Выберите тип дека: \n1. Int\n2. Double\n3. Const char *\nВаш выбор: ";
        int n, t, r;
        char b;
        cin>>n;
        while(n<1 || n>3) {
            std::cout<< "Число не соответствует запросу. Повторите ввод: ";
            std::cin>>n;
        }
        switch (n) {
        case 1:
            cout<<"Введите какое количество элементов хотите увидеть в деке: ";
            cin>>t;
            while(t<0) {
                cout<< "Отрицательное число не соответствует запросу. Повторите ввод: ";
                cin>>t;
            }
            for(int i = 0; i<t;i++) {
                r = rand()%28;
                if(i%2 == 0) {
                    ideq.pushFront(r);
                }
                else {
                    ideq.pushBack(r);
                }
            }
            cout<<"Ввывод дека с начала: \n";
            ideq.outputFromFront(cout);
            cout<<"Ввывод дека с конца: \n";
            ideq.outputFromBack(cout);
            cout<<"Удалить первый элемент дека?(Y/n)";
            cin>>b;
            if(b == 'Y' || b == 'y') {
                ideq.popFront();
                cout<<"Ввывод получившегося дека с начала: \n";
                ideq.outputFromFront(cout);
            }
            cout<<"Удалить последний элемент дека?(Y/n)";
            cin>>b;
            if(b == 'Y' || b == 'y') {
                ideq.popBack();
                cout<<"Ввывод получившегося дека с начала: \n";
                ideq.outputFromFront(cout);
            }
            t = ideq.getFirst();
            cout<<"Первый элемент дека: "<< t<<endl;
            t = ideq.getLast();
            cout<<"Последний элемент дека: "<< t<<endl;
            cout<<"Размер вашего дека: "<<ideq.getSize()<<endl;
            cout<<"Проверка оператора присваивания. Введите один элемент: ";
            cin>>t;
            ideq1.pushFront(t);
            ideq = ideq1;
            ideq.outputFromBack(cout);
            cout<<"Изменённый дек: ";
            break;
        case 2:
            double d;
            cout<<"Введите какое количество элементов хотите увидеть в деке: ";
            cin>>t;
            while(t<0) {
                cout<< "Отрицательное число не соответствует запросу. Повторите ввод: ";
                cin>>t;
            }
            for(int i = 0; i<t;i++) {
                r = (rand()%28)*0.7;
                if(i%2 == 0) {
                    ddeq.pushFront(r);
                }
                else {
                    ddeq.pushBack(r);
                }
            }
            cout<<"Ввывод дека с начала: \n";
            ddeq.outputFromFront(cout);
            cout<<"Ввывод дека с конца: \n";
            ddeq.outputFromBack(cout);
            cout<<"Удалить первый элемент дека?(Y/n)";
            cin>>b;
            if(b == 'Y' || b == 'y') {
                ddeq.popFront();
                cout<<"Ввывод получившегося дека с начала: \n";
                ddeq.outputFromFront(cout);
            }
            cout<<"Удалить последний элемент дека?(Y/n)";
            cin>>b;
            if(b == 'Y' || b == 'y') {
                ddeq.popBack();
                cout<<"Ввывод получившегося дека с начала: \n";
                ddeq.outputFromFront(cout);
            }
            d = ddeq.getFirst();
            cout<<"Первый элемент дека: "<< d <<endl;
            d = ddeq.getLast();
            cout<<"Последний элемент дека: "<< d <<endl;
            cout<<"Размер вашего дека: "<<ddeq.getSize()<<endl;
            cout<<"Проверка оператора присваивания. Введите один элемент: ";
            cin>>t;
            ddeq1.pushFront(t);
            ddeq = ddeq1;
            cout<<"Изменённый дек: ";
            ddeq.outputFromBack(cout);
            break;

        case 3:
            char *a = new char [70];
            const char * c = new char [70];
            cout<<"Введите какое количество элементов хотите увидеть в деке: ";
            cin>>t;
            while(t<0) {
                cout<< "Отрицательное число не соответствует запросу. Повторите ввод: ";
                cin>>t;
            }
            cout<<"Введите эти элементы: ";
            for(int i = 0; i<t;i++) {
                cin>>a;
                if(i%2 == 0) {
                    chdeq.pushFront(a);
                }
                else {
                    chdeq.pushBack(a);
                }
            }
            cout<<"Ввывод дека с начала: \n";
            chdeq.outputFromFront(cout);
            cout<<"Ввывод дека с конца: \n";
            chdeq.outputFromBack(cout);
            cout<<"Удалить первый элемент дека?(Y/n)";
            cin>>b;
            if(b == 'Y' || b == 'y') {
                chdeq.popFront();
                cout<<"Ввывод получившегося дека с начала: \n";
                chdeq.outputFromFront(cout);
            }
            cout<<"Удалить последний элемент дека?(Y/n)";
            cin>>b;
            if(b == 'Y' || b == 'y') {
                chdeq.popBack();
                cout<<"Ввывод получившегося дека с начала: \n";
                chdeq.outputFromFront(cout);
            }
            c = chdeq.getFirst();
            cout<<"Первый элемент дека: "<< c <<endl;
            c = chdeq.getLast();
            cout<<"Последний элемент дека: "<< c <<endl;
            cout<<"Размер вашего дека: "<<chdeq.getSize()<<endl;
            cout<<"Проверка оператора присваивания. Введите один элемент: ";
            cin>>a;
            chdeq1.pushFront(a);
            chdeq = chdeq1;
            cout<<"Изменённый дек: ";
            chdeq.outputFromBack(cout);
            break;    
        }
        cout<<"Для продолжения работы введите 1\nДля завершения работы введите 0."<<endl;
        cout<<"Ваш выбор: ";
        cin>>check;
        if (check > 1 || check < 0) {
            cout<<"Неправильный ввод, работа автоматически завершена.\n";
        }
    }
    cout<<"С наступающим Новым годом и хорошего времени суток!:)";
} 