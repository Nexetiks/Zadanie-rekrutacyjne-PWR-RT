Program zostal stworzony w celu policzenia najkrotszej drogi dojazdu z punktu początkowego A do punktu koncowego B, lecz moj program oferuje troszeczke wiecej. Jest on w stanie obliczyc najoplacalniejsza droge z punktu startowego do jakiegokolwiek punktu na mapie, wszystko zalezy od uzytkownika, rowniez program jest w stanie wyswietlic wszystkie punkty (o ile uzytkownik wyrazi taka chec) przez ktore przechodzi droga idac do celu(sciezka).

Program sklada sie z 5 funkcji wykonujacych poszczegolne elementy, ktore nizej objasnie, oraz funkcji main.

Funkcja - Input
Prosi uzytkownika o wpisanie wartosci zuzycia energi podczas przemiszczania sie na poszczegolnych kolorach trasy i zapisuje je do zmiennych, ktore nastepnie zostaja przemnozone w tablicy.

Funkcja - UserInputValidation
Jest to funkcja ktora czesciowo waliduje dane (lecz nie wszystkie, nie sprawdza czy liczby wykraczaja poza maksymalna wartosc floata oraz nie obsluguje liter, program wtedy sie wysypuje). Sprawdza ona czy wartosci sa z przedzialow jaki program oczekuje od uzytkownika do wprowadzenia.

Funkcja - FindShortestPath
Najwazniejsza ze wszystkich funkcji, to wlasnie ona liczy najkrotsza trase i ja zapisuje do tablicy z wynikami, tworzac algorytm bazowalem na Algorytmie Dijkstry, choc zostal on lekko zmieniony ze wzgledu na nieuniwersalne potrzeby(liczenie zawsze na tej samej mapie).

Funkcja - GetDestinationPoint
Funkcja, ktora proponuje uzytkownikowi obliczenie najkrotszej trasy do innego punktu niz punkt ktory zostal z gory zalozony w zadaniu(punkt B). W wypadku checi uzytkownika program wyswietli wynik dla innego punktu, w przeciwnym wypadku funkcja policzy zuzycie energii dla punktu podstawowego.

Funkcja - RouteCourse
Funkcja dajaca mozliwosc uzytkownikowi podgladu punktow przez, ktore przebiega trasa w drodze do punktu docelowego. Trasa jest wyswietlana tylko w wypadku gdy uzytkownik wyrazi ow chec.

Funkcja - Main
Raczej nie trudno sie domyslic, funkcja w ktorej wywolywane sa po kolei wszystkie powyzsze funkcje, jedyne co znajduje sie w mainie oprocz wywolan sa to tablice zawierajace macierz powiazan punktow i tablica do zapisywania wynikow oraz sciezki.


Zalaczam zdjecie z ponumerowanymi skrzyzowaniami wedlug ktorych program wypisuje sciezke.