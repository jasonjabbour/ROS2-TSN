simple Txc7
{
    parameters:
        volatile double delayTime @unit(s);   // delay before sending back message
        @display("i=block/routing"); // add a default icon
    gates:
        input in;
        output out;
}

simple Tic7 extends Txc7
{
    parameters:
        @display("i=,cyan");
}

simple Toc7 extends Txc7
{
    parameters:
        @display("i=,gold");
}

//
// Two instances (tic and toc) of Txc1 connected both ways.
// Tic and toc will pass messages to one another.
//
network Tictoc7
{
    @display("bgb=486.38998,385.94998");
    submodules:
	    tic: Tic7;  // the limit parameter is still unbound here. We will get it from the ini file
        toc: Toc7;
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
}
