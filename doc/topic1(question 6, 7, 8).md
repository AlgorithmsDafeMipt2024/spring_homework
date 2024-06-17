# Стеки, Очереди, Деки (C++)

## Стек

### Определение

Стеком (англ. stack) называется хранилище данных, в котором можно работать только с одним элементом: тем, который был добавлен в стек последним. Стек должен поддерживать следующие операции:

- `push`: Добавить (положить) в конец стека новый элемент.
- `pop`: Извлечь из стека последний элемент.
- `back`: Узнать значение последнего элемента (не удаляя его).
- `size`: Узнать количество элементов в стеке.
- `clear`: Очистить стек (удалить из него все элементы).

### Структура данных Stack

- stack();               // Конструктор
- ~stack();              // Деструктор
- void push(int d);      // Добавить в стек новый элемент
- int pop();             // Удалить из стека последний элемент и вернуть его значение
- int back();            // Вернуть значение последнего элемента
- int size();            // Вернуть количество элементов в стеке
- void clear();          // Очистить стек


## Очередь

### Определение

Очередью (англ. queue) называется структура данных, в которой элементы кладутся в конец, а извлекаются из начала. Первым из очереди будет извлечен тот элемент, который будет добавлен раньше других.

### Структура данных Queue

- queue();               // Конструктор
- ~queue();              // Деструктор
- void push(int d);      // Добавить в очередь новый элемент
- int pop();             // Удалить из очереди первый элемент и вернуть его значение
- int front();           // Вернуть значение первого элемента
- int size();            // Вернуть количество элементов в очереди
- void clear();          // Очистить очередь

## Дек

### Определение

Деком (англ. deque – аббревиатура от double-ended queue, двухсторонняя очередь) называется структура данных, в которую можно удалять и добавлять элементы как в начало, так и в конец.

### Структура данных Deque

- push_front Добавить (положить) в начало дека новый элемент 
- push_back Добавить (положить) в конец дека новый элемент 
- pop_front Извлечь из дека первый элемент 
- pop_back Извлечь из дека последний элемент 
- front Узнать значение первого элемента (не удаляя его) 
- back Узнать значение последнего элемента (не удаляя его) 
- size Узнать количество элементов в деке 
- clear Очистить дек (удалить из него все элементы) 


## Упражнения

### Упражнение A - Простой стек

- Реализуйте структуру данных "стек", реализовав все указанные методы.
- Напишите программу (функцию main), содержащую описание стека и моделирующую работу стека.

### Упражнение B - Стек с обработкой ошибок

- Аналогично предыдущему заданию, только снимается ограничение на корректность вызовов методов back и pop.

### Упражнение C - Стек без ограничения на размер

- Реализуйте стек динамического размера, то есть ограниченный только объемом свободной оперативной памяти.

### Упражнение D - Простая очередь

- Реализуйте простейшую очередь, размер которой не превосходит 100 элементов.

### Упражнение E - Очередь с обработкой ошибок

- Аналогично заданию B, но для очереди.

### Упражнение F - Очередь без ограничений на размер

- Аналогично заданию C, но для очереди.

### Упражнение G - Простой дек

- Аналогично заданиям A и D, но для дека.

### Упражнение H - Дек с обработкой ошибок

- Аналогично заданиям B и E, но для дека.

### Упражнение I - Дек неограниченного размера

- Аналогично заданию C и F, но для дека.