#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "SettingsDialog.h"

#include <QDebug>
#include <QSettings>
#include <QTimer>
#include <QScrollBar>

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

	QPalette palette = ui->tbConsole->palette();
	palette.setColor(QPalette::Base,Qt::black);
	palette.setColor(QPalette::Text,Qt::white);
	ui->tbConsole->setPalette(palette);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	m_ftdi.close();
	QMainWindow::closeEvent(event);
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
			ui->tbConsole->setText(m_log);

			QScrollBar * sb = ui->tbConsole->verticalScrollBar();
				sb->setValue(sb->maximum());
		}
	}
}

void MainWindow::on_bRun_clicked()
{

}

void MainWindow::on_actionConnect_triggered()
{
	int speed = QSettings().value("port-speed", 230400).toInt();
	FTDI::EParity parity = (FTDI::EParity)QSettings().value("port-parity", 230400).toInt();
	FTDI::EStopBits stopbits = (FTDI::EStopBits)QSettings().value("port-stopbits", 230400).toInt();

	if (m_ftdi.open(speed, parity, stopbits))
	{
		m_statusLabel->setText(QString("Connected (%1)").arg(speed));
		m_state = Connected;
	}
	else
	{
		m_statusLabel->setText("Connection failed");
		m_state = NotConnected;
	}
}
void MainWindow::on_actionDisconnect_triggered()
{
	m_ftdi.close();
	m_statusLabel->setText("Disconnected");
	m_state = NotConnected;
}
void MainWindow::on_actionSettings_triggered()
{
	SettingsDialog sd;
	sd.exec();
}
