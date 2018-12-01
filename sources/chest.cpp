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
        //setting new scene for puzzle
        Puzzle_1 *scene = new Puzzle_1(view, view->scene());
        scene->player = this->player;
        scene->level_key = this->level_key;
        view->setScene(scene);
    }
}
