#!/bin/sh

#############################################################################
#
#  Copyright (C) 2015 The Qt Company Ltd.
#  Contact: http://www.qt.io/licensing
#
#  This file is part of Qt Creator.
#
#  Commercial License Usage
#  Licensees holding valid commercial Qt licenses may use this file in
#  accordance with the commercial license agreement provided with the
#  Software or, alternatively, in accordance with the terms contained in
#  a written agreement between you and The Qt Company.  For licensing terms and
#  conditions see http://www.qt.io/terms-conditions.  For further information
#  use the contact form at http://www.qt.io/contact-us.
#
#  GNU Lesser General Public License Usage
#  Alternatively, this file may be used under the terms of the GNU Lesser
#  General Public License version 2.1 or version 3 as published by the Free Software
#  Foundation and appearing in the file LICENSE.LGPLv21 and LICENSE.LGPLv3 included in the
#  packaging of this file.  Please review the following information to
#  ensure the GNU Lesser General Public License requirements
#  will be met: https://www.gnu.org/licenses/lgpl.html and http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
#
#  In addition, as a special exception, The Qt Company gives you certain additional
#  rights.  These rights are described in The Qt Company LGPL Exception
#  version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
#
#############################################################################

# Internal utility script that synchronizes the Qt Designer private headers
# used by the Qt Designer plugin (located in the qt_private) directory
# with the Qt source tree pointed to by the environment variable QTDIR.

REQUIRED_HEADERS="pluginmanager_p.h iconloader_p.h qdesigner_formwindowmanager_p.h formwindowbase_p.h
abstractnewformwidget_p.h qtresourcemodel_p.h abstractoptionspage_p.h
shared_global_p.h abstractsettings_p.h qdesigner_integration_p.h qsimpleresource_p.h shared_enums_p.h"

echo Using $QTDIR

syncHeader()
{
  HDR=$1
  # Locate the Designer header: look in lib/shared or SDK
  QTHDR=$QTDIR/tools/designer/src/lib/shared/$HDR
  if [ ! -f $QTHDR ]
  then
    QTHDR=$QTDIR/tools/designer/src/lib/sdk/$HDR
  fi
  echo Syncing $QTHDR

  [ -f $QTHDR ] || { echo "$HDR does not exist" ; exit 1 ; }

  TARGET=qt_private/$HDR

  # Exchange license header
  head -n 28 formwindowfile.h > $TARGET || exit 1
  tail -n +41 $QTHDR >> $TARGET || exit 1
}

for H in $REQUIRED_HEADERS
do
  syncHeader $H
done
