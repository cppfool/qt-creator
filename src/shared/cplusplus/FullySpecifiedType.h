/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2011 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** No Commercial Usage
**
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
**
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**************************************************************************/
// Copyright (c) 2008 Roberto Raggi <roberto.raggi@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef CPLUSPLUS_FULLYSPECIFIEDTYPE_H
#define CPLUSPLUS_FULLYSPECIFIEDTYPE_H

#include "CPlusPlusForwardDeclarations.h"


namespace CPlusPlus {

class CPLUSPLUS_EXPORT FullySpecifiedType
{
public:
    FullySpecifiedType(Type *type = 0);
    ~FullySpecifiedType();

    bool isValid() const;
    operator bool() const;

    Type *type() const;
    void setType(Type *type);

    FullySpecifiedType qualifiedType() const;

    bool isConst() const;
    void setConst(bool isConst);

    bool isVolatile() const;
    void setVolatile(bool isVolatile);

    bool isSigned() const;
    void setSigned(bool isSigned);

    bool isUnsigned() const;
    void setUnsigned(bool isUnsigned);

    bool isFriend() const;
    void setFriend(bool isFriend);

    bool isAuto() const;
    void setAuto(bool isAuto);

    bool isRegister() const;
    void setRegister(bool isRegister);

    bool isStatic() const;
    void setStatic(bool isStatic);

    bool isExtern() const;
    void setExtern(bool isExtern);

    bool isMutable() const;
    void setMutable(bool isMutable);

    bool isTypedef() const;
    void setTypedef(bool isTypedef);

    bool isInline() const;
    void setInline(bool isInline);

    bool isVirtual() const;
    void setVirtual(bool isVirtual);

    bool isExplicit() const;
    void setExplicit(bool isExplicit);

    bool isDeprecated() const;
    void setDeprecated(bool isDeprecated);

    bool isUnavailable() const;
    void setUnavailable(bool isUnavailable);

    bool isEqualTo(const FullySpecifiedType &other) const;

    Type &operator*();
    const Type &operator*() const;

    Type *operator->();
    const Type *operator->() const;

    bool operator == (const FullySpecifiedType &other) const;
    bool operator != (const FullySpecifiedType &other) const;
    bool operator < (const FullySpecifiedType &other) const;

    bool match(const FullySpecifiedType &otherTy, TypeMatcher *matcher) const;

    FullySpecifiedType simplified() const;

    void copySpecifiers(const FullySpecifiedType &type);

    unsigned flags() const;
    void setFlags(unsigned flags);

private:
    Type *_type;
    struct Flags {
        // cv qualifiers
        unsigned _isConst: 1;
        unsigned _isVolatile: 1;

        // sign
        unsigned _isSigned: 1;
        unsigned _isUnsigned: 1;

        // storage class specifiers
        unsigned _isFriend: 1;
        unsigned _isAuto: 1;
        unsigned _isRegister: 1;
        unsigned _isStatic: 1;
        unsigned _isExtern: 1;
        unsigned _isMutable: 1;
        unsigned _isTypedef: 1;

        // function specifiers
        unsigned _isInline: 1;
        unsigned _isVirtual: 1;
        unsigned _isExplicit: 1;

        // speficiers from attributes
        unsigned _isDeprecated: 1;
        unsigned _isUnavailable: 1;
    };
    union {
        unsigned _flags;
        Flags f;
    };
};

} // namespace CPlusPlus


#endif // CPLUSPLUS_FULLYSPECIFIEDTYPE_H
