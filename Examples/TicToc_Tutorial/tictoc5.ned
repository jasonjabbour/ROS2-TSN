simple Txc5
{
    parameters:
        bool sendMsgOnInit = default(false); // whether the module should send out a message on initialization
        int limit = default(2);   // another parameter with a default value
        @display("i=block/routing"); // add a default icon
    gates:
        input in;
        output out;
}

simple Tic5 extends Txc5
{
    parameters:
        @display("i=,cyan");
        sendMsgOnInit = true;   // Tic modules should send a message on init
}

simple Toc5 extends Txc5
{
    parameters:
        @display("i=,gold");
        sendMsgOnInit = false;  // Toc modules should NOT send a message on init
}

//
// Two instances (tic and toc) of Txc1 connected both ways.
// Tic and toc will pass messages to one another.
//
network Tictoc5
{
    @display("bgb=486.38998,385.94998");
    submodules:
	    tic: Tic5;  // the limit parameter is still unbound here. We will get it from the ini file
        toc: Toc5;
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
}
