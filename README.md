# Simple Shields for Doom
A Simple Shield mod that replaces Armor in Doom with Tiered Shields which recharge overtime and cannot be lost.

Currently there are 4 Shields:

##### Shield Type I - The Shield you spawn with.
Maximum Charge: 50 (can be configured via menudef or console cvar)
Delay: 8 seconds (can be configured via menudef or console cvar)
Charge Rate: 1/9s

##### Shield Type II - Replaces Green Armor
Maximum Charge: 100 (can be configured via menudef or console cvar)
Delay: 7 seconds (can be configured via menudef or console cvar)
Charge Rate: 1/12s

##### Shield Type III - Replaces Blue Armor
Maximum Charge: 200 (can be configured via menudef or console cvar)
Delay: 6 seconds (can be configured via menudef or console cvar)
Charge Rate: 1/12s

##### Shield Type IV - Can randomly replace Megasphere (1/10 chance)
Maximum Charge: 300 (can be configured via menudef or console cvar)
Delay: 5 seconds (can be configured via menudef or console cvar)
Charge Rate: 1/12s

## Compatibility with mods

The mod currently replaces:
* Green Armor -> Shield Type II
* Blue Armor -> Shield Type III
* Megasphere -> Random Spawner (Custom Megasphere, Shield Type IV)
* Armor Bonus -> Health Bonus

It doesn't replace the player, it's all ACS Magic.

Plays perfectly in GZDoom/ZDoom ("Multiplayer" compatible)

It's also compatible with Zandronum3, but you have to remove the MENUDEF to make it work.
You can find a Zan version on my server.

## ToDo

* ~~Make charge rate changeable
* Make SubTiers(?)
* More Randomization
* Make a special version ;)


Special Thanks to Jigsaw (Zandronum Forum Name) for introducing me to ACS.

