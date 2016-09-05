#ifndef CSVTABLEPLUGIN_H
#define CSVTABLEPLUGIN_H
#include "widgetplugins_global.h"
#include "iwidgetplugin.h"
#include <QPushButton>
#include <QWidget>
#include <QObject>
#include <QTableWidget>
#include <QApplication>
#include <QClipboard>
#include <QTextTable>
#include <QTextCursor>
#include <QTextDocument>
#include <QTextDocumentWriter>
#include <QFileDialog>
#include <QMimeData>

namespace WidgetPlugins
{

class CSVTablePlugin:public IWidgetPlugin
{
    Q_OBJECT
public:
    CSVTablePlugin(QWidget *parent=0);
    QWidget *getControl();
    QTableWidget *_tblwgt;
private:
    QPushButton * _btn = nullptr;

    // IWidgetPlugin interface
public slots:
    void  handleSaveTable();
};
}

#endif // CSVTABLEPLUGIN_H
