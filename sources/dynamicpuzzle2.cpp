#include "headers/dynamicpuzzle2.h"

DynamicPuzzle2::DynamicPuzzle2(QGraphicsView *parent, QGraphicsScene *scene, qint16 cl)
    : Puzzle(parent, scene, cl)
{
    setBackgroundBrush(QImage(":/resources/puzzles/fifteen_puzzle/frame1.png"));
    setSceneRect(0, 0, 1280, 720);
    _closeBtn = new QGraphicsRectItem(1200, 0, 80, 80);
    _closeBtn->setBrush(QImage(":/resources/buttons/close_btn.png"));
    _closeBtn->setFlag(QGraphicsItem::ItemIsFocusable);
    this->addItem(_closeBtn);
    initializePuzzle();

}
void DynamicPuzzle2::initializePuzzle(){
    QString base(":/resources/puzzles/fifteen_puzzle/");
    for(qint16 j = 0; j < 4; j++){
        for(qint16 i = 0; i < 4; i++) {
            auto s1 = base + QString::number(j*4 + i) + ".png";
            QGraphicsPixmapItem* tilePixmap = new QGraphicsPixmapItem(QPixmap(QString(s1)));
            QPair<QGraphicsPixmapItem*, qint16> item(tilePixmap, j*4 + i);
            _tiles.push_back(std::move(item));
            _tiles.at(j*4 + i).first->setPos(QPoint(337+151*i, 58+151*j));
        }
    }
    for(qint16 i = 0; i < 4; i++) {
        for(qint16 j = 0; j < 4; j++) {
            this->addItem(_tiles.at(4*i + j).first);
        }
    }
    int i = 0;
    int position = _tiles.size() - 1;
    int nextPosition = 0;
    while(i < NUM_OF_ITERS){
        nextPosition = std::rand();
        switch(position) {
            case 0: {
                if ( nextPosition % 2 == 0) {
                    nextPosition = position + 1;
                }
                else {
                    nextPosition = position + 4;
                }
                break;
            }
            case 1:
            case 2: {
                if ( nextPosition % 3 == 0) {
                    nextPosition = position - 1;
                }
                else if ( nextPosition % 3 == 1){
                    nextPosition = position + 1;
                }
                else {
                    nextPosition = position + 4;
                }
                break;
            }
            case 3: {
                if ( nextPosition % 2 == 0){
                    nextPosition = position - 1;
                }
                else {
                    nextPosition = position + 4;
                }
                break;
            }
            case 4:
            case 8: {
                if ( nextPosition % 3 == 0){
                    nextPosition = position + 1;
                }
                else if ( nextPosition % 3 == 1) {
                    nextPosition = position + 4;
                }
                else {
                    nextPosition = position - 4;
                }
                break;
            }
            case 5:
            case 6:
            case 9:
            case 10: {
                if ( nextPosition % 4 == 0){
                    nextPosition = position + 1;
                }
                else if (nextPosition % 4 == 1){
                    nextPosition = position - 1;
                }
                else if (nextPosition % 4 == 2){
                    nextPosition = position + 4;
                }
                else {
                    nextPosition = position - 4;
                }
                break;
            }
            case 7:
            case 11: {
                if ( nextPosition % 3 == 0 ){
                    nextPosition = position - 1;
                }
                else if ( nextPosition % 3 == 1 ) {
                    nextPosition = position + 4;
                }
                else {
                    nextPosition = position - 4;
                }
                break;
            }
            case 12: {
                if ( nextPosition % 2 == 0){
                    nextPosition = position + 1;
                }
                else {
                    nextPosition = position - 4;
                }
                break;
            }
            case 13:
            case 14: {
                if ( nextPosition % 3 == 0){
                    nextPosition = position + 1;
                }
                else if ( nextPosition % 3 == 1){
                    nextPosition = position - 1;
                }
                else {
                    nextPosition = position - 4;
                }
                break;
            }
            case 15: {
                if ( nextPosition % 2 == 0){
                    nextPosition = position - 4;
                }
                else {
                    nextPosition = position - 1;
                }
            }
        }
        swapTiles(position, nextPosition);
        i++;
    }

}

void DynamicPuzzle2::swapTiles(int &position, int nextPosition){
    auto tmp = _tiles.begin() + nextPosition;
    QPair<qreal, qreal> current(_tiles.at(position).first->x(),_tiles.at(position).first->y());
    QPair<qreal, qreal> next(tmp->first->x(),tmp->first->y());
    _tiles.at(position).first->setPos(next.first, next.second);
    _tiles.at(nextPosition).first->setPos(current.first, current.second);
    std::iter_swap(_tiles.begin() + position, _tiles.begin() + nextPosition);
    position = nextPosition;
}
void DynamicPuzzle2::mousePressEvent(QGraphicsSceneMouseEvent *){
    if(_closeBtn->isUnderMouse()){
        puzzleOver();
    }
    for(int i = 0; i < 16; i++){
        if (_tiles.at(i).first->isUnderMouse()){
            switch(i) {
                case 0: {
                    if(_tiles.at(i+1).second == 15){
                        swapTiles(i, i+1);
                    }
                    else if(_tiles.at(i+4).second == 15){
                        swapTiles(i, i+4);
                    }
                    break;
                }
                case 1:
                case 2: {
                    if(_tiles.at(i+1).second == 15){
                        swapTiles(i, i+1);
                    }
                    else if(_tiles.at(i-1).second == 15) {
                        swapTiles(i, i-1);
                    }
                    else if(_tiles.at(i+4).second == 15) {
                        swapTiles(i, i+4);
                    }
                    break;

                }
                case 3: {
                    if (_tiles.at(i-1).second == 15){
                        swapTiles(i, i-1);
                    }
                    else if (_tiles.at(i+4).second == 15){
                        swapTiles(i, i+4);
                    }
                    break;
                }
                case 4:
                case 8: {
                    if (_tiles.at(i+1).second == 15){
                        swapTiles(i,i+1);
                    }
                    else if(_tiles.at(i+4).second == 15){
                        swapTiles(i, i+4);
                    }
                    else if(_tiles.at(i-4).second == 15) {
                        swapTiles(i, i-4);
                    }
                    break;
                }
                case 5:
                case 6:
                case 9:
                case 10: {
                    if(_tiles.at(i-1).second == 15){
                        swapTiles(i, i-1);
                    }
                    else if(_tiles.at(i+1).second == 15){
                        swapTiles(i, i+1);
                    }
                    else if(_tiles.at(i+4).second == 15){
                        swapTiles(i, i+4);
                    }
                    else if(_tiles.at(i-4).second == 15){
                        swapTiles(i, i-4);
                    }
                    break;
                }
                case 7:
                case 11:{
                    if(_tiles.at(i-1).second == 15){
                        swapTiles(i, i-1);
                    }
                    else if(_tiles.at(i+4).second == 15){
                        swapTiles(i, i+4);
                    }
                    else if(_tiles.at(i-4).second == 15){
                        swapTiles(i, i-4);
                    }
                    break;
                }
                case 12: {
                    if(_tiles.at(i-4).second == 15){
                        swapTiles(i, i-4);
                    }
                    else if(_tiles.at(i+1).second == 15){
                        swapTiles(i, i+1);
                    }
                    break;
                }
                case 13:
                case 14:{
                    if(_tiles.at(i-1).second == 15){
                        swapTiles(i, i-1);
                    }
                    else if(_tiles.at(i+1).second == 15){
                        swapTiles(i, i+1);
                    }
                    else if(_tiles.at(i-4).second == 15){
                        swapTiles(i, i-4);
                    }
                    break;
                }
                case 15: {

                    if(_tiles.at(i-1).second == 15){
                        swapTiles(i, i-1);
                    }
                    else if(_tiles.at(i-4).second == 15){
                        swapTiles(i, i-4);
                    }
                    break;
               }
           }
        }
    }
    checkResult();
}


void DynamicPuzzle2::puzzleOver(){
    this->deleteLater();
    getView()->setScene(getScene());
}

void DynamicPuzzle2::checkResult(){
    QVector<int> val;
    for(auto tile : _tiles){
        val.push_back(tile.second);
    }
    if(std::is_sorted(val.begin(), val.end())){
        getLK()->setKeyAvailability(true);
        getLog()->setText("Chest unlocked, click to get key");
        puzzleOver();
    }
}
