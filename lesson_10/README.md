# Занятие 10

#### 29.01.2021

## Работа с файлами в C

### Материалы с необходимыми (но не обязательно достаточными) для выполнения домашки знаниями

1. [Про работу с текстовыми файлами](https://learnc.info/c/text_files.html)
2. [Шифр Цезаря](https://ru.wikipedia.org/wiki/%D0%A8%D0%B8%D1%84%D1%80_%D0%A6%D0%B5%D0%B7%D0%B0%D1%80%D1%8F)


## Домашнее задание

#### 1
Написать программу, которая открывает файл в режиме записи, записывает строку или несколько строк в файл, закрывает файл и открывает в режиме чтения (или переоткрывает в режим чтения), после чего выводит содержимое файла в терминал. При записи использовать относительный путь до файла, при чтении -- абсолютный.

#### 2
То же, что и номере 1, но строку для записи в файл вводит пользователь через терминал. Не забудьте ограничить длину считываемой строки.

#### 3
Напишите программу, которая зашифровывает строку, считанную из терминала, шифром Цезаря (действует только на цифры и буквы), после чего записывает обработанную строку в файл.

#### 4
Напишите программу, которая делает обратное к номеру 3 -- считывает строку из файла и расшифровывает ее.