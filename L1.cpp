#include <stdio.h>

void setup() {
    printf("\nThis happens one time");
}

void loop() {
    printf("\nThis happens forever...");
}

int main() {
    setup();        // run once

    for(;;) {       // infinite loop
        loop();
    }

    return 0;   // never reached
}
