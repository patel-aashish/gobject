# gobject
Gobject learning repo

- example person following the youtube video https://www.youtube.com/watch?v=1-_EBEr0fxI&t=291s
- shape following http://www.wl-chuang.com/blog/categories/gobject/ blogs
- https://syscall.org/doku.php/gobjectutorial/start#first_steps
- https://sgros.blogspot.com/2016/01/few-tips-about-gobject-for-oo.html
- https://habrahabr.info/development/gtk/119-gobject-inheritance-and-interfaces.html
- official documentation: https://developer.gnome.org/gobject/stable/index.html

# how to compile
## example-person
```cd example-person```
```
gcc -Wall -c -o libtest.so example-person.c `pkg-config --cflags --libs gobject-2.0`
```

## shape
```cd shape```
```mkdir -p build```
```cd build```
```cmake ..```
```make```
```./shape_test```

# how to check symbol
```nm <bin/lib name>```