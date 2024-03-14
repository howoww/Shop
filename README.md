# Курсовой проект: Магазин
## Описание
Этот проект представляет собой программу для управления данными о товарах и пользователях в магазине. Программа реализует функционал администратора и пользователя, а также предоставляет возможность сортировки товаров и экспорта/импорта данных в формате CSV. Реализован с применением архитектурного паттерна MVC. Проект выполнен на языке программирования C++.

## Функциональность
- Добавление, удаление и редактирование данных о товарах.
- Добавление, удаление и редактирование данных о пользователях.
- Два режима доступа: "Администратор" и "Пользователь".
- Возможность сортировки товаров.
- Экспорт и импорт данных в формате CSV.

##Использование
1. Склонируйте репозиторий на свой локальный компьютер.
2. Соберите проект с помощью компилятора C++ (например, g++).
3. Запустите программу, выполнив получившийся исполняемый файл.
4. Войдите как администратор или пользователь (Логин и пароль администратора *admin*).
5. Для администратора:
5.1. Добавьте, удалите или измените данные о товарах и пользователях.
5.2. Используйте функцию сортировки товаров.
5.3. Экспортируйте данные в CSV или импортируйте их из CSV.
6.  Для пользователя:
6.1. Просматривайте доступные товары.
6.2. Можете использовать функцию сортировки товаров, если доступно.

## Требования к сборке
- Компилятор C++ (например, g++)
- Стандартная библиотека C++

## Структура проекта
### Модель
"**IDomain**": Интерфейс для базового доменного объекта (*Идентификация пользователя и товара*).
"**Product**": Класс, представляющий товар.
"**User**": Класс, представляющий пользователя.
"**IRepository**": Интерфейс для репозитория.
"**ProductRepository**": Класс, реализующий репозиторий товаров.
"**UserRepository**": Класс, реализующий репозиторий пользователей.
"**AuthorizationService**": Класс, обеспечивающий авторизацию пользователей.
### Контроллеры
"**MainController**": Главный контроллер, координирующий работу других контроллеров.
"**ProductController**": Контроллер для управления товарами.
"**UserController**": Контроллер для управления пользователями.
### Представление
"**MenuView**": Отображение главного меню.
"**ConsoleInputView**": Отображение ввода данных через консоль.

## Автор
Никита (@HowWow)

## Лицензия
Этот проект лицензирован по лицензии MIT License.