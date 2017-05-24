
#ifndef __LB_SIM_HXX__
#define __LB_SIM_HXX__

using namespace std;

class LbSim {
    public:
        LbSim(int numEndpoints, int requestDuration, int requestsPerSecond);
        ~LbSim();
    public:
        StartSim();
        StopSim();
    private:
        vector<Endpoint> _endpointList;
        int _requestDuration;
        int _rps;
};

#endif
