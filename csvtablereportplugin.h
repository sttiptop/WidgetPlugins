#ifndef CSVTABLEREPORTPLUGIN_H
#define CSVTABLEREPORTPLUGIN_H

#include "ireportplugin.h"
#include <QTableWidget>
#include <QTextTable>
#include <QTextCursor>
#include <QTextDocument>
#include <QTextDocumentWriter>
#include <QObject>
#include <QPushButton>
#include <QWidget>
namespace WidgetPlugins
{

class CSVTableReportPlugin:public IReportPlugin
{
    Q_OBJECT
public:
    CSVTableReportPlugin(QString fileName, QWidget *parent);
private:
    QPushButton * _btn = nullptr;
    QTableWidget *_tblwgt;
    // IWidgetPlugin interface
public:
    QWidget *getControl();
public slots:
    void handleSaveTableToFile();
};
}
#endif // CSVTABLEREPORTPLUGIN_H
