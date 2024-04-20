/*
 * CustomGptp.h
 *
 *  Created on: Apr 20, 2024
 *      Author: root
 */

#ifndef CUSTOMGPTP_H_
#define CUSTOMGPTP_H_

#include "inet/linklayer/ieee8021as/Gptp.h"

using namespace inet;

class CustomGptp : public Gptp {
  protected:
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void sendSync() override;  // Override this method to add additional behavior
};



#endif /* CUSTOMGPTP_H_ */
