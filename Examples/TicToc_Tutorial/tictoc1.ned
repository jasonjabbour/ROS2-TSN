simple Txc1
{
    parameters:
        bool sendMsgOnInit = default(false); // whether the module should send out a message on initialization
        int limit = default(20);   // another parameter with a default value
        @display("i=block/routing"); // add a default icon
    gates:
        input in;
        output out;
}

//
// Two instances (tic and toc) of Txc1 connected both ways.
// Tic and toc will pass messages to one another.
//
network Tictoc1
{
    @display("bgb=486.38998,385.94998");
    submodules:
        tic: Txc1 {
            sendMsgOnInit = true;
            @display("i=,cyan;p=127.409996,228.77998"); // do not change the icon (first arg of i=) just colorize it
            @display("p=76,140");
        }
        toc: Txc1 {
        	sendMsgOnInit = false;
            @display("i=,gold;p=306.9,111.6"); // do not change the icon (first arg of i=) just colorize it
            @display("p=165,61");
        }
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
}
