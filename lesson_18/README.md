# Занятие 18

#### 26.03.2021

## Структуры

### Материалы с необходимыми (но не обязательно достаточными) для выполнения домашки знаниями

1. [Про структуры](https://rtfm.co.ua/c-struktury/)  
2. [Про указатели на структуру и оператор стрелка](http://www.c-cpp.ru/books/ispolzovanie-ukazateley-na-strukturu)  
3. [Про односвязный список на структурах](https://learnc.info/adt/linked_list.html)
4. [Про двусвязный список на структурах](https://learnc.info/adt/double_linked_list.html)   
5. [Про стэк на структурах](https://learnc.info/adt/stack.html)

Самостоятельный поиск материалов приветствуется!  

## Домашнее задание

Дополнить код из файла `26_03_2021.c` функцией `void shift(DLL* list, int n)`, которая сдвинет указатель на текущий элемент циклического двусвязного списка на `n`. Учесть, что положительные `n` -- сдвиг вперед, а отрицательные -- назад.