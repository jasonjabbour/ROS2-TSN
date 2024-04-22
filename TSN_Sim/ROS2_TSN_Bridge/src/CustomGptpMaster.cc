/*
 * CustomGptp.cc
 *
 *  Created on: Apr 21, 2024
 *      Author: root
 */


#include "CustomGptpMaster.h"

Define_Module(CustomGptpMaster);

void CustomGptpMaster::initialize(int stage) {
    Gptp::initialize(stage);  // Call the base class initialize method
    throw cRuntimeError("CustomGptpMaster is being used");
}

void CustomGptpMaster::handleMessage(cMessage *msg) {
    Gptp::handleMessage(msg);  // Call the base class message handler
}

void CustomGptpMaster::sendSync() {
    Gptp::sendSync();  // Call the base class sendSync to perform the standard operation
//    EV << "[JASON] CustomGptpMaster: Sending synchronization message" << endl;
    EV_WARN << "JASON JASON JASON JASON JASON";
    EV_INFO << "Jason JASON       - " << endl;


    // Here you can add more code to log details about the sync message or the network state
}

void CustomGptpMaster::processFollowUp(Packet *packet, const GptpFollowUp* gptp) {
    // First call the base class method
    Gptp::processFollowUp(packet, gptp);

    // Then add your custom logging or other behavior
    EV << "HERE HERE HERE HERE HERE" << endl;
    EV_WARN << "JASON JASON JASON JASON JASON";
    EV_INFO << "Jason JASON       - " << endl;
    // Further custom behavior can follow here
    throw cRuntimeError("CustomGptpMaster is being used...");
}
