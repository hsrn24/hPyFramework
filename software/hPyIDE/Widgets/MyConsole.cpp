#include "MyConsole.h"

#include <QDebug>
#include <QKeyEvent>
#include <QScrollBar>

MyConsole::MyConsole(QWidget* parent)
	: QTextEdit(parent)
{
	//setTextInteractionFlags();
	setCursorWidth(8);
}

void MyConsole::appendText(const QString& txt)
{
	for (int i = 0; i < txt.size(); i++)
	{
		QChar qc = txt.at(i);
		char c = qc.toAscii();
		qDebug() << "got" << (int)c;
		if (c == 8) // backspace
		{
			m_text.remove(m_text.size() - 1, 1);
		}
		else
		{
			m_text.append(qc);
		}
	}
	setText(m_text);
	
	QScrollBar * sb = verticalScrollBar();
	sb->setValue(sb->maximum());
	moveCursor(QTextCursor::End);
}

void MyConsole::keyPressEvent(QKeyEvent* event)
{
	int key = event->key();
	bool ctrl = event->modifiers() & Qt::CTRL;
	qDebug() << event->key() << ctrl << event->modifiers() << event->nativeScanCode() << event->text();
	QByteArray d;
	QString txt = event->text();
	
	if (key == 67 && ctrl) // CTRL-C
	{
		d.append(0x03);
	}
	
	if (key == 0x1000003) // backspace
	{
		d.append(0x7f);
	}
	
	if (d.size() == 0 && txt.size() > 0)
	{
		char c = event->text().at(0).toAscii();
		qDebug() << (int)c;
		d.append(c);
	}
	
	if (d.size() > 0)
		emit onDataGenerated(d);
}
