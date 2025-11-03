#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <atomic>
using namespace std;

class Task {
    private:
        
    
    public:

};

class Worker {
    private:
    
    public:

};

class Master {
    private:
    
    public:
};


int main() {
    mutex mtx;              //serve per sincronizzare thread e permette di proteggere sezioni critiche, che sono luoghi in cui possono avvenire 2 operazioni nello stesso momento dando problemi
    queue<Task> coda; //sto creando la coda per le task
    condition_variable cv;
    

	return 0;
}