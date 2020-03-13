/*
 * Copyright Johannes Sixt
 * This file is licensed under the GNU General Public License Version 2.
 * See the file COPYING in the toplevel directory of the source directory.
 */

#ifndef CMDWINDOW_H
#define CMDWINDOW_H

#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPlainTextEdit>

class CommandWindow : public QWidget
{
    Q_OBJECT
public:
    CommandWindow(QWidget* parent);
    ~CommandWindow();

    QString commandText() const { return m_cmdEdit.text(); }
    void addText(const QString& text);

protected:

    QLineEdit m_cmdEdit;
    QPushButton m_cmdExec;
    QPlainTextEdit m_outputDisplay;

    QVBoxLayout m_layoutV;
    QHBoxLayout m_layoutH;

signals:
    void execCommand();
};

#endif // CMDWINDOW_H
