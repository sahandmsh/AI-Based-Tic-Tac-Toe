# RL-Based-Tic-Tac-Toe

This project comes in two phases:
1) Training an AI tic-tac-toe player
2) Playing against the AI

For the first phase, Q-learning method is used to allow computer to properly learn and play tic-tac-toe. The RL againt interacts and learns while playing against
random moves. To make sure that RL observes as much states as possible, we may need to set a high number of games that RL plays against random player 
(e.g., 2 000 000).

After training phase is over, now a human player can start playing against the RL agent. It is noted that, the RL will continue to learn while playing against a human player.
Below you can see a sample of the simulation results (training RL agent over 2 000 000 round of playing against the random player). The AI uses "X" while the human player uses "@".

![Screenshot 2023-08-22 at 11 36 01 AM](https://github.com/sahandmsh/RL-Based-Tic-Tac-Toe/assets/82970651/8c98a672-c00c-4eb9-befd-998952fa700e)

Example of AI as the winner:

![Screenshot 2023-08-22 at 11 39 19 AM](https://github.com/sahandmsh/RL-Based-Tic-Tac-Toe/assets/82970651/9d9bb093-bb9d-4e70-b363-6e16cabd91ae)


Example of Draw:

![Screenshot 2023-08-22 at 11 40 37 AM](https://github.com/sahandmsh/RL-Based-Tic-Tac-Toe/assets/82970651/aa29113d-2fa4-4e69-81fd-0c9f9b0d65d2)
