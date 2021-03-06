#include "systemtray.h"
#include <QMenu>
#include <QSystemTrayIcon>

SystemTray::SystemTray(QObject *parent) : QObject(parent)
{
    QMenu *trayIconMenu = new QMenu();
    QAction *viewWindow = new QAction(tr("view"), this);
    QAction *quitAction = new QAction(tr("quit"), this);
    
    connect(viewWindow, &QAction::triggered, this, &SystemTray::signalShow);
    connect(quitAction, &QAction::triggered, this, &SystemTray::signalQuit);

    trayIconMenu->addAction(viewWindow);
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon();
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setIcon(QIcon(":/images/gdrive.png"));
    trayIcon->show();
    trayIcon->setToolTip("");

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

void SystemTray::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        emit signalIconActivated();
        break;
    default:
        break;
    }
}

void SystemTray::hideIconTray()
{
    trayIcon->hide();
}
