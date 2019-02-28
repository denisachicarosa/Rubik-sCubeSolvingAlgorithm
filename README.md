# **Rubik'sCubeSolvingAlgorithm**

### Acest proiect invata utilizatorul sa rezolve un cub Rubik, fara sa foloseasca un caz general, adaptandu-se pentru configuratia cubului amestecat.

## Componente: 
- LCD 1602 Module
- Button
- LED
- Wires
- Breadboard
- Arduino Uno R3 sau Mega
- Bluetooth Module

## Inceput:
 Programul primeste ca input configuratia cubului amestecat prin intermediul modulului Bluetooth. 
 Eu am folosit Bluetooth Terminal, conectat la dispozitivul HC-06 (modulul conectat la arduino).
 Pentru o usoara comunicare si interpretare intre dispozitive am atribuit fiecarei culori un cod, dupa cum urmeaza:
  (W) alb        - 0
  (Y) galben     - 1
  (R) rosu       - 2
  (G) verde      - 3
  (B) albastru   - 4
  (O) portocaliu - 5
 La fiecare latura a cubului introdusa complet, primim inapoi latura afisata folosind initialele culorilor in engleza, pentru verificare.
 La final, dupa introducerea tuturor laturilor, se afiseaza "Cub filled" si nu mai sunt salvate urmatoarele caractere trimise.
 Un exemplu de introducere a datelor gasiti [aici]().
 
## Rezolvarea cubului:
 In continuare, vom primi pe LCD cate un pas pe care trebuie sa il executam pentru ca in final sa reusim sa rezolvvam cubul Rubik.
 Pentru rezolvarea acestuia trebuie sa respectam un set de reguli.
 1. Pozitionarea cubului Rubik:
  a) Fata cubului care are patratelul din mijloc rosu, va fi indreptata spre noi.
  b) Fata cubului care are patratelul din mijloc galbe, va fi tinuta in sus.
  c) Programul ofera o rezolvare corecta pentru cuburile care au in stanga laturii rosii, latura verde, iar in dreapta laturii rosii, va fi latura albastra.
 2. Codificarea mutarilor:
  a) Literele scrise cu majuscule reprezinta o miscare a fetei respective in sensul acelor de ceasornic.
  b) Literele mici reprezinta o miscare a fetei respective in sensul invers acelor de ceasornic.
  c) R = right, (latura albastra), iar r = right reverse 
  d) L = left, (latura verde), iar l = left reverse
  e) U = up, (latura galbena), iar u = up reverse
  f) D = down, (latura alba), iar d = down reverse
  g) F = front, (latura rosie), iar f = front reverse
  h) B = back, (latura portocalie), iar b = back reverse
 
 Imediat dupa introducerea configuratiei cubului, apare prima mutare. Dupa ce am executat mutarea respectiva respectand regulile de mai sus, vom apasa butonul si dupa ce se aprinde ledul alaturat, stim ca am trecut la mutarea urmatoare.

  Cand ajungem la final, cubul va fi rezolvat si ledul va ramane aprins.
  Gasiti [aici] un demo al rezolvarii.
  
  
  
