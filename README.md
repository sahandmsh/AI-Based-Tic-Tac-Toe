# RL-Based-Tic-Tac-Toe

This project comes in two phases:
1) Training an AI tic-tac-toe player
2) Playing against the AI

For the first phase, Q-learning method is used to allow computer to properly learn and play tic-tac-toe. The RL againt interacts and learns while playing against
random moves. To make sure that RL observes as much states as possible, we may need to set a high number of games that RL plays against random player 
(e.g., 2 000 000).

After training phase is over, now a human player can start playing against the RL agent. It is noted that, the RL will continue to learn while playing against a human player.
Below you can see a sample of the simulation results (training RL agent over 2 000 000 round of playing against the random player). The AI uses "X" while the human player uses "@".

![Screenshot 2023-08-22 at 11 36 01 AM](https://github.com/sahandmsh/AI-Based-Tic-Tac-Toe/assets/82970651/e590a42d-642e-4791-8946-640f867c5368)


### Example of AI as the winner:

![Screenshot 2023-08-22 at 11 39 19 AM](https://github.com/sahandmsh/AI-Based-Tic-Tac-Toe/assets/82970651/edb1e7a7-896e-4f85-809e-1d3c92635aea)



### Example of Draw:

![Screenshot 2023-08-22 at 11 40 37 AM](https://github.com/sahandmsh/AI-Based-Tic-Tac-Toe/assets/82970651/641730d7-5e22-433b-8a7f-c5627d4b26f6)

