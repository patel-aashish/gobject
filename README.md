# gobject
Gobject learning repo

- example person following the youtube video https://www.youtube.com/watch?v=1-_EBEr0fxI&t=291s
- shape following http://www.wl-chuang.com/blog/categories/gobject/ blogs 
- official documentation: https://developer.gnome.org/gobject/stable/index.html

# how to compile
## example-person
```cd example-person```
```gcc -Wall -c -o libtest.so example-person.c `pkg-config --cflags --libs gobject-2.0```