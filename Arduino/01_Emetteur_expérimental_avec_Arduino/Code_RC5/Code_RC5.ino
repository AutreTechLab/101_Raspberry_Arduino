#include <IRremote.h>
 
//...et initialisation de cette librairie
IRsend irsend;
 
// Les réglages de la sortie à prendre en charge par la librairie
// Les sorties correspondantes sont différentes selon la carte Arduino utilisée
// Arduino UNO:  sortie = D3
// Arduino MEGA: sortie = D9
// Une liste complète des sorties correspondantes est visible à la page
// http://z3t0.github.io/Arduino-IRremote/

void setup()
{

}

int ThymioRC5Commands[10];

// Boucle de programme principale
void loop() {
        // L'émetteur envoie le signal Thymio_rc5_commands[x] (en hexadécimal) en codage 'RC5'.
        // Cette opération est répétée trois fois.Ensuite, une pause de 5 secondes est mise en place.
       

    ThymioRC5Commands[0] = 5; // 5 -> Arrêt
    ThymioRC5Commands[1] = 2; // 2 -> aller en avant
    ThymioRC5Commands[2] = 5; // 5 -> Arrêt 
    ThymioRC5Commands[3] = 4; // 4 -> tournez à gauche 
    ThymioRC5Commands[4] = 5; // 5 -> Arrêt
    ThymioRC5Commands[5] = 6; // 6 -> tournez à droite 
    ThymioRC5Commands[6] = 5; // 5 -> Arrêt
    ThymioRC5Commands[7] = 8; // 8 -> reculer 
    ThymioRC5Commands[8] = 5; // 5 -> Arrêt
    ThymioRC5Commands[9] = 5; // 5 -> Arrêt

    for (int x = 0; x < 10; x++) {
      
      for (int i = 0; i < 3; i++) {
          irsend.sendRC5(ThymioRC5Commands[x], 12); // Signal à envoyer
          delay(50);
      } 
    delay(4000); //Pause de 5 secondes entre les impulsions de transmission.
    }    
}

// The command comprises 14 bits:

// A start bit, which is always logic 1 and allows the receiving IC to set the proper gain.
// A field bit, which denotes whether the command sent is in the lower field (logic 1 = 0 to 63 decimal) or the upper field (logic 0 = 64 to 127 decimal). Originally a second start bit, the field bit was added later by Philips when it was realized that 64 commands per device were insufficient. Many devices still use the original system.
// A control bit, which toggles with each button press. This allows the receiving device to distinguish between two successive button presses (such as "1", "1" for "11") as opposed to the user simply holding down the button and the repeating commands being interrupted by a person walking by, for example.
// A five-bit system address, that selects one of 32 possible systems.
// A six-bit command, that (in conjunction with the field bit) represents one of the 128 possible RC-5 commands.
