/*
 * mainWindow.cpp
 *
 *  Created on: 19 nov. 2016
 *      Author: gustavo
 */

#include "mainWindow.h"

mainWindow::mainWindow(){
	QWidget *widget = new QWidget;
	setCentralWidget(widget);
	setWindowTitle("Odissey MediaPlayer");
	setMinimumSize(360, 360);
	resize(1024, 780);
	createActions();
	createMenus();
}

mainWindow::~mainWindow() {
}


#ifndef QT_NO_CONTEXTMENU
void mainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(openAct);
    menu.exec(event->globalPos());
}
#endif // QT_NO_CONTEXTMENU


void mainWindow::createActions(){
	openAct = new QAction(tr("&Open"), this);
	openAct->setShortcut(QKeySequence::Open);
	openAct->setStatusTip(tr("Open a file video"));
	connect(openAct, SIGNAL(triggered()), this, SLOT(openFile()));
	alignmentGroup = new QActionGroup(this);
}

void mainWindow::createMenus(){
	 fileMenu = menuBar()->addMenu(tr("&File"));
	 fileMenu->addAction(openAct);
}

void mainWindow::openSig(){
	emit openFile();
}


void mainWindow::openFile(){
	QFileDialog fileDialog(this);
	fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
	fileDialog.setWindowTitle(tr("Open file"));
	fileDialog.setDirectory("/home/gustavo/workspace/TECMFS/videos");
	fileDialog.show();
	if (fileDialog.exec() == QDialog::Accepted){
		cout << (fileDialog.selectedNameFilter()).toAscii().data() << endl;
	}
}

void mainWindow::setupMenuBar(){

}
