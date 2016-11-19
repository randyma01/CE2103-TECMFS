/*
 * mainWindow.h
 *
 *  Created on: 19 nov. 2016
 *      Author: gustavo
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <stdlib.h>
#include <iostream>
#include <string>


#include <qmainwindow.h>
#include <qaction.h>
#include <qlayout.h>
#include <qmenu.h>
#include <qmenubar.h>
#include <qstatusbar.h>
#include <qtextedit.h>
#include <qfile.h>
#include <qdatastream.h>
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qsignalmapper.h>
#include <qapplication.h>
#include <qpainter.h>
#include <QMouseEvent>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qlabel.h>
#include <qtoolbar.h>
#include <qpushbutton.h>
#include <qobjectdefs.h>


using namespace std;

//#redefine  Q_OBJECT

class mainWindow : public QMainWindow{

	Q_OBJECT_GETSTATICMETAOBJECT

	public:
	 	 mainWindow();
	 	 virtual ~mainWindow();
	 	 void setupMenuBar();

	signals:
		void openSig();

    public Q_SLOTS:
		void openFile();


    protected:
		#ifndef QT_NO_CONTEXTMENU
			void contextMenuEvent(QContextMenuEvent *event);
		#endif /*QT_NO_CONTEXTMENU*/

    public:
			QActionGroup *alignmentGroup;

	private:
		void createActions();
		void createMenus();
		bool load(const QString &f);

		QMenu *fileMenu;


		QAction *openAct;

};

#endif /* MAINWINDOW_H_ */
