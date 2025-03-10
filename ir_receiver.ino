#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

#define IR_RECEIVE_PIN 32  // Change this to your actual pin

IRrecv irrecv(IR_RECEIVE_PIN);
decode_results results;

void setup() {
    Serial.begin(115200);
    irrecv.enableIRIn();  // Start the receiver
    Serial.println("IR Receiver ready...");
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.println("IR Signal Received!");
        Serial.println(resultToHexidecimal(&results));  // Print hex code of received signal
        irrecv.resume();  // Receive the next signal
    }
}
