#include "appglobal.h"
#include <QFile>
#include <QtDebug>
#include <QFileInfo>

AppGlobal::AppGlobal(QObject *parent) : QObject(parent)
{

}

QString AppGlobal::readAll(QString path)
{
    QFile file(path);
    if(!file.exists()){
        qWarning()<<"File not exist!";
        return "";
    }
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        qWarning()<<"Cannot open the file!";
        return "";
    }
    auto content = file.readAll();
    return QString(content);
}

void AppGlobal::setDefaultStyleSheet(QQuickTextDocument *qd)
{
    auto td = qd->textDocument();
    td->setDefaultStyleSheet(readAll(":/default.css"));
}

void AppGlobal::setBaseUrl(QQuickTextDocument *qd, QUrl url)
{
    qd->textDocument()->setBaseUrl(url);
}

QString AppGlobal::fileSuffix(const QString &filePath)
{
    QFileInfo info(filePath);
    return info.suffix();
}

QString AppGlobal::fileDir(const QString &filePath)
{
    QFileInfo info(filePath);
    return info.absolutePath();
}
