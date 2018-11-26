#include "headers/game.h"

Game::Game(QGraphicsView *) {

    scene = new QGraphicsScene;
    //background of scene
    scene->setBackgroundBrush(QImage(":/resources/levels/firstlevel_0_3_1_1.png"));

    player = new Player();
    player->setPos(sceneWidth/2, sceneHeight/2);
    //setting player ahead of gift, because first we add player to the scene, then gift, so gift's z-value is lower than player's
    player->setZValue(5);
    player->setScale(0.04);
    //enabling keyboard inputs
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    //focusing item, so it can catch keyboard inputs
    player->setFocus();
    scene->addItem(player);

    gift = new Gift();
    //hardcoded coordinates, for now
    gift->setPos(565, 255);
    gift->setScale(0.04);
    gift->setFlag(QGraphicsItem::ItemIsFocusable);
    gift->player = player;
    scene->addItem(gift);

    //setting scene, setting origin in top, left corner,
    //setting size to 1280x720 and disabeling size changing
    setScene(scene);
    setSceneRect(0, 0, sceneWidth, sceneHeight);
    //setting fixed size of scene + a little adjusment to height, at least for now
    setFixedSize(sceneWidth, sceneHeight+15);

    show();
}

Game::~Game(){

}


//if user click on box on the scene, keyPressEvent function from gift class will be called
void Game::mousePressEvent(QMouseEvent *event){
    if(gift->isUnderMouse())
        gift->mousePressEvent(event);
}

//if user press double click somewhere on the scene, player will stay in focus
void Game::mouseDoubleClickEvent(QMouseEvent *event){
    if(event->KeyPress)
        player->setFocus();
}
