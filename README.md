# CRL
A roguelike I'm developing in C, using ncurses so that I can use the terminal to its full potential.
# NOTE
There is currently a fatal error in the code - I'm uploading it to Github anyway so that if anyone can possibly help me fix it,
they can help me. 

The error is as follows (according to gbd):
  > 0x00400cf2 in movePlayer (newPosition=0x41be30, user=0x41b330, level=0x41a7d0) at ./src/player.c:72
> mvaddch\(user->position.y, user->position.x, level\[user->position.y\]\[user->position.x\]\);

I'd greatly appreciate help in solving this problem with it segfaulting, thank you.
