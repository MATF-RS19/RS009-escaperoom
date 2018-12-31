#include "headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete _ui;
}

void MainWindow::newGame(QString name) {
    //making new game
    _game.reset(new Game(_ui->display, name));
    //setting scene
    _ui->display->setScene(&(*_game));
    //setting game scene to be main scene
    _ui->display->raise();
    //setting focus on game scene
    _ui->display->setFocus();
}

void MainWindow::on_newGame_btn_clicked() {

    _ui->newGameTE->setVisible(true);
    _ui->newGameTE->setEnabled(true);
    _ui->newGame_conf_btn->setVisible(true);

}

void MainWindow::on_newGameTE_textChanged() {
    if(_ui->newGameTE->toPlainText().size() > 0 )
        _ui->newGame_conf_btn->setEnabled(true);
    else
        _ui->newGame_conf_btn->setEnabled(false);
}

void MainWindow::on_newGame_conf_btn_clicked() {
    QString username = _ui->newGameTE->toPlainText();
    QFile qf("../RS009-escaperoom/resources/username_json/" + username + ".json");

    if(qf.exists()){
        qint32 answer = QInputDialog::getInt(this, "Korisnik vec postoji", "Ako zelite da prebriste podatke, unesite 1");
        if(answer == 1){
            writeJson(username);
            newGame(username);
        }
    }
    else{
        writeJson(username);
        newGame(username);
    }
}

void MainWindow::writeJson(QString name) {
    QFile qf("../RS009-escaperoom/resources/username_json/" + name + ".json");
    qf.open(QIODevice::WriteOnly);
    QJsonDocument qjd;
    QJsonObject qjo;
    qjo.insert("CurrentLevel", QJsonValue(0));
    qjo.insert("UniversalKey", QJsonValue(false));
    qjd.setObject(qjo);
    qf.write(qjd.toJson());
    qf.close();
}

void MainWindow::readJsonAndStartGame(QString name) {
    QFile qf("../RS009-escaperoom/resources/username_json/" + name + ".json");
    qf.open(QIODevice::ReadOnly);
    QJsonDocument qjd = QJsonDocument::fromJson(qf.readAll());
    qf.close();
    qint32 currLevel = qjd["CurrentLevel"].toInt();
    bool doesHaveUniversalKey = qjd["UniversalKey"].toBool();

    //making new game
    _game.reset(new Game(_ui->display, name, qint16(currLevel), doesHaveUniversalKey));
    //_game.get()->getPlayer()->setUsername(" ");
    //setting scene
    _ui->display->setScene(&(*_game));
    //setting game scene to be main scene
    _ui->display->raise();
    //setting focus on game scene
    _ui->display->setFocus();
}

void MainWindow::on_loadGame_btn_clicked() {
    _ui->loadGameTE->setVisible(true);
    _ui->loadGameTE->setEnabled(true);
    _ui->loadGame_conf_btn->setVisible(true);
}

void MainWindow::on_loadGameTE_textChanged() {
    if(_ui->loadGameTE->toPlainText().size() > 0 )
        _ui->loadGame_conf_btn->setEnabled(true);
    else
        _ui->loadGame_conf_btn->setEnabled(false);
}

void MainWindow::on_loadGame_conf_btn_clicked() {
    QString username = _ui->loadGameTE->toPlainText();
    QFile qf("../RS009-escaperoom/resources/username_json/" + username + ".json");

    if(qf.exists()){
        readJsonAndStartGame(username);
    }
    else{
        _ui->loadGameTE->setText("Username dosen't exist");
    }
}

void MainWindow::on_highscore_btn_clicked() {
    QFile qf("../RS009-escaperoom/resources/highscores.json");
    qf.open(QIODevice::ReadOnly);
    QJsonDocument qjd = QJsonDocument::fromJson(qf.readAll());
    qf.close();
    QJsonArray arrayOfBest = qjd["results"].toArray();
    QVector<QPair<QString, qint32>> best;
    qint32 n = arrayOfBest.size();
    for(qint32 i = 0; i < n; ++i){
        QPair<QString, qint32> curr;
        curr.first = arrayOfBest.at(i)["name"].toString();
        curr.second = arrayOfBest.at(i)["score"].toInt();
        best.push_back(curr);
    }

    std::sort(std::begin(best), std::end(best),
              [](const QPair<QString, qint32> &first, const QPair<QString, qint32> &second) {return first.second > second.second;});

    for(qint32 i = 0; i < n; ++i)
        _ui->highscoreList->addItem(best.at(i).first + "\t" + QString::number(best.at(i).second));
}

void MainWindow::on_exit_btn_clicked(){
    this->close();
}
