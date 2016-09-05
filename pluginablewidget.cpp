#include "ireportplugin.h"
#include "pluginablewidget.h"
namespace WidgetPlugins {
PluginableWidget::PluginableWidget(QWidget *parent, PluginInPlace place, QColor color)
{
    _pluginPanelColor=color;
    this->_plaginPanelPlace=place;



}

PluginableWidget::PluginableWidget(QWidget *parent, PluginInPlace place, QColor color, QList<PluginType> types)
{
    addPlugin(parent,types);
    _pluginPanelColor=color;
    this->_plaginPanelPlace=place;

}

PluginableWidget::PluginableWidget(QWidget *parent, PluginInPlace place, QColor color, QList<PluginType> types, QString fileName)
{

    _pluginPanelColor=color;
    this->_plaginPanelPlace=place;
    IReportPlugin::ReportDocument::getInstance().setFileName(fileName);
    addPlugin(parent,types,fileName);



}

void PluginableWidget::addPlugin(QWidget *parent, QList<PluginType> types,QString fileName)
{
    _pluginPanel=new PluginPanel(_plaginPanelPlace,_pluginPanelColor);
    _pluginPanel->setParent(parent);

    _pluginPanelAnimationPropertyShow=new QPropertyAnimation(_pluginPanel,"pos",_pluginPanel->parentWidget());
    _pluginPanelAnimationPropertyHide=new QPropertyAnimation(_pluginPanel,"pos",_pluginPanel->parentWidget());

    foreach (PluginType t, types) {
        _pluginControls.insert(t,PluginFactory::createPluginTest(parent,t,fileName));

    }
    IWidgetPlugin *_iwgt;
    QMap<PluginType, QSharedPointer<IWidgetPlugin> >::iterator it = _pluginControls.begin();
    for(;it != _pluginControls.end(); ++it)
    {
        _iwgt=it.value().data();
        _pluginPanel->addWidgetAtPanel(_iwgt->getControl());
    }
    _timer = new QTimer(parent);
    connect(_pluginPanel,SIGNAL(enter()),this,SLOT(handleShowPluginPanel()));
    connect(_pluginPanel,SIGNAL(enter()),_timer,SLOT(stop()));
    connect(_pluginPanel,SIGNAL(drop(int)),_timer,SLOT(start(int)));
    connect(_timer,SIGNAL(timeout()),this,SLOT(handleHidePluginPanel()));

}

void PluginableWidget::setGeometryPlugin()
{
    switch (_plaginPanelPlace) {
    case PluginInPlace::verticalLeft:
        _pluginPanel->setGeometry(-_pluginPanel->width()+2,(this->height()-_pluginPanel->height())/2,_pluginPanel->width(),_pluginPanel->height());
        break;
    case PluginInPlace::verticalRight:
        _pluginPanel->setGeometry(this->width()-2,(this->height()-_pluginPanel->height())/2,_pluginPanel->width(),_pluginPanel->height());
        break;
    case PluginInPlace::horizontalTop:
        _pluginPanel->setGeometry((this->width()-_pluginPanel->width())/2,-_pluginPanel->height()+2,_pluginPanel->width(),_pluginPanel->height());
        break;
    case PluginInPlace::horizontalBottom:
        _pluginPanel->setGeometry((this->width()-_pluginPanel->width())/2,this->height()-2,_pluginPanel->width(),_pluginPanel->height());
        break;
    default:
        break;
    }
    _pluginPanel->raise();

}

void PluginableWidget::handleShowPluginPanel()
{

    _pluginPanelAnimationPropertyShow->setDuration(400);
    _pluginPanelAnimationPropertyShow->setStartValue(_pluginPanel->pos());
    int _x,_y;
    switch (_plaginPanelPlace) {
    case PluginInPlace::verticalLeft:
        _x=0;
        _y=((this->height()-_pluginPanel->height())/2);
        break;
    case PluginInPlace::verticalRight:

        _x=this->width()-_pluginPanel->width();
        _y=(this->height()-_pluginPanel->height())/2;
        break;
    case PluginInPlace::horizontalTop:
        _x=(this->width()-_pluginPanel->width())/2;
        _y=0;
        break;
    case PluginInPlace::horizontalBottom:
        _x=(this->width()-_pluginPanel->width())/2;
        _y=this->height()-_pluginPanel->height();
        break;
    default:
        break;
    }
    _pluginPanelAnimationPropertyShow->setEndValue(QPoint(_x,_y));
    _pluginPanelAnimationPropertyShow->start();
    _pluginPanel->raise();
    QPalette _palette(_pluginPanel->palette());
    _palette.setColor(QPalette::Window,Qt::transparent);
    _pluginPanel->setPalette(_palette);

}

void PluginableWidget::handleHidePluginPanel()
{


    _pluginPanelAnimationPropertyHide->setDuration(400);
    if(_pluginPanel->pos()==QPoint(0,0)){
        setGeometryPlugin();

    }
    _pluginPanelAnimationPropertyHide->setStartValue(_pluginPanel->pos());
    int _x,_y;
    switch (_plaginPanelPlace) {
    case PluginInPlace::verticalLeft:
        _x=(-_pluginPanel->width()+2);
        _y=(this->height()-_pluginPanel->height())/2;
        break;
    case PluginInPlace::verticalRight:
        _x=this->width()-2;
        _y=(this->height()-_pluginPanel->height())/2;
        break;
    case PluginInPlace::horizontalTop:

        _x=(this->width()-_pluginPanel->width())/2;
        _y=-_pluginPanel->height()+2;
        break;
    case PluginInPlace::horizontalBottom:
        _x=(this->width()-_pluginPanel->width())/2;
        _y=this->height()-2;
        break;
    default:
        break;
    }
    _pluginPanelAnimationPropertyHide->setEndValue(QPoint(_x,_y));
    _pluginPanelAnimationPropertyHide->start();
    connect(_pluginPanelAnimationPropertyHide,SIGNAL(finished()),this,SLOT(handleChangePluginColor()));
    _pluginPanel->raise();


}

void PluginableWidget::handleChangePluginColor()
{
    QPalette _palette(_pluginPanel->palette());
    _palette.setColor(QPalette::Window,_pluginPanelColor);
    _pluginPanel->setPalette(_palette);

}

void PluginableWidget::resizeEvent(QResizeEvent *event)
{
    handleHidePluginPanel();
}
}
