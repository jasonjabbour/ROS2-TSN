#include <stdio.h>
#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

/**
 * Derive the Txc5 class from cSimpleModule. In the Tictoc1 network,
 * both the `tic' and `toc' modules are Txc5 objects, created by OMNeT++
 * at the beginning of the simulation.
 */
class Txc5 : public cSimpleModule
{
    private:
        int counter;
        // Set the pointers to nullptr, so that the destructor won't crash
        // even if initialize() doesn't get called because of a runtime
        // error or user cancellation during the startup process.
        cMessage *event = nullptr;  // pointer to the event object which we'll use for timing
        cMessage *tictocMsg = nullptr;  // variable to remember the message until we send it back

    protected:
        // The following redefined virtual function holds the algorithm.
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;

    public:
        virtual ~Txc5();
};

// The module class needs to be registered with OMNeT++
Define_Module(Txc5);

Txc5::~Txc5()
{
    // Dispose of dynamically allocated the objects
    cancelAndDelete(event);
    delete tictocMsg;
}

void Txc5::initialize()
{


    // Create the event object we'll use for timing -- just any ordinary message.
    event = new cMessage("event");

    // No tictoc message yet.
    tictocMsg = nullptr;

    // Initialize is called at the beginning of the simulation.
    // To bootstrap the tic-toc-tic-toc process, one of the modules needs
    // to send the first message.
    if (par("sendMsgOnInit").boolValue() == true) {
        // create and send first message on gate "out". "tictocMsg" is an
        // arbitrary string which will be the name of the message object.
        cMessage *msg = new cMessage("tictocMsg");
        send(msg, "out");
        EV << "Sending initial message\n";
    }
}

void Txc5::handleMessage(cMessage *msg)
{

    // There are several ways of distinguishing messages, for example by message
    // kind (an int attribute of cMessage) or by class using dynamic_cast
    // (provided you subclass from cMessage). In this code we just check if we
    // recognize the pointer, which (if feasible) is the easiest and fastest
    // method.
    if (msg == event) {
        // The self-message arrived, so we can send out tictocMsg and nullptr out
        // its pointer so that it doesn't confuse us later.
        EV << "Wait period is over, sending back message\n";
        send(tictocMsg, "out");
        tictocMsg = nullptr;
    }
    else {
        // If the message we received is not our self-message, then it must
        // be the tic-toc message arriving from our partner. We remember its
        // pointer in the tictocMsg variable, then schedule our self-message
        // to come back to us in 1s simulated time.
        EV << "Message arrived, starting to wait 1 sec...\n";
        tictocMsg = msg;
        scheduleAt(simTime()+1.0, event);
    }
}

