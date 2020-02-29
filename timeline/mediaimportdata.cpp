#include "mediaimportdata.h"

hitvidio::timeline::MediaImportData::MediaImportData(Media *media, hitvidio::timeline::MediaImportType import_type) :
  media_(media),
  import_type_(import_type)
{
}

Media *hitvidio::timeline::MediaImportData::media() const
{
  return media_;
}

hitvidio::timeline::MediaImportType hitvidio::timeline::MediaImportData::type() const
{
  return import_type_;
}