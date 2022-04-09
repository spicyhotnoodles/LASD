# Esercizio 1 - Vettori e Liste di Dati Generici
## Traccia
Implementare due librerie di funzioni in Linguaggio C++ per la gestione di strutture dati
dinamiche di tipo vettore e lista per dati generici, ovvero interi, float, stringhe, struct, ecc.
Le funzionalità da realizzare sono di seguito elencate:

1. costruzione e distruzione di una struttura dati;
2. operazioni di assegnamento e confronto tra istanze diverse della struttura dati;
3. operazioni comuni ai due tipi di strutture dati (accesso non distruttivo all’elemento
iniziale, finale o avente uno specifico indice; controllo di esistenza di un dato valore;
operazioni di applicazione di una funzione a tutti gli elementi: funzioni map; ope-
razioni di accumulazione di un valore estratto dagli elementi: funzioni fold; test di
vuotezza; lettura della dimensione; svuotamento della struttura);
4. funzioni specifiche su vettore (ridimensionamento del vettore);
5. funzioni specifiche su lista (inserimento di un dato valore in testa o coda; rimozione e
rimozione con lettura dell’elemento in testa).

Al fine di poter testare adeguatamente le librerie sopra descritte, si richiede di definire (esterna-
mente alle stesse, in un opportuno file di test richiamato dal “main”) un insieme di procedure
che implementi le seguenti funzionalità:

1. scelta della struttura (vettore vs lista) e del relativo tipo di dati da gestire (interi, ecc.);
2. popolamento della struttura precedentemente scelta con n valori del tipo opportuno
generati casualmente, dove n è un parametro dato dall’utente in ingresso;
3. visualizzazione dell’elemento iniziale, finale o avente uno specifico indice;
4. visualizzazione di tutti gli elementi (effettuata per mezzo della funzione map);
5. controllo di esistenza di un dato valore;
6. calcolo di una delle seguenti funzioni (effettuato per mezzo delle funzioni fold) e
relativa visualizzazione del risultato: somma per gli interi minori di n, prodotto per i
float maggiori di n, e concatenazione per le stringhe con lunghezza minore o uguale a n,
dove n è un parametro dato dall’utente in ingresso;
7. applicazione di una delle seguenti funzioni a tutti gli elementi: 2n per gli interi, n2
per i float, e “uppercase” per le stringhe.

Da un opportuno menu, dovrà essere inoltre possibile operare sulla struttura scelta attraverso
le funzioni di libreria di cui ai punti (4) e (5). Infine, è necessario prevedere l’accesso alla
funzionalità di test prevista dal docente.
Il codice sorgente prodotto dovrà seguire pedissequamente (sia nei nomi delle funzioni di libreria,
sia nella strutturazione, gerarchia di classi e nei nomi delle diverse directory e file “.cpp” e
“.hpp”) la forma riportata nel template Exercise1.zip associato al presente esercizio.
## Appunti
1. Nella funzione `main()` va incluso un menu tramite il quale l'utente può scegliere quale test effettuare; la prima voce rimanda al test del docente `lasdtest()`, mentre il secondo dovrà essere implementato dallo studente (`mytest()`).
2. Nella directory `zlasdtest` non va fatta alcuna modifica.
3. `container` è il file contenente le **classi astratte** su cui andrà costruita l'intera gerarchia di strutture dati.\
Non è una classe `template` poiché i metodi da implementare (`size()`, `empty()` e `clear()`) non necessitano di conoscere il tipo di dato contenuto nella struttura (vettore o lista).
***
## Note a margine:
Il copy constructor è un metodo che istanzia crea una copia di un oggetto già definito. Analogamente, in C, sarebbe una funzione che, ad esempio, dato un vettore, instanzia un nuovo vettore e ricopia tutti i valori contenuti nel primo.\
Non ho la più pallida idea del perché alcuni costruttori funzionino (eg. copy constructor list). Devo chiedere al prof.\
Il move constructor è un metodo che consente di evitare la copia di un valore (per poi distruggerla) "spostando" direttamente i valori in un nuovo oggetto. Dovrebbe essere implementato per mezzo di puntatori.\
Implementare separatamente `Fold` `FoldPreOrder` `FoldPostOrder` `Map` `MapPreOrder` `MapPostOrder`\
### Esempio function pointer
```cpp
template<typename Data>
void funct(Data&, void* opt) {
    ... ;
}

template<typename Data>
void anotherFunct(Data&, void* opt) {
    ... ;
}

vec.Map(funct, nullptr);
vec.Map(anotherFunct, nullptr);


type Map(MapFunctor, void* ) {
    MapInOrder
}
```