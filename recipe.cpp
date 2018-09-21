/*
Написать класс "Книга рецептов". В классе хранится динамически расширяемый массив, в котором хранится структура Recipe со следующими полями: название блюда, главный ингредиент, время приготовления.

Реализовать следующие методы:

(Держать рецепты отсортированными по ингредиентам, путем вставки элемента в нужное место в массиве)
Объединение книг рецептов
Добавление рецепта
Сохранение/восстановление данных из файла
*/
#include <iostream>
#include <string.h>
using namespace std;
struct Recipe{
    char *name;
    char *mainingr;
    long time;
    friend ostream &operator << (ostream &out, Recipe &tmp)
        {
            out << tmp.name<<" "<<tmp.mainingr<<" "<<tmp.time<<endl;
            return out;
        }
    friend int operator < (Recipe o,Recipe a)
    {
        if(strcmp(o.mainingr,a.mainingr)>0) return 1;
        return 0;
    }

};

