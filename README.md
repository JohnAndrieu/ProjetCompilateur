# Projet Compilateur

#### How to use it

```
git clone https://github.com/JohnAndrieu/ProjetCompilateur
cd ProjetCompilateur/sources
make
./comp < hello.c
```

We can also use this command to run the program and catch the tokens read

```
./comp < hello.c  2>&1 | grep Read
```
