# Projet Compilateur

Jonathan Andrieu - Yanis Imekraz

#### How to use it

```
git clone https://github.com/JohnAndrieu/ProjetCompilateur
cd ProjetCompilateur/sources
make
./comp < hello.c
```

#### We can also use this command to run the program and catch the tokens read

```
./comp < hello.c  2>&1 | grep Read
```

## Avancee

- Analyse lexicale et communication des tokens et leur valeur vers yacc		- OK

- Table des symboles et les fonctions pour gérer la table                 - OK

- Générer du code assembleur pour calcul arithmétique                     - OK

-	Générer du code assembleur pour if-else/while	                          - OK
