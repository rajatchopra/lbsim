
#include "lb.hxx"
#include "endpoint.hxx"
#include <stdio>

LbSim::LbSim(int numEndpoints, int simDuration, int requestDuration, int requestsPerSecond) {
    for (int i =1; i <= numEndpoints; i++) {
        _endpointsList.push_back(new Endpoint(requestDuration))
    }
    _rps = requestsPerSecond;
}

LbSim::~LbSim() {
}

void*
SimLaunchFunction(void *arg) {
    LbSim *lb = (LbSim *)arg;
    lb->Simulate()
}

void
LbSim::StartSim() {
    pthread_t *th = new pthread_t;
    pthread_attr_t custom_attr;
    pthread_attr_init(&custom_attr);
    pthread_create(th, &custom_attr, &SimLaunchFunction, (void *) this);
}

void
LbSim::Simulate() {
    float nSecsBetweenRequest = (1.0*1000000000/_rps);
    _sim = true;
    while (1) {
        for (int i =0; i < _endpointsList.Size(); i++) {
            ep = _endpointsList[i];
            ep->HandleRequest();
            if (!_sim) {
                return;
            }
            nanosleep(nSecsBetweenRequest);
        }
    }
}

void
LbSim::PrintStats() {
    string stats;
    for (i =0; i < this->_endpointsList.Size(); i++) {
        Endpoint *ep = this->_endpointsList[i];
        stats += ep->CurrentSessions();
        stats += " ";
    }
    cout << stats.c_str();
    cout << "\n";
}

void
LbSim::StopSim() {
    _sim = false;
}


//    private:
//        vector<Endpoint> _endpointList;
