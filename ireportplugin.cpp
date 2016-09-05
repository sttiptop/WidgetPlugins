#include "ireportplugin.h"

#include <QTextDocumentWriter>
#include <QTextTable>

namespace WidgetPlugins {
IReportPlugin::ReportDocument &IReportPlugin::ReportDocument::getInstance(){
    static IReportPlugin::ReportDocument instance;
    return instance;
}

void IReportPlugin::ReportDocument::setFileName(QString fileName)
{
    _fName=fileName;
    _fName.remove(_fName.size()-4,4);
    _fName.push_back("_");
    _fName.push_back(QString::number(_countFile));
    _fName.push_back(".odf");


}

void IReportPlugin::ReportDocument::addImage(QImage img)
{
    if(_count<100){
        _cursor=QTextCursor(_document->end());
        _cursor.insertImage(img);
        _count++;
        return;
    }
    else{ _count=0;
        save();
        _document->clear();
        addImage(img);
    }
}

void IReportPlugin::ReportDocument::addTable(QTableWidget *_tblwgt)
{
    if(_count<2){
        _cursor=QTextCursor(_document->end());
        _cursor.beginEditBlock();
        QTextTable *_table=_cursor.insertTable(_tblwgt->rowCount()+1,_tblwgt->columnCount()+1);
        for(int i=0;i<_tblwgt->rowCount()+1;i++){
            for(int j=0;j<_tblwgt->columnCount()+1;j++){
                if(i==0){
                    if(j>0){
                        if(_tblwgt->horizontalHeaderItem(j-1)!=0){
                            QTableWidgetItem *_itemh=_tblwgt->horizontalHeaderItem(j-1);
                            QTextTableCell _cell=_table->cellAt(0,j);
                            QTextCursor _cursor=_cell.firstCursorPosition();
                            _cursor.insertHtml(_itemh->text());
                        }
                    }
                }
                else{
                    if(j==0){
                        if(i>0){
                            if(_tblwgt->verticalHeaderItem(i-1)!=0){
                                QTableWidgetItem *_itemh=_tblwgt->verticalHeaderItem(i-1);
                                QTextTableCell _cell=_table->cellAt(i,0);
                                QTextCursor _cursor=_cell.firstCursorPosition();
                                _cursor.insertHtml(_itemh->text());
                            }
                        }
                    }else{
                        QTableWidgetItem *_item=_tblwgt->item(i-1,j-1);
                        QTextTableCell _cell=_table->cellAt(i,j);
                        QTextCursor _cursor=_cell.firstCursorPosition();
                        _cursor.insertHtml(_item->text());
                    }
                }
            }
        }
        _cursor.endEditBlock();
        _count++;
        qDebug()<<_count;
        return;
    }else{_count=0;
        save();
        _document->clear();
        addTable(_tblwgt);
    }
}

void IReportPlugin::ReportDocument::save()
{
    if(_fName.contains(".odf")){
        QTextDocumentWriter writer(_fName);
        writer.write(_document);
        _countFile++;
        _fName.remove(_fName.size()-5,5);
        _fName.push_back(QString::number(_countFile));
        _fName.push_back(".odf");

    }
}

QWidget *IReportPlugin::getControl(){}

IReportPlugin::IReportPlugin()
{

}


}
