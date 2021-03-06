# Занятие 5

#### 27.11.2020

## Многомерные массивы. Указатели. Адреса. Ссылки. Строки (`string.h`)

### Многомерные массивы. Указатели. Адреса. Ссылки.
Если про указатели и массивы еще не читали, то читать по ссылкам ниже


Более подробно можно прочитать тут :  
+ [https://learnc.info/c/multidimensional_arrays.html](https://learnc.info/c/multidimensional_arrays.html)  
+ [https://learnc.info/c/pointers.html](https://learnc.info/c/pointers.html)  
+ [https://learnc.info/c/arrays_vs_pointers.html](https://learnc.info/c/arrays_vs_pointers.html)  


### Строки (`string.h`)
Про сами строки повторить по первой ссылке, про заголовочный файл `string.h` почитать документацию (любой подходящий Вам вариант). Для выполнения домашнего задания также почтиайте документацию на `scanf()` и то, как именно он работает.



+ [https://learnc.info/c/strings.html](https://learnc.info/c/strings.html)
+ [Здесь читать про `scanf()` и спецификатор вида `%5s`, вместо пяти -- любое натуральное число](https://learnc.info/c/formatted_input_output.html)

## Домашнее задание

#### 0
Создать переменную любого типа и указатели того же типа, которые будут инициализированы адресом начальной переменной:
1. с неизменяемым адресом, но изменяемым содержимым;
2. с изменяемым адресом, но содержимое с использованием этого указателя изменить нельзя;
3. с неизменяемым адресом и содержимым;
4. обычный указатель и указатель на него (указатель на указатель).  
Вывести переменную с помоью каждого из объявленных указателей, после чего с помощью каждого указателя, который поддерживает изменение содержимого, увеличить значение переменной на единицу и вывести ее значение. Вывести, что лежит в соседних ячейках памяти от переменной.

#### 1
Создать многомерный статический массив произвольной формы, инициализировать как считаете необходимым, вывести все элементы массива, используя только один индекс и указатель на нулевой элемент массива.

#### 2
Напишите программу, которая считывает 2 строки, выводит их длины и проверяет их на равенство, после чего выводит результат проверки (**с использованием `string.h`**) и количество символов до первого расхождения.

#### 3
Напишите программу, принимающую на вход строку, ограниченную по длине 16 **значащими** символами. Если строка короче, дозаполнить символом '\*' до 16 символов, вывести строку. Сделать из первых 8 элементов строки палиндром, вывести то, что получилось. Например: вводим "abcdefghijklmnop", выводим "abcdefghhgfedcba", вводим "привет", выводим "привет\*\*\*\*тевирп". **Используйте функции из `string.h`**.

#### 4* (повторение и `scanf()`)
Пользователь вводит числа (выберите максимально универсальный тип данных), их количество неизвестно. После ввода каждого числа выводится среднее арифметическое уже введенных чисел. Реализуйте такую программу с использованием одного цикла, одного вызова `scanf()` в теле цикла и без использования любого вида массивов. Если пользователь вводит не числовой символ (букву, знак препинания и тд), то программа завершает работу.

#### 5** (необязательная)
В Яндекс.Такси оценка пользователя водителями расчитывается как взвешенное среднее последних `N` оценок, причем свежие оценки имеют большее влияние на результат, чем старые. Реализуте такой алгоритм, который по вводимым пользователем числам вычислял бы такое среднее. Условие завершения работы такое же, как в предыдущей задаче. [Статья Яндекса про это.](https://pro.yandex/ru-ru/moskva/base/raiting)
