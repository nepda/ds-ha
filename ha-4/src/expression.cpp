/**
 * Die gleiche Hausaufgabe nochmal in einer Datei etwas anders geloest
 */
#include <iostream>

using namespace std;

/**
 * Macht den Quelltext lesbarer
 *
 *  'O' -> Operator
 *  'C' -> Zeichen (character)
 *  'N' -> Zahl (number)
 */
#define TYP_OPERATOR 'O'
#define TYP_ZEICHEN 'C'
#define TYP_ZAHL 'N'

/**
 * Wandelt den Abschnitt der Eingabe von `start` bis `ende` in einen Integer Wert um
 */
int zeichenInZahl(char *eingabe, int start, int ende) {

    int negativ = 0;
    if (eingabe[start] == '-') {
        negativ = 1;
        start++;
    }
    if (eingabe[start] == '+') {
        negativ = 0;
        start++;
    }
    int zahl = 0;
    for (int i = start; i < ende; i++) {
        zahl = zahl * 10 + (eingabe[i] - 48);
    }
    if (negativ) {
        zahl = zahl * (-1);
    }
    return zahl;
}

/**
 * Repraesentiert einen Knoten im dyadischen Baum mit zwei Kindern (rechts und links)
 */
class Knoten {

public:

    /**
     * Speichert den linken Teilbaum
     */
    Knoten *links;

    /**
     * Speichert den rechten Teilbaum
     */
    Knoten *rechts;

    /**
     * Speichert den Operator
     */
    char operation;

    /**
     * Speichert das Zeichen
     */
    char zeichen;

    /**
     * Speichert die Zahl
     */
    int zahl;

    /**
     * Welche Art von Knoten ist das
     *
     *  'O' -> Operator
     *  'C' -> Zeichen (character)
     *  TYP_ZAHL -> Zahl (number)
     */
    char typ;

    /**
     * Gibt den Knoten auf dem Bildschirm aus
     */
    void ausgabe() {
        switch (this->typ) {
            case TYP_OPERATOR:
                cout << this->operation;
                break;
            case TYP_ZAHL:
                cout << this->zahl;
                break;
            case TYP_ZEICHEN:
                cout << this->zeichen;
                break;
            default:
                cout << "Unbekannter Knotentyp!";
        };
    }

    Knoten() {
        this->links = 0;
        this->rechts = 0;
    }
};


/**
 *
 */
class Baum {

public:

    /**
     * Speichert den Wurzelknoten des Baumes
     */
    Knoten *wurzel;

    Baum(Knoten *wurzel) {
        this->wurzel = wurzel;
    }

    /**
     * PreOrder - gesamter Baum
     */
    void preOrder() {
        this->preOrder(this->wurzel);
    }

    /**
     * PreOrder - Teilbaum
     */
    void preOrder(Knoten *wurzel) {

        if (!wurzel) {
            return;
        }

        wurzel->ausgabe();
        cout << " ";
        if (wurzel->links) {
            this->preOrder(wurzel->links);
        }
        if (wurzel->rechts) {
            this->preOrder(wurzel->rechts);
        }
    }

    /**
     * InOrder - gesamter Baum
     */
    void inOrder() {
        this->inOrder(this->wurzel);
    }

    /**
     * InOrder - Teilbaum
     */
    void inOrder(Knoten *wurzel) {

        if (!wurzel) {
            return;
        }

        if (wurzel->links) {
            cout << "(";
            this->inOrder(wurzel->links);
        }

        wurzel->ausgabe();

        if (wurzel->rechts) {
            this->inOrder(wurzel->rechts);
            cout << ")";
        }
    }

    /**
     * PostOrder - gesamter Baum
     */
    void postOrder() {
        this->postOrder(this->wurzel);
    }

    /**
     * PostOrder - Teilbaum
     */
    void postOrder(Knoten *wurzel) {

        if (!wurzel) {
            return;
        }

        if (wurzel->links) {
            this->postOrder(wurzel->links);
        }
        if (wurzel->rechts) {
            this->postOrder(wurzel->rechts);
        }

        wurzel->ausgabe();

        cout << " ";
    }

    /**
     * Den gesamten Baum vereinfachen
     */
    void vereinfachen() {
        this->vereinfachen(this->wurzel);
    }

    /**
     * Teilbaum vereinfachen
     */
    void vereinfachen(Knoten *wurzel) {

        // Wenn der (Teil)Baum leer ist, weiter gehen
        if (!wurzel) {
            return;
        }

        // Wenn Knoten ein Zeichen oder Zahl ist, weiter gehen
        if (wurzel->typ == TYP_ZEICHEN || wurzel->typ == TYP_ZAHL) {
            return;
        }

        // Erst bis runter in die Blaetter...
        this->vereinfachen(wurzel->links);
        this->vereinfachen(wurzel->rechts);

        // und dann von unten an vereinfachen.

        cout << "Operation '" << wurzel->operation << "' vereinfachen: " << endl;
        cout << "Links: " << wurzel->links->typ << ", Rechts: " << wurzel->rechts->typ << endl;

        switch (wurzel->operation) {
            case '+':

                // links zahl, rechts zahl => summe wird knoten
                // rechts zahl, links zahl => summe wird knoten
                if (wurzel->links->typ == TYP_ZAHL && wurzel->rechts->typ == TYP_ZAHL) {

                    cout << "=> Addition: " << wurzel->links->zahl << " + " << wurzel->rechts->zahl << " = ";

                    wurzel->typ = TYP_ZAHL;
                    wurzel->zahl = wurzel->links->zahl + wurzel->rechts->zahl;

                    cout << wurzel->zahl << "." << endl;

                    delete wurzel->links;
                    delete wurzel->rechts;
                    wurzel->links = 0;
                    wurzel->rechts = 0;

                    cout << endl;
                    return;
                }

                // links 0 (zahl), rechts buchstabe => rechts wird knoten
                if (
                        (wurzel->links->typ == TYP_ZAHL && wurzel->links->zahl == 0) // links zahl, 0
                        &&
                        (wurzel->rechts->typ == TYP_ZEICHEN) // rechts buchstabe
                        ) {

                    cout << "=> " << wurzel->links->zahl << " + " << wurzel->rechts->zeichen << " = " <<
                    wurzel->rechts->zeichen << endl;

                    wurzel->typ = TYP_ZEICHEN;
                    wurzel->zeichen = wurzel->rechts->zeichen;
                    delete wurzel->links;
                    delete wurzel->rechts;
                    wurzel->links = 0;
                    wurzel->rechts = 0;
                    cout << endl;
                    return;
                }

                // rechts 0 (zahl), links buchstabe => links wird knoten
                if (
                        (wurzel->rechts->typ == TYP_ZAHL && wurzel->rechts->zahl == 0) // rects zahl, 0
                        &&
                        (wurzel->links->typ == TYP_ZEICHEN)
                        ) {

                    cout << "=> " << wurzel->links->zeichen << " + " << wurzel->rechts->zahl << " = " <<
                    wurzel->links->zeichen << endl;

                    wurzel->typ = TYP_ZEICHEN;
                    wurzel->zeichen = wurzel->links->zeichen;
                    delete wurzel->links;
                    delete wurzel->rechts;
                    wurzel->links = 0;
                    wurzel->rechts = 0;
                    cout << endl;
                    return;
                }

                break;
            case '-':


                // links zahl, rechts zahl => differenz wird knoten
                // rechts zahl, links zahl => differenz wird knoten
                if (wurzel->links->typ == TYP_ZAHL && wurzel->rechts->typ == TYP_ZAHL) {

                    cout << "=> " << wurzel->links->zahl << " - " << wurzel->rechts->zahl << " = ";

                    wurzel->typ = TYP_ZAHL;
                    wurzel->zahl = wurzel->links->zahl - wurzel->rechts->zahl;

                    cout << wurzel->zahl << endl;

                    delete wurzel->links;
                    delete wurzel->rechts;
                    wurzel->links = 0;
                    wurzel->rechts = 0;
                    cout << endl;
                    return;
                }

                // links 0 (zahl), rechts buchstabe => rechts wird knoten
                if (
                        (wurzel->links->typ == TYP_ZAHL && wurzel->links->zahl == 0) // links zahl, 0
                        &&
                        (wurzel->rechts->typ == TYP_ZEICHEN) // rechts buchstabe
                        ) {

                    cout << "=> " << wurzel->links->zahl << " - " << wurzel->rechts->zeichen << " = " <<
                    wurzel->rechts->zeichen << endl;

                    wurzel->typ = TYP_ZEICHEN;
                    wurzel->zeichen = wurzel->rechts->zeichen;
                    delete wurzel->links;
                    delete wurzel->rechts;
                    wurzel->links = 0;
                    wurzel->rechts = 0;
                    cout << endl;
                    return;
                }


                // rechts 0 (zahl), links buchstabe => links wird knoten
                if (
                        (wurzel->rechts->typ == TYP_ZAHL && wurzel->rechts->zahl == 0) // rects zahl, 0
                        &&
                        (wurzel->links->typ == TYP_ZEICHEN)
                        ) {

                    cout << "=> " << wurzel->links->zeichen << " - " << wurzel->rechts->zahl << " = " <<
                    wurzel->rechts->zeichen << endl;

                    wurzel->typ = TYP_ZEICHEN;
                    wurzel->zeichen = wurzel->links->zeichen;
                    delete wurzel->links;
                    delete wurzel->rechts;
                    wurzel->links = 0;
                    wurzel->rechts = 0;
                    cout << endl;
                    return;
                }
                break;
            case '*':

                if (wurzel->links->typ == TYP_ZAHL && wurzel->rechts->typ == TYP_ZAHL) {

                    cout << "=> " << wurzel->links->zahl << " * " << wurzel->rechts->zahl << " = ";

                    wurzel->typ = TYP_ZAHL;
                    wurzel->zahl = wurzel->links->zahl * wurzel->rechts->zahl;

                    cout << wurzel->zahl << endl;

                    delete wurzel->links;
                    delete wurzel->rechts;

                    wurzel->links = 0;
                    wurzel->rechts = 0;
                    cout << endl;
                    return;
                }

                // links oder rechts 0, knoten wird 0
                if (
                        (wurzel->links->typ == TYP_ZAHL && wurzel->links->zahl == 0) // links 0
                        ||
                        (wurzel->rechts->typ == TYP_ZAHL && wurzel->rechts->zahl == 0) // rechts 0
                        ) {

                    cout << "=> " << wurzel->links->zahl << " * " << wurzel->rechts->zahl << " = 0" << endl;

                    wurzel->typ = TYP_ZAHL;
                    wurzel->zahl = 0;
                    delete wurzel->links;
                    delete wurzel->rechts;
                    wurzel->links = 0;
                    wurzel->rechts = 0;
                    cout << endl;
                    return;
                }

                // links 1 (zahl), rechts zahl => rechte zahl wird knoten
                if (wurzel->links->typ == TYP_ZAHL && wurzel->links->zahl == 1 && wurzel->rechts->typ == TYP_ZAHL) {

                    cout << "=> " << wurzel->links->zahl << " * " << wurzel->rechts->zahl << " = " <<
                    wurzel->rechts->zahl;

                    wurzel->typ = TYP_ZAHL;
                    wurzel->zahl = wurzel->rechts->zahl;
                    delete wurzel->links;
                    delete wurzel->rechts;
                    wurzel->links = 0;
                    wurzel->rechts = 0;
                    cout << endl;
                    return;
                }
                // links 1 (zahl), rechts buchstabe => rechter buchstabe wird knoten
                if (wurzel->links->typ == TYP_ZAHL && wurzel->links->zahl == 1 && wurzel->rechts->typ == TYP_ZEICHEN) {

                    cout << "=> " << wurzel->links->zahl << " * " << wurzel->rechts->zeichen << " = " <<
                    wurzel->rechts->zeichen;

                    wurzel->typ = TYP_ZEICHEN;
                    wurzel->zeichen = wurzel->rechts->zeichen;
                    delete wurzel->links;
                    delete wurzel->rechts;
                    wurzel->links = 0;
                    wurzel->rechts = 0;
                    cout << endl;
                    return;
                }

                // rechts 1 (zahl), links zahl, linke zahl wird knoten
                if (wurzel->rechts->typ == TYP_ZAHL && wurzel->rechts->zahl == 1 && wurzel->links->typ == TYP_ZAHL) {

                    cout << "=> " << wurzel->links->zahl << " * " << wurzel->rechts->zahl << " = " <<
                    wurzel->links->zahl;

                    wurzel->typ = TYP_ZAHL;
                    wurzel->zahl = wurzel->links->zahl;
                    delete wurzel->links;
                    delete wurzel->rechts;
                    wurzel->links = 0;
                    wurzel->rechts = 0;
                    cout << endl;
                    return;
                }
                // rechts 1 (zahl), links buchstabe, linker buchstabe wird knoten
                if (wurzel->rechts->typ == TYP_ZAHL && wurzel->rechts->zahl == 1 && wurzel->links->typ == TYP_ZEICHEN) {

                    cout << "=> " << wurzel->links->zeichen << " * " << wurzel->rechts->zahl << " = " <<
                    wurzel->links->zeichen;

                    wurzel->typ = TYP_ZEICHEN;
                    wurzel->zeichen = wurzel->links->zeichen;
                    delete wurzel->links;
                    delete wurzel->rechts;
                    wurzel->links = 0;
                    wurzel->rechts = 0;
                    cout << endl;
                    return;
                }
                break;
            default:
                return;
        }
    }

    /**
     * Loescht rekursiv alle Knoten aus dem Baum
     */
    void loescheKnoten(Knoten *knoten) {
        if (knoten->links) {
            this->loescheKnoten(knoten->links);
        }
        if (knoten->rechts) {
            this->loescheKnoten(knoten->rechts);
        }
        delete knoten;
    }

    /**
     * Destrkutor, loescht den Baum mit allen Knoten
     */
    ~Baum() {
        this->loescheKnoten(this->wurzel);
    }
};

int laenge(char *eingabe) {
    int l = 0;
    while (eingabe[l] != '\0') ++l;
    return l;
}

/**
 * Findet die Position des ersten Operators in der Eingabezeichenkette und gibt diese zurueck.
 *
 * Wenn kein Operator in der Eingabe gefunden wurde, wird -1 zurueckgegeben.
 */
int findeOperationsPosition(char *eingabe, int startPosition, int endPosition) {

    int i = startPosition;

    // Erst nach + und - suchen:
    while (eingabe[i] != '\0' && i < endPosition) {
        if (eingabe[i] == '+' || eingabe[i] == '-') {
            return i; // Erste Position gefunden, Ruecksprung
        }
        i++;
    }

    i = startPosition;
    // Dann nach * suchen:
    while (eingabe[i] != '\0' && i < endPosition) {
        if (eingabe[i] == '*') {
            return i; // Erste Position gefunden, Ruecksprung
        }
        i++;
    }

    // Wenn nichts gefunden wurde, -1 zurueckgeben
    return -1;
}

Knoten *erstelleKnoten(char *eingabe, int startPosition, int endPosition) {

    if (startPosition - endPosition == 0) {
        return 0;
    }
    // Position des ersten Operators in der Zeichenkette
    int operatorPosition;
    char erstesZeichen;

    // Wenn das aller erste Zeichen ein + oder - ist, dann ist die folgende Zahl vorzeichenbehaftet
    // Und der erste Operator darf erst danach gefunden werden
    // Bspw.: -1+b-1+3
    //          ^------- das Plus hier ist der erste Operator!
    int offset = 0;
    if (startPosition == 0) {
        if (eingabe[0] == '-' || eingabe[0] == '+') {
            offset = 1;
        }
    }

    operatorPosition = findeOperationsPosition(eingabe, startPosition + offset, endPosition);

    Knoten *knoten = new Knoten();

    erstesZeichen = eingabe[startPosition];

    if (operatorPosition == -1) {
        // Es wurde kein Operator in der Eingabe gefunden, also ist die Eingabe ein Blatt

        knoten->links = 0;
        knoten->rechts = 0;

        if (erstesZeichen >= 'a' && erstesZeichen <= 'z') {
            knoten->typ = TYP_ZEICHEN; // Zeichen
            knoten->zeichen = erstesZeichen;

            cout << "Zeichen '" << knoten->zeichen << "' gefunden." << endl;
        } else {

            knoten->typ = TYP_ZAHL; // Zahl

            int wert;
            wert = zeichenInZahl(eingabe, startPosition, endPosition);

            cout << "Zahl '" << wert << "' gefunden." << endl;

            knoten->zahl = wert;
        }
    } else {

        knoten->typ = TYP_OPERATOR;
        knoten->operation = eingabe[operatorPosition];

        cout << "Operator '" << knoten->operation << "' an Pos. " << operatorPosition << " gefunden." << endl;

        Knoten *links, *rechts;

        cout << "Gehe links von " << startPosition << " bis " << operatorPosition << " weiter: " << endl << endl;
        links = erstelleKnoten(eingabe, startPosition, operatorPosition);

        cout << "Gehe rechts von " << operatorPosition + 1 << " bis " << endPosition << " weiter: " << endl << endl;
        rechts = erstelleKnoten(eingabe, operatorPosition + 1, endPosition);

        cout << endl;

        knoten->links = links;
        knoten->rechts = rechts;
    }

    return knoten;
}

Knoten *erstelleWurzelKnoten(char *eingabe) {

    cout << "Lese Eingabe '" << eingabe << "'";
    int L = laenge(eingabe);
    cout << ", Laenge: " << L << endl;
    return erstelleKnoten(eingabe, 0, L);
}

int main(int argc, char **argv) {

    Knoten *wurzel;

    wurzel = erstelleWurzelKnoten(argv[1]);

    Baum *baum = new Baum(wurzel);


    cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++" << endl;

    cout << "Pre-Order: " << endl;
    baum->preOrder();
    cout << endl;
    cout << endl;

    cout << "In-Order: " << endl;
    baum->inOrder();
    cout << endl;
    cout << endl;

    cout << "Post-Order: " << endl;
    baum->postOrder();
    cout << endl;
    cout << endl;


    cout << endl << "+++++++++ Baum vereinfachen +++++++++++++++" << endl;
    baum->vereinfachen();
    cout << endl << "+++++++++ Vereinfachter Baum ++++++++++++++" << endl;

    cout << endl << "Pre-Order: " << endl;
    baum->preOrder();
    cout << endl;
    cout << endl;

    cout << "In-Order: " << endl;
    baum->inOrder();
    cout << endl;
    cout << endl;

    cout << "Post-Order: " << endl;
    baum->postOrder();
    cout << endl;
    cout << endl;

    delete baum;

    return 0;
}
