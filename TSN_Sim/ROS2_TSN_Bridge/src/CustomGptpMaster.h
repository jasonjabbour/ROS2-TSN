/*
 * CustomGptp.h
 *
 *  Created on: Apr 21, 2024
 *      Author: root
 */

#ifndef CUSTOMGPTPMASTER_H_
#define CUSTOMGPTPMASTER_H_

#include "inet/linklayer/ieee8021as/Gptp.h"

using namespace inet;

class CustomGptpMaster : public Gptp {
  protected:
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *msg) override;
    void sendSync(); // Extend functionality
    virtual void processFollowUp(Packet *packet, const GptpFollowUp* gptp);  // Extend the processFollowUp method

};



#endif /* CUSTOMGPTPMASTER_H_ */
