#ifndef USLOGGER_H
#define USLOGGER_H

/*
 * 一个基于Log4qt的文件logger类
*/

#include "logger.h"
#include "basicconfigurator.h"
#include "propertyconfigurator.h"
#include "patternlayout.h"
#include "fileappender.h"
#include "logmanager.h"
#include <iostream>

#include <QTextCodec>
#include <QTime>

/// a logging macro to logging into both console and log4qt log file
#define USLOG(t) { qDebug(t); std::cout << t; }

class UsLogger
{
public:
    QString LOG_PATH = "log/";

    UsLogger();
    ~UsLogger()
    {
        log->deleteLater();
    }

    static UsLogger& getSingleton()
    {
        static UsLogger m_Instance;
        return m_Instance;
    }

    void init(void)
    {
        log = Log4Qt::Logger::rootLogger();
        Log4Qt::LogManager::setHandleQtMessages(true); ///<使用Log4Qt输出qDebug日志

        Log4Qt::PatternLayout *lay = new Log4Qt::PatternLayout(Log4Qt::PatternLayout::TTCC_CONVERSION_PATTERN);
        lay->setConversionPattern("%-d{yyyy-MM-dd HH:mm:ss} [%c]-[%p] %m%n");
        lay->activateOptions();

        fileappender = new Log4Qt::FileAppender(lay, QString(LOG_PATH) + "/LOG_UNIVERAL_"+QDateTime::currentDateTime().toString("yyyyMMddhhmmss")+ ".log");
        fileappender->setAppendFile(true);
        fileappender->activateOptions();

        //fileappender->setEncoding(QTextCodec::codecForName("UTF-8"):)
        log->addAppender(fileappender);

        //log->deleteLater();
    }

private:
    Log4Qt::Logger *log;
    Log4Qt::FileAppender *fileappender;
};

#endif // USLOGGER_H
