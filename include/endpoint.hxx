
#ifndef __ENDPOINT_HXX__
#define __ENDPOINT_HXX__

#include <pthread.h>

class Endpoint {
    public:
        Endpoint();
        ~Endpoint();
    public:
        void HandleRequest();
        int CurrentSessions();
    public:
        void ProcessRequest();
    private:
        void IncrSessions();
        void DecrSessions();
    private:
        int _curSessions;
        int _requestDuration;
        pthread_mutex_t _lock;
};

#endif
