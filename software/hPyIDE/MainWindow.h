#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

#include "FTDI.h"

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	enum EState { NotConnected, Connected };

	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	
	void closeEvent(QCloseEvent *event);

private slots:
	void on_actionConnect_triggered();

	void on_bRun_clicked();

	void update();

	void on_actionSettings_triggered();

	void on_actionDisconnect_triggered();

	void sendDataToFTDI(QByteArray& data);

private:
	Ui::MainWindow *ui;

	QLabel *m_statusLabel;

	FTDI m_ftdi;
	EState m_state;
	QString m_log;

	bool isConnected() const { return m_state == Connected; }
};

#endif // MAINWINDOW_H
