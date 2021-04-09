#ifndef GAMESTRUCT_H_
#define GAMESTRUCT_H_

#include <pthread.h>

//Used for game create callback
struct gameCreateCallbackWaitParam {   
    char *gameName;
    int   gameID, 
    sendTime;
    void (*callbackFn) (struct gameCreateCallbackWaitParam *);
};

//Game list
struct gameList {
    struct gameListNode *gamesHead;
    pthread_mutex_t mutex;
};

struct gameListNode {
    struct game *currentGame;
    struct gameListNode *nextGame;
};

struct game {
    int gameID, 
        started;
    long startTime;
};

// Add to non-circular linked-list
struct game *createGame(int gameID);

// Init the game list structure
void initGameList(struct gameList *gl);

void freeGameCreateCallbackWaitParam(struct gameCreateCallbackWaitParam *gp);

void freeGameListNode(struct gameList *g, struct gameListNode *gl);

void freeGameList(struct gameList *g);

struct game *getGameWithID(struct gameList *g, int gameID);

void addGame (struct gameList *g, struct game *gamePointer);

void removeGame (struct gameList *g, struct game *gamePointer);

#endif
