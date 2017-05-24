
#include "endpoint.hxx"
#include <time>
#include <pthread>

Endpoint::Endpoint(int requestDuration) {
    _curSessions =0;
    _requestDuration = requestDuration;
    _lock = new pthread_mutex_t;
    pthread_mutex_init(_lock);
}

Endpoint::~Endpoint() {
}

void* LaunchFunction(void *arg) {
    Endpoint *self = (Endpoint *)arg;
    self->ProcessRequest()
}

void Endpoint::ProcessRequest() {
    self->IncrSessions();
    sleep(self->RequestDuration())
    self->DecrSessions();
}

void Endpoint::IncrSessions() {
    pthread_mutex_lock(this->_lock);
    this->_curSessions++;
    pthread_mutex_unlock(this->_lock);
}

void Endpoint::DecrSessions() {
    pthread_mutex_lock(this->_lock);
    this->_curSessions--;
    pthread_mutex_unlock(this->_lock);
}

void Endpoint::HandleRequest() {
    // start a thread that waits for timeout seconds
    pthread_t *th = new pthread_t;
    pthread_attr_t custom_attr;
    pthread_attr_init(&custom_attr);
    pthread_create(th, &custom_attr, &LaunchFunction, (void *) this);
}

int Endpoint::CurrentSessions() {
    return _curSessions;
}

//    private:
//        int _curSessions;
