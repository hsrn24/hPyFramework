#include "SettingsDialog.h"
#include "ui_SettingsDialog.h"

#include <QDebug>
#include <QFile>
#include <QSettings>
#include <QMessageBox>

#ifdef Q_WS_WIN
#include <windows.h>
#include <setupapi.h>
#endif

QStringList getDevicesList();

SettingsDialog::SettingsDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SettingsDialog)
{
	ui->setupUi(this);
	
	/*ui->cbPort->clear();
	QStringList devices = getDevicesList();
	foreach(QString dev, devices)
	{
		ui->cbPort->addItem(dev);
	}*/

	int speed  = QSettings().value("port-speed", 230400).toInt();
	ui->cbSpeed->setEditText(QString::number(speed));
	int parity  = QSettings().value("port-parity", 0).toInt();
	ui->cbParity->setCurrentIndex(parity);
	int stop  = QSettings().value("port-stop", 0).toInt();
	ui->cbStopBits->setCurrentIndex(stop);
}

SettingsDialog::~SettingsDialog()
{
	delete ui;
}

QStringList getDevicesList()
{
	QStringList list;
#ifdef Q_WS_WIN
	BYTE* pbuf = 0;
	DWORD reqSize = 0;
	DWORD n = 0;
	HDEVINFO hDevInfo;
	
	static const GUID guid = { 0x4d36e978, 0xe325, 0x11ce, { 0xbf, 0xc1, 0x08, 0x00, 0x2b, 0xe1, 0x03, 0x18 } };
	char *str;
	
	SP_DEVINFO_DATA DeviceInfoData;
	
	DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	hDevInfo = SetupDiGetClassDevs(&guid, 0L, NULL, DIGCF_PRESENT);
	if (hDevInfo == INVALID_HANDLE_VALUE)
		return QStringList();
		
	for (;;)
	{
		if (!SetupDiEnumDeviceInfo(hDevInfo, n++, &DeviceInfoData))
		{
			SetupDiDestroyDeviceInfoList(hDevInfo);
			break;
		}
		reqSize = 0;
		SetupDiGetDeviceRegistryPropertyA(hDevInfo, &DeviceInfoData, SPDRP_FRIENDLYNAME, NULL, NULL, 0, &reqSize);
		pbuf = (BYTE*)malloc(reqSize > 1 ? reqSize : 1);
		if (!SetupDiGetDeviceRegistryPropertyA(hDevInfo, &DeviceInfoData, SPDRP_FRIENDLYNAME, NULL, pbuf, reqSize, NULL))
		{
			free(pbuf);
			continue;
		}
		str = (char*)pbuf;
		
		QString s(str);
		
		QStringList split_list = s.split("\n", QString::SkipEmptyParts);
		
		foreach (const QString &str, split_list)
		{
			if (str.contains(CONSTANTS::BLE_NAME))
			{
				list << str;
			}
		}
		
		free(pbuf);
	}
#else
	
	QStringList prefixes;
	prefixes << "USB" << "ACM" << "AMA";
	
	foreach (QString prefix, prefixes)
	{
		int i = 0;
		for (;;)
		{
			QString name = QString("/dev/tty%1%2").arg(prefix).arg(i);
			if (!QFile(name).exists())
				break;
			i++;
			list << name;
		}
	}
	
#endif
	return list;
}

void SettingsDialog::accept()
{
	bool ok;
	int speed = ui->cbSpeed->currentText().toInt(&ok);
	if(!ok)
	{
		QMessageBox::warning(this, "Port settings", "Invalid port speed");
		return;
	}
	QSettings().setValue("port-speed", speed);
	QSettings().setValue("port-parity", ui->cbParity->currentIndex());
	QSettings().setValue("port-stop", ui->cbStopBits->currentIndex());

	QDialog::accept();
}
