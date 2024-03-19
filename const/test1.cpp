#include "stdio.h"

const double ASpecRatio = 1.68;

class GamePlayer {
    static const int NumTurns = 5;
    int scores[NumTurns];
    public: 
    void setScore( int score) {
        scores[0] = score;
    };
    int getScore( int idx) {
        return scores[idx];
    };
};

int main()
{
    printf("test \r\n");
    GamePlayer p;
    p.setScore(2);
    printf("test p.scores[0] %d \r\n", p.getScore(0));
    return 0;
}
