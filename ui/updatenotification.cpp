#include "updatenotification.h"

#include <QNetworkAccessManager>
#include <QStatusBar>

#include "mainwindow.h"

UpdateNotification hitvidio::update_notifier;

UpdateNotification::UpdateNotification()
{

}

void UpdateNotification::check()
{
#if defined(GITHASH) && defined(UPDATEMSG)
  QNetworkAccessManager* manager = new QNetworkAccessManager();

  connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(finished_slot(QNetworkReply *)));
  connect(manager, SIGNAL(finished(QNetworkReply *)), manager, SLOT(deleteLater()));

  QString update_url = QString("http://hitvid.io/update.php?version=0&hash=%1");

  QNetworkRequest request(QUrl(update_url.arg(GITHASH)));
  manager->get(request);
#endif
}

void UpdateNotification::finished_slot(QNetworkReply *reply)
{
  QString response = QString::fromUtf8(reply->readAll());

  if (response == "1") {
    hitvidio::MainWindow->statusBar()->showMessage(tr("An update is available from the Hitvidio website. "
                                                   "Visit www.hitvid.io to download it."));
  }
}