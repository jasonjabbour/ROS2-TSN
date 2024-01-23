simple Txc1
{
    gates:
        input in;
        output out;
}

// 
// Two instances (tic and toc) of Txc1 connected both ways
// Tic and toc will pass messages to one another
//
network Tictoc1
{
    @display("bgb=185,147");
    submodules:
        tic: Txc1;
        toc: Txc1 {
            @display("p=94,87");
        }
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
}
