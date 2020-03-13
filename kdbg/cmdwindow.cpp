/*
 * Copyright Johannes Sixt
 * This file is licensed under the GNU General Public License Version 2.
 * See the file COPYING in the toplevel directory of the source directory.
 */

#include "cmdwindow.h"
#include <klocalizedstring.h>           /* i18n */

CommandWindow::CommandWindow(QWidget* parent) :
        QWidget(parent),
        m_cmdEdit(this),
        m_cmdExec(i18n(" Execute "), this),
        m_outputDisplay(this),
        m_layoutV(this),
        m_layoutH()
{
    // setup the layout
    m_cmdExec.setMinimumSize(m_cmdExec.sizeHint());
    m_layoutV.setMargin(0);
    m_layoutV.setSpacing(0);
    m_layoutH.setMargin(0);
    m_layoutH.setSpacing(0);
    m_layoutV.addLayout(&m_layoutH);
    m_layoutV.addWidget(&m_outputDisplay);

    m_layoutH.addWidget(&m_cmdEdit);
    m_layoutH.addWidget(&m_cmdExec);

    connect(&m_cmdExec, SIGNAL(clicked()), SIGNAL(execCommand()));
}

CommandWindow::~CommandWindow()
{
}

void CommandWindow::addText(const QString& text)
{
    m_outputDisplay.appendPlainText("\n"+ text);
}

#include "cmdwindow.moc"
