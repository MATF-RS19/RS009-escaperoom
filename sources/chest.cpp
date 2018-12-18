#include "headers/chest.hpp"

Chest::Chest(QPixmap picture) {
    setPixmap(picture);
}

Chest::~Chest(){

}

void Chest::mousePressEvent(QGraphicsSceneMouseEvent *){
}

void Chest::mousePressEvent(QGraphicsSceneMouseEvent *event, QGraphicsView *view){
    //checking mouse click and player distance from the chest
    if(event->button() == Qt::LeftButton && this->distance() < 100.0){
        //if player already have level key, user won't be able to open puzzle again
        if(!player->keyList.contains(level_key)){
            switch (player->currentLevel) {
                case 4: {
                    //setting scene for first dynamic puzzle
                    DynamicPuzzle1 *dynamicPuzzle1Scene = new DynamicPuzzle1(view, view->scene(), player->currentLevel);
                    dynamicPuzzle1Scene->player = this->player;
                    dynamicPuzzle1Scene->level_key = this->level_key;
                    view->setScene(dynamicPuzzle1Scene);
                    break;
                }
                default: {
                    //setting new scene for static puzzle
                    StaticPuzzle *puzzleScene = new StaticPuzzle(view, view->scene(), player->currentLevel);
                    puzzleScene->player = this->player;
                    puzzleScene->level_key = this->level_key;
                    view->setScene(puzzleScene);
                }
            }
        }
    }
}
