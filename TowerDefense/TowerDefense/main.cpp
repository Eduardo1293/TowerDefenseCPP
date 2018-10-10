/*
ACHTUNG
Damit das Spiel im Visual Studio richtig kompiliert müssen in den Projekteinstellungen möglicherweise
die SFML Verzeichnisse angepasst werden.
*/

/*

-----SPACE DEFENDER-----

Einteilung sehr grob - im Grunde sind fast alle Einzelteile in Zusammenarbeit entstanden.

Stefan Reso         286788	   Spiellogik, Menü, Interface, Steuerung
Johannes Schmidt    293868     Gegner, Pathfinding, Gegnermovement, Balancing
Andre Jelonek       259031     Spiellogik, Türme, Turmlogik, Gegnermovement

Art by Kenney Vleugels (Kenney.nl)
used under Creative Commons Zero, CC0
http://creativecommons.org/publicdomain/zero/1.0/

and DinVStudio (https://dinvstudio.itch.io/)
used under free license

Music and Sound by musicfox.com
https://www.musicfox.com/info/kostenlose-gemafreie-musik.php
used under free license

Daniel Noronha (https://mrthenoronha.bandcamp.com)
and timgormly (https://freesound.org/people/timgormly/)
used under Attribution 3.0 Unported (CC BY 3.0)
https://creativecommons.org/licenses/by/3.0/

*/

#include "Menu.h"

int main() {

	
	Menu game;

	while (game.isRunning())
	{
		game.Run();
	}
}