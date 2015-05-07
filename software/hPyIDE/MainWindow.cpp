#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "SettingsDialog.h"

#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	
	m_state = NotConnected;
	
	m_statusLabel = new QLabel();
	m_statusLabel->setText("Not connected");
	statusBar()->addWidget(m_statusLabel);
	
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start(50);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::update()
{
	if (m_state == Connected)
	{
		char d[100];
		int r = m_ftdi.readAny(d, 100);
		if (r)
		{
			QString txt = QString::fromAscii(d, r);
			m_log += txt.replace("\r", "");
			ui->tbConsole->setPlainText(m_log);
			qDebug() << txt;
		}
	}
}

void MainWindow::on_bRun_clicked()
{

}

void MainWindow::on_actionConnect_triggered()
{
}
void MainWindow::on_actionDisconnect_triggered()
{

}
void MainWindow::on_actionSettings_triggered()
{
	SettingsDialog sd;
	if (sd.exec() == QDialog::Accepted)
	{
		/*qDebug() << "opening" << sd.speed;
		if (m_ftdi.open(sd.speed))
		{
			qDebug() << "opened";
			m_statusLabel->setText("Connected");
			m_state = Connected;
		}
		else
		{
			m_statusLabel->setText("Connection failed");
			m_state = NotConnected;
		}*/
	}
}
