# Программа для тестирования слов английского языка
Курсовая работа по ТРПО, курс 1
[![Build Status](https://travis-ci.com/GoldAndPurple/TranslateTest.svg?branch=master)](https://travis-ci.com/GoldAndPurple/TranslateTest)
# Установка библиотеки gtk
Ubuntu: 
1. apt-get install -qq libgtk-3-dev

Windows:
1. Установить msys2
2. Скачать инструменты
```
pacman -S mingw-w64-x86_64-gtk3 
pacman -S mingw-w64-x86_64-toolchain base-devel
```
3. Добавить последующие строки в .bashrc
```
export PKG_CONFIG_PATH=/mingw64/lib/pkgconfig:/mingw64/share/pkgconfig
export PATH=/mingw64/bin:$PATH
export PATH=/usr/bin:$PATH
```
# Запуск приложения
```
make
cd bin
./translate.exe
```
