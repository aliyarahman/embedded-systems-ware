
/* ================================================================================================== +
                                   Arduino DJ metronome

        WHAT DOES THIS SKETCH (PROGRAM) DO?
        -----------------------------------
        This sketch turns the Arduino into a blinking metronome to help new vinyl DJs get a
        sense of two of the most common speeds for dance music. Right now if only does two
        kinds of standards beats - Chicago house (120 beats per minute), and old skool hip hop
        98 beats per minute).
        
        
        HOW DO YOU RUN THE SKETCH?
        --------------------------
        + In Section 1, comment out the lines for the kind of beats you DON'T wamt to see
        + Plug in the board and press run!
        
        
        WHAT HARDWARE DO YOU NEED TO RUN THIS SKETCH?
        -------------------------------------------
        + This sketch is written for the Arduino Uno
        + This sketch needs nothing other than the Arduino board itself to run.
        
        
        ANY OBVIOUS MODS?
        --------------------------------------------
        + If you want to run this on the Uno but with an external LED (bigger, different color), 
          go for it! But change the pin number in the first line of code depending on where
          you plug in the LED.
        + The sketch is written for the Uno, but you can run it on any board with an on-board 
          (or external) LED, as long as you put the right pin number in the first line of code.
        + Try a speaker as output! Beeps as well as blinks, but same function in the end.

+ ================================================================================================== */


//SECTION 1- INITIALIZE OUR VARIABLES
    //Initialize the on-board "L" LED, which sits at pin 13, and  
    int LED_pin = 13;

    // Initialize beat and silence lengths for Chicago house tempo (120 bpm) 
    // Comment out this section if you are looking for hip hop!
    //int beat = 200;
    //int silent = 300;
    
    // Initialize beat and silence lengths for hip hop tempo (98 bpm)
    // Comment out this section if you are looking for Chicago house!
    int beat = 200;
    int silent = 412;
    

//SECTION 2 - Every sketch needs a setup() function to fire up the parts we'll be using
    void setup()
    {
        pinMode(LED_pin, OUTPUT);  
    }


//SECTION 3 - Every sketch also needs a loop() function where the commands actually run
    void loop()
    {
    //TURN THE PIN ON
      digitalWrite(LED_pin, HIGH);  
      delay(beat);
      digitalWrite(LED_pin, LOW);
      delay(silent);
    }
