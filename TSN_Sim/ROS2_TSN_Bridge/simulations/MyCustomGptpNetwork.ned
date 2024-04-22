package ros2_tsn_bridge.simulations;

import inet.linklayer.ieee8021as.GptpSlave;
import ros2_tsn_bridge.CustomGptpMaster;  // Import custom gPTP module

channel EthernetChannel extends ned.DatarateChannel {
    datarate = 100Mbps; // Example datarate
    delay = 1ms;        // Example delay
}

network MyCustomGptpNetwork {
    submodules:
        myCustomGptpMaster: CustomGptpMaster {  // Use your custom module
            // Set parameters or display properties here if needed
            @display("p=100,200");
        }
        gptpSlave: GptpSlave {
            // Set parameters or display properties here if needed
            @display("p=300,200");
        }
    connections:
        myCustomGptpMaster.ethg++ <--> EthernetChannel <--> gptpSlave.ethg++;
}

