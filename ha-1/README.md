Sieb des Eratosthenes
=====================

Eratosthenes (ca. 200 v. Chr.) war ein griechischer Mathematiker und Philosoph, der
u.a. einen Algorithmus zur Bestimmung von Primzahlen entwickelte:

* Schreibe mit Zahl 2 beginnend alle folgenden natürlichen Zahlen bis zu einem frei wählbaren Maximalwert M auf
* Zunächst sind alle Zahlen unmarkiert
* Die kleinste unmarkierte Zahl ist immer eine Primzahl
* Bestimme die kleinste unmarkierte Zahl und markiere alle Vielfachen dieser Zahl (es genügt, mit dem Quadrat der Primzahl zu beginnen, da alle kleineren Vielfachen bereits markiert sind)
* Ist das Quadrat der aktuellen Primzahl größer als der Maximalwert M, ergeben alle nicht markierten Zahlen die Primzahlen von 2 bis M

