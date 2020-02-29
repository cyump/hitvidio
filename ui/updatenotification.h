#ifndef UPDATENOTIFICATION_H
#define UPDATENOTIFICATION_H

#include <QNetworkReply>

class UpdateNotification : public QObject {
  Q_OBJECT
public:
  UpdateNotification();
  void check();
private slots:
  void finished_slot(QNetworkReply*);
};

namespace hitvidio {
  extern UpdateNotification update_notifier;
}

#endif // UPDATENOTIFICATION_H