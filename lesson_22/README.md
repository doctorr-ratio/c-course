# Занятие 22

#### 23.04.2021

## Быстрый обратный квадратный корень

### Материалы с необходимыми (но не обязательно достаточными) для выполнения домашки знаниями

1. [Хорошее видео на английском](https://www.youtube.com/watch?v=p8u_k2LIZyo)  
2. [Не очень понятная статья на вики](https://ru.wikipedia.org/wiki/%D0%91%D1%8B%D1%81%D1%82%D1%80%D1%8B%D0%B9_%D0%BE%D0%B1%D1%80%D0%B0%D1%82%D0%BD%D1%8B%D0%B9_%D0%BA%D0%B2%D0%B0%D0%B4%D1%80%D0%B0%D1%82%D0%BD%D1%8B%D0%B9_%D0%BA%D0%BE%D1%80%D0%B5%D0%BD%D1%8C)  
3. [Понятная статья на Хабре](https://habr.com/ru/company/infopulse/blog/336110/)


Самостоятельный поиск материалов приветствуется!  


### Задание для получения зачета

1. Создать массив чисел с плавающей точкой (`float`), заполнить его числами от 1 до 100 (или больше, на Ваше усмотрение) с шагом 1 (то есть 1, 2, 3 и тд), посчитать для него обратный корень поэлементно с помощью `1/sqrtf(x)` из `math.h` и с помощью функции `Q_rsqrt(x)` из приложенного файла (проверьте, что длина целого числа равна 4 байтам, как и у числа с плавающей точкой). Для этого создайте еще 1 массив того же типа. Для каждой точки также оцените абсолютную ошибку `1/sqrtf(x) - Q_rsqrt(x)`.
2. Записать текстовый файл `res.csv` со следующим форматом содержания:
`x,abs_accuracy`
где `x` — точка, в которой были вычислены обратные корни; `abs_accuracy` — абсолютное значение ошибки быстрого обратного корня относительно библиотечной функции: `1/sqrtf(x) - Q_rsqrt(x)`.
3. Сравнить время работы цикла с библиотечной функцией и цикла с быстрым обратным корнем. Результат вывести в командную строку без пересчета в секунды. Если запускаете компилятор руками в командной строке, попробуйте поставить флаг оптимизации -О3.