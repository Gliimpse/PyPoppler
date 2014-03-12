//========================================================================
//
// FilePDFDocBuilder.h
//
// This file is licensed under the GPLv2 or later
//
// Copyright 2010 Hib Eris <hib@hiberis.nl>
// Copyright 2010 Albert Astals Cid <aacid@kde.org>
//
//========================================================================

#ifndef FILEPDFDOCBUILDER_H
#define FILEPDFDOCBUILDER_H

#include "PDFDocBuilder.h"

//-------------------------------------------------------------------------------
// FilePDFDocBuilder
//
// The FilePDFDocBuilder implements a PDFDocBuilder that read from a file handle.
//-------------------------------------------------------------------------------

class FilePDFDocBuilder : public PDFDocBuilder {

public:

  PDFDoc *buildPDFDoc(const GooString &uri, GooString *ownerPassword = NULL,
    GooString *userPassword = NULL, void *guiDataA = NULL);
  GBool supports(const GooString &uri);

};

#endif /* FILEPDFDOCBUILDER_H */
