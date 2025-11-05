#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <vector>
using namespace std;

const int LAVORATORI = 20;
const int LAVORI = 10;

class Task {
    private:
        int nTask;
    
    public:
        Task (int nTask) : nTask(nTask) {}          //costruttore di task che permette di passare il numero della task
        
        int IdTask() {
            return nTask;       // qua viene il return del numero della task, tramite questa funzione che identifica appunto il numero della task
        }

};

class Worker {
    private:
    
    public:

};

class Master {
    private:
        vector<Worker> workers; //nuovo vettore che specifica il tipo di oggetti creati (Worker) e il nome del vettore (workers)
        queue<Task>& coda;
        mutex& mtx;
        condition_variable& cv;
        atomic<bool>& conclusione;
        
    
    public:
        Master(queue<Task>& coda, mutex& mtx, condition_variable& cv, atomic<bool>& conclusione)
        : coda(coda), mtx(mtx), cv(cv), conclusione(conclusione) {}
        
        void start (){
            for (int i =0; i < LAVORATORI; i+*) {
                workers.push_back(<Worker>(new Worker(i, coda, mtx, cv, conclusione))); //inserisco un nuovo oggetto nel vettore , specifico il tipo e i dati su cui lavora
            }
        }
};


int main() {
    mutex mtx;              //serve per sincronizzare thread e permette di proteggere sezioni critiche, che sono luoghi in cui possono avvenire 2 operazioni nello stesso momento dando problemi
    queue<Task> coda;                //sto creando la coda per le task
    condition_variable cv;          // serve per fare operazioni con i thread
    atomic<bool> conclusione(false);     // è una variabile booleana thread safe atomic=variabile, bool indica che è booleana, conclusione è il nome e infine false è il suo stato in cui viene dichiarata
    
    Master m (mtx, coda, cv, conclusione);      //questa è chiama la funzione Master che è costruttore della classe master, creando l'oggetto m, partendo dai dati messi tra parentesi
    m.start();
    
	return 0;
}
