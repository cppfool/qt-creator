/**************************************************************************
**
** Copyright (C) 2015 Lorenz Haas
** Contact: http://www.qt.io/licensing
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company.  For licensing terms and
** conditions see http://www.qt.io/terms-conditions.  For further information
** use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file.  Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, The Qt Company gives you certain additional
** rights.  These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#ifndef BEAUTIFIER_UNCRUSTIFYOPTIONSPAGE_H
#define BEAUTIFIER_UNCRUSTIFYOPTIONSPAGE_H

#include <coreplugin/dialogs/ioptionspage.h>

#include <QPointer>
#include <QWidget>

namespace Beautifier {
namespace Internal {
namespace Uncrustify {

class UncrustifySettings;

namespace Ui { class UncrustifyOptionsPage; }

class UncrustifyOptionsPageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UncrustifyOptionsPageWidget(UncrustifySettings *settings, QWidget *parent = 0);
    virtual ~UncrustifyOptionsPageWidget();
    void restore();
    void apply();

private:
    Ui::UncrustifyOptionsPage *ui;
    UncrustifySettings *m_settings;
};

class UncrustifyOptionsPage : public Core::IOptionsPage
{
    Q_OBJECT

public:
    explicit UncrustifyOptionsPage(UncrustifySettings *settings, QObject *parent = 0);
    QWidget *widget() Q_DECL_OVERRIDE;
    void apply() Q_DECL_OVERRIDE;
    void finish() Q_DECL_OVERRIDE;

private:
    QPointer<UncrustifyOptionsPageWidget> m_widget;
    UncrustifySettings *m_settings;
};

} // namespace Uncrustify
} // namespace Internal
} // namespace Beautifier


#endif // BEAUTIFIER_UNCRUSTIFYOPTIONSPAGE_H
