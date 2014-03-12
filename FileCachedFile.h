//========================================================================
//
// FileCachedFile.h
//
// This file is licensed under the GPLv2 or later
//
// Copyright 2010 Hib Eris <hib@hiberis.nl>
// Copyright 2010 Albert Astals Cid <aacid@kde.org>
//
//========================================================================

#ifndef FILECACHELOADER_H
#define FILECACHELOADER_H

#include "CachedFile.h"

class FileCacheLoader : public CachedFileLoader {

public:

  size_t init(GooString *dummy, CachedFile* cachedFile);
  int load(const std::vector<ByteRange> &ranges, CachedFileWriter *writer);

};

#endif

