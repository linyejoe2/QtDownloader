#include "ytdlp.h"

#include <QDebug>
#include <QProcess>
#include <QString>
#include <QStringList>

YtDlp::YtDlp() {}

void YtDlp::download(QString url) {
    QProcess process;

    // QString args = "";
    // args += QString("--format ") + QString("bestaudio/best") + QString(" ");
    // args += QString("--output ") + QString("%(title)s.%(ext)s");
    // args += url;

    QStringList args;
    args << "-f"
         << "best[height<=480]";
    args << url;
    qDebug() << args;

    process.start("yt-dlp", args);

    // qDebug() << process.

    if (!process.waitForStarted()) {
        qDebug() << "Error: Failed to start youtube-dl process";
        return;
    }

    if (!process.waitForFinished()) {
        qDebug() << "Error: youtube-dl process did not finish";
        return;
    }

    qDebug() << process.readAllStandardOutput();
}
