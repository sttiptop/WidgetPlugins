#include "csvtablereportplugin.h"
namespace WidgetPlugins {
CSVTableReportPlugin::CSVTableReportPlugin(QString fileName,QWidget *parent)
{
    setParent(parent);
    _wgt=parent;    
    _btn=new QPushButton;
    _btn->setStyleSheet("QPushButton{"
                       "border-image: url(:/icons/tableIconSaveToFile.png);"
                       "border-radius: 2px;"
                       "}"
                       "QPushButton:hover{"
                       "border-image: url(:/icons/tableIconSaveToFilePressed.png);"
                       "border-radius: 1px;"
                       "}"
                       "QPushButton:pressed{"
                       "border-image: url(:/icons/tableIconSaveToFilePressed.png);"
                       "border-radius: 1px;"
                       "margin:2px;"
                       "}");
    connect(_btn,SIGNAL(clicked(bool)),this,SLOT(handleSaveTableToFile()));
}

QWidget *WidgetPlugins::CSVTableReportPlugin::getControl()
{
    return _btn;
}

void CSVTableReportPlugin::handleSaveTableToFile()
{
    if(qobject_cast<QTableWidget*>(_wgt)){
        _tblwgt=qobject_cast<QTableWidget*>(_wgt);
    }
    else{
        _tblwgt = _wgt->findChild<QTableWidget*>();
    }
    ReportDocument::getInstance().addTable(_tblwgt);

}
}
