#include <iostream>
#include <list>
#include <queue>

using namespace std;

// Klasė, kuri atstovauja nukreiptą grafą, naudojant sąsajos sąrašo atvaizdavimą

class Grafas {
    int V; // Viršūnių skaičius

    list<int> *adj;

public:
    Grafas(int V); // Konstruktorius

    void pridetiBriauna(int v, int w); // Funkcija, skirta pridėti briauną į grafą

    void BFS(int s);// BFS algoritmas nuo nurodytos viršūnės
};

Grafas::Grafas(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Grafas::pridetiBriauna(int v, int w) {
    adj[v].push_back(w); // Pridėti w į v sąrašą
}

void Grafas::BFS(int s) {
    // Pažymėti visas viršūnes kaip nenaplankytas
    bool *aplankytos = new bool[V];
    for (int i = 0; i < V; i++)
        aplankytos[i] = false;

    // Sukurti eilę BFS algoritmui
    queue<int> eile;

    // Pažymėti dabartinę viršūnę kaip aplankytą ir įdėti ją į eilę
    aplankytos[s] = true;
    eile.push(s);

    while (!eile.empty()) {
        // Išimti viršūnę iš eilės ir ją atspausdinti
        s = eile.front();
        cout << s << " ";
        eile.pop();

        // Gauti visas kaimynines viršūnes iš išimtos viršūnės s.
        // Jei kaimyninė viršūnė dar nebuvo aplankyta, pažymėti ją kaip aplankytą ir įdėti į eilę

        for (list<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!aplankytos[*i]) {
                aplankytos[*i] = true;
                eile.push(*i);
            }
        }
    }
}

// Pagrindinė programa, skirta išbandyti grafo klasės metodus
int main() {
    // Sukurti grafą
    Grafas g(4);
    g.pridetiBriauna(0, 1);
    g.pridetiBriauna(0, 2);
    g.pridetiBriauna(1, 2);
    g.pridetiBriauna(2, 0);
    g.pridetiBriauna(2, 3);
    g.pridetiBriauna(3, 3);

    // Paleisti BFS algoritmą nuo skirtingų pradinės viršūnių
    cout << "BFS algoritmo rezultatas (pradedant nuo viršūnės 2): ";
    g.BFS(2);
    cout << endl;

    cout << "BFS algoritmo rezultatas (pradedant nuo viršūnės 0): ";
    g.BFS(0);
    cout << endl;

    cout << "BFS algoritmo rezultatas (pradedant nuo viršūnės 1): ";
    g.BFS(1);
    cout << endl;

    cout << "BFS algoritmo rezultatas (pradedant nuo viršūnės 3): ";
    g.BFS(3);
    cout << endl;

    return 0;
}
