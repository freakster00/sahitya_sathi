@echo off

cd content\posts
g++ gui_.c -o gui_output.exe `pkg-config --cflags --libs gtk+-3.0`
start "" gui_output.exe

rem gcc add_new_blog.c -o program_.exe
rem program_.exe

exit
