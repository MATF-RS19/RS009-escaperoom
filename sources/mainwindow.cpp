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

//starting new game
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

//setting textEdit field visible, so user can enter his/her username
void MainWindow::on_newGame_btn_clicked() {

    _ui->newGameTE->setVisible(true);
    _ui->newGameTE->setEnabled(true);
    _ui->newGame_conf_btn->setVisible(true);

}

//if lenght of username is > 0, user can confirm that username
void MainWindow::on_newGameTE_textChanged() {
    if(_ui->newGameTE->toPlainText().size() > 0 )
        _ui->newGame_conf_btn->setEnabled(true);
    else
        _ui->newGame_conf_btn->setEnabled(false);
}

//checking is username alredy exist and if doesn't create new json file and start game,
//otherwise ask user if he/she want to erase old data and start game all over again
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

//make json file for new user or rewrite data for old one
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

//load old user's data from json and start game where he/she left off
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

//setting textEdit field visible, so user can enter his/her existing username
void MainWindow::on_loadGame_btn_clicked() {
    _ui->loadGameTE->setVisible(true);
    _ui->loadGameTE->setEnabled(true);
    _ui->loadGame_conf_btn->setVisible(true);
}

//if lenght of username is > 0, user can confirm that username
void MainWindow::on_loadGameTE_textChanged() {
    if(_ui->loadGameTE->toPlainText().size() > 0 )
        _ui->loadGame_conf_btn->setEnabled(true);
    else
        _ui->loadGame_conf_btn->setEnabled(false);
}

//checking is username alredy exist and if does loas json file and continue game
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

//read highscores txt file, sort all data by score and write it in list on left side
void MainWindow::on_highscore_btn_clicked() {
    QFile qf("../RS009-escaperoom/resources/highscores.txt");
    QString line;
    if(qf.open(QIODevice::ReadOnly)){
        QVector<QPair<QString, qint32>> players;
        while((line = qf.readLine()) != nullptr){
            if(line.trimmed().size() == 0) continue;
            QStringList reci = line.split(' ');
            QPair<QString, qint32> onePlayer(reci.at(0).trimmed(),
                                             reci.size() > 1 ? reci.at(1).trimmed().toInt() : 0 /*For now, because _score->text return ""*/);
            players.push_back(onePlayer);
        }
        std::sort(std::begin(players), std::end(players),
                  [](const QPair<QString, qint32> &first, const QPair<QString, qint32> &second) {return first.second > second.second;});

        for(qint32 i = 0, n = players.size(); i < n; ++i)
            _ui->highscoreList->addItem(players.at(i).first + "\t" + QString::number(players.at(i).second));
    }
    qf.close();
}

void MainWindow::on_exit_btn_clicked(){
    this->close();
}
