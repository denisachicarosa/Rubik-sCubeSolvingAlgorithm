# **Rubik'sCubeSolvingAlgorithm**

### Acest proiect invata utilizatorul sa rezolve un cub Rubik, fara sa foloseasca un caz particular, adaptandu-se pentru configuratia cubului amestecat.

## *Componente*: 
- LCD 1602 Module
- Button
- LED
- Wires
- Breadboard
- Arduino Uno R3 sau Mega
- Bluetooth Module

## *Inceput:*
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
 
## *Rezolvarea cubului:*
 In continuare, vom primi pe LCD cate un pas pe care trebuie sa il executam pentru ca in final sa reusim sa rezolvam cubul Rubik.
 Pentru rezolvarea acestuia trebuie sa respectam un set de reguli.
 
 1. *Pozitionarea cubului Rubik:*
  - Fata cubului care are patratelul din mijloc rosu, va fi indreptata spre noi.
  
  - Fata cubului care are patratelul din mijloc galben, va fi tinuta in sus.
  
  - Programul ofera o rezolvare corecta pentru cuburile care au in stanga laturii rosii, latura verde, iar in dreapta laturii rosii, latura albastra.
 
 2. *Codificarea mutarilor:*
  
  - Literele scrise cu majuscule reprezinta o miscare a fetei respective in sensul acelor de ceasornic.
  
  - Literele mici reprezinta o miscare a fetei respective in sensul invers acelor de ceasornic.
  
  - R = right, (latura albastra), iar r = right reverse 
  
  - L = left, (latura verde), iar l = left reverse
  
  - U = up, (latura galbena), iar u = up reverse
  
  - D = down, (latura alba), iar d = down reverse
  
  - F = front, (latura rosie), iar f = front reverse
  
  - B = back, (latura portocalie), iar b = back reverse
 
 Imediat dupa introducerea configuratiei cubului, apare prima mutare. Dupa ce am executat mutarea respectiva respectand regulile de mai sus, vom apasa butonul si dupa ce se aprinde ledul alaturat, stim ca am trecut la mutarea urmatoare.

  Cand ajungem la final, cubul va fi rezolvat si ledul va ramane aprins.
  Gasiti [aici] un demo al rezolvarii.
  
  
  
