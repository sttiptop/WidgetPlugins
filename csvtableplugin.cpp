#include "csvtableplugin.h"
#include "QDebug"
namespace WidgetPlugins
{
CSVTablePlugin::CSVTablePlugin(QWidget *parent)
{
    setParent(parent);
    _wgt=parent;
    _btn=new QPushButton(_wgt);
    _btn->setStyleSheet("QPushButton{"
                        "border-image: url(:/icons/tableIcon.png);"
                        "border-radius: 2px;"
                        "}"
                        "QPushButton:hover{"
                        "border-image: url(:/icons/TableIconPressed.png);"
                        "border-radius: 1px;"
                        "}"
                        "QPushButton:pressed{"
                        "border-image: url(:/icons/TableIconPressed.png);"
                        "border-radius: 1px;"
                        "margin:2px;"
                        "}");
    connect(_btn,SIGNAL(clicked(bool)),this,SLOT(handleSaveTable()));

}

QWidget *CSVTablePlugin::getControl()
{
    return _btn;
}

void CSVTablePlugin::handleSaveTable()
{

    if(qobject_cast<QTableWidget*>(_wgt)){
        _tblwgt=qobject_cast<QTableWidget*>(_wgt);
    }
    else{
        _tblwgt = _wgt->findChild<QTableWidget*>();
    }

    QTextDocument *_document=new QTextDocument;
    QTextCursor _cursor=QTextCursor(_document->begin() );
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
    QClipboard *_clipboard = QApplication::clipboard();
    QMimeData *_mimeData = new QMimeData();
    _mimeData->setHtml(_document->toHtml());
    _clipboard->setMimeData(_mimeData, QClipboard::Clipboard);
}
}
