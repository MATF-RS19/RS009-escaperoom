/*TODO:
    -Change pixmap of chest, when user solve puzzle
    -Add log to all classes that need to change log text
*/

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
        if(!getPlayer()->keyList.contains(getLK())){
            switch (getPlayer()->getCurrentLevel()) {
                case 4: {
                    //setting scene for first dynamic puzzle
                    DynamicPuzzle1 *dynamicPuzzle1Scene = new DynamicPuzzle1(view, view->scene(), getPlayer()->getCurrentLevel());
                    dynamicPuzzle1Scene->setPlayer(this->getPlayer());
                    dynamicPuzzle1Scene->setLevelKey(this->getLK());
                    view->setScene(dynamicPuzzle1Scene);
                    break;
                }
                default: {
                    //setting new scene for static puzzle
                    StaticPuzzle *puzzleScene = new StaticPuzzle(view, view->scene(), getPlayer()->getCurrentLevel());
                    puzzleScene->setPlayer(this->getPlayer());
                    puzzleScene->setLevelKey(this->getLK());
                    view->setScene(puzzleScene);
                }
            }
        }
    }
}
