# cpp00-04 y tisabbat
# C++ — 42 School

Esercizi dei moduli C++00 → C++04 del curriculum di 42 School, dall'introduzione al linguaggio fino a polimorfismo, classi abstract e interfacce.

Ogni cartella `exXX` è autonoma: contiene il proprio `Makefile` e compila in isolamento con `clang++ -Wall -Wextra -Werror -std=c++98`.

## cpp00 — Introduzione a C++

| Ex | Argomento |
|----|-----------|
| `ex00` | **Megaphone** — primo programma C++: legge `argv`, converte in maiuscolo e stampa (introduzione a `std::string`, `std::cout`) |
| `ex01` | **PhoneBook** — classi `Contact`/`PhoneBook`, incapsulamento con membri privati e accessor, buffer circolare di 8 contatti |

## cpp01 — Memory allocation, reference, puntatori a funzioni membro

| Ex | Argomento |
|----|-----------|
| `ex00` | **Zombie** — `new`/`delete`, zombie su stack vs heap |
| `ex01` | **Zombie Horde** — array dinamico di oggetti con `new[]`/`delete[]` |
| `ex02` | **Unnecessary pointers** — differenza reference vs pointer sullo stesso oggetto |
| `ex03` | **Weapon / HumanA / HumanB** — reference a un membro (sempre valido) vs pointer (può essere nullo) |
| `ex04` | **Sed is for losers** — find & replace su file di testo, algoritmo a finestra scorrevole sulle stringhe |
| `ex05`/`ex06` | **Harl** — puntatori a funzioni membro per dispatchare i livelli di log senza `if/else` a catena |

## cpp02 — Ad-hoc polymorphism, Orthodox Canonical Form

| Ex | Argomento |
|----|-----------|
| `ex00` | **Fixed** — Orthodox Canonical Form, numero a virgola fissa rappresentato con bit-shifting su un intero (`_rawBits`, 8 bit fract.) |
| `ex01` | **Fixed** — costruttori/conversioni int↔float↔fixed, overload di `operator<<` |
| `ex02` | **Fixed** — operatori di confronto e aritmetici, `++`/`--` pre e post, `min`/`max` statici |
| `ex03` *(bonus)* | **Point + bsp()** — punto con coordinate `Fixed` const, test "punto dentro triangolo" via prodotto vettoriale |

## cpp03 — Inheritance

| Ex | Argomento |
|----|-----------|
| `ex00` | **ClapTrap** — OCF completa, HP/EP/AD, `attack()` con controllo delle risorse prima di agire |
| `ex01` | **ScavTrap** — eredita da ClapTrap, nuove statistiche, `guardGate()` |
| `ex02` | **FragTrap** — stessa logica di ScavTrap, con `highFivesGuys()` |
| `ex03` | **DiamondTrap** — eredita da ScavTrap **e** FragTrap; ereditarietà virtuale su ClapTrap per risolvere il diamond problem, attributo `name` shadowato, `attack()` disambiguato con `using ScavTrap::attack` |

## cpp04 — Polymorphism, abstract classes, interfaces

| Ex | Argomento |
|----|-----------|
| `ex00` | **WrongAnimal / WrongCat** — dimostra il problema del dispatch statico quando `makeSound()` non è `virtual` |
| `ex01` | **Animal / Brain / Cat / Dog** — `makeSound()` virtuale corretto, classe `Brain` posseduta per puntatore, deep copy di `Brain` in copy ctor/`operator=`, test su array polimorfico di `Animal*` |
| `ex02` | Stessa gerarchia di `ex01`, ma `Animal::makeSound()` diventa **pure virtual** → `Animal` è abstract, non istanziabile direttamente |
| `ex03` | **AMateria / Ice / Cure / Character / MateriaSource** — interfacce pure (`ICharacter`, `IMateriaSource`), *virtual constructor idiom* (`clone()`) per copiare oggetti polimorfici, deep copy dell'inventario di `Character`, gestione degli owner dei puntatori senza leak né double-free |

## Come compilare

```bash
cd cppXX/exYY
make
./nome_eseguibile
```

Verificato con `valgrind --leak-check=full --show-leak-kinds=all` su tutti gli esercizi con allocazione dinamica (cpp01, cpp03, cpp04).