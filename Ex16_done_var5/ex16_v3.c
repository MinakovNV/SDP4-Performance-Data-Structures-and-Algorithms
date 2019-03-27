

// Ex 16
struct Deque{
    int p1[10];// = {1, 3, 5, 7, 9};
    int p2[10];// = {2,4,6,8,0};
};

struct Deque Game;


void push(){

    printf("Input 5 cards of 1st player");
    for (int i = 0; i<5; i++){
        scanf("%d", &Game.p1[i]);
    }

    printf("Input 5 cards of 2nd player");
    for (int i = 0; i<5; i++){
        scanf("%d", &Game.p2[i]);
    }

}

void check(){

    for (int i = 0; i<5; i++)
    {
        if (Game.p1[i] == 0){

            Game.p1[i] = 10;
        }

        if (Game.p2[i] == 0){
            Game.p2[i] = 10;
        }
    }
}

void pop(){
    int i = 0;
    int flag = 1;
    while (flag)
    {
        if (i>5)
        {
            i = 0;
        }
        i++;

        if (Game.p1[i] == NULL) {
            printf("Second, %d", i);
            flag = 0;
        } else if (Game.p2[i] == NULL) {
            printf("First, %d", i);
            flag = 0;
        } else {
            if (Game.p1[i] > Game.p2[i]) {
                int n = sizeof(Game.p1) / sizeof(Game.p1[0]);
                Game.p1[n + 1] = Game.p2[i];
            }
            if (Game.p1[i] < Game.p2[i]) {
                int n = sizeof(Game.p1) / sizeof(Game.p1[0]);
                Game.p2[n + 1] = Game.p1[i];
            }
        }
    }
}


void main()
{
    //Player 1
    Game.p1[0] = 1;
    Game.p1[1] = 3;
    Game.p1[2] = 5;
    Game.p1[3] = 7;
    Game.p1[4] = 9;
    //Player 2
    Game.p2[0] = 2;
    Game.p2[1] = 4;
    Game.p2[2] = 6;
    Game.p2[3] = 8;
    Game.p2[4] = 0;

    //push();
    check();
    pop();

}