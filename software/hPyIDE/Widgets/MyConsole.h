#ifndef MYCONSOLE_H
#define MYCONSOLE_H

#include <QTextEdit>

class MyConsole : public QTextEdit
{
	Q_OBJECT
public:
	explicit MyConsole(QWidget* parent = 0);
	
	void keyPressEvent(QKeyEvent* event);

	void appendText(const QString& txt);

signals:
	void onDataGenerated(QByteArray& data);
	
public slots:

private:
	QString m_text;
};

#endif // MYCONSOLE_H
