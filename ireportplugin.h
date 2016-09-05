#ifndef IREPORTPLUGIN_H
#define IREPORTPLUGIN_H

#include "iwidgetplugin.h"
#include "QTextBlock"
#include <QObject>
#include <QTableWidget>
#include <QTextCursor>
#include <QTextDocument>
#include <QWidget>
namespace WidgetPlugins {

class IReportPlugin : public IWidgetPlugin
{
    Q_OBJECT
public:
    QWidget *getControl();
    IReportPlugin ();
    class ReportDocument final
    {
    public:
        static ReportDocument &getInstance();

        void setFileName(QString fileName);
        void addImage(QImage img);
        void addTable(QTableWidget *_tblwgt);

    protected:
        QTextDocument *_document=new QTextDocument;
        QTextCursor _cursor=QTextCursor(_document);

    private:
        ReportDocument(){}
        ~ReportDocument(){}
        ReportDocument(ReportDocument const&)=delete;
        ReportDocument(ReportDocument&&) = delete;
        ReportDocument& operator=(ReportDocument const&) = delete;
        ReportDocument& operator=(ReportDocument &&) = delete;
        QString _fName;
        int _countFile=0;
        int _count=0;
        void save();
    };

};
}
#endif // IREPORTPLUGIN_H
