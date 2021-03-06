/****************************<--CSLU-->************************************/
/*                                                                        */
/*             Center for Spoken Language Understanding                   */
/*               Division of Biomedical Computer Science                  */
/*               Oregon Health and Science University                     */
/*                         Portland, OR USA                               */
/*                        Copyright (c) 1999 - 2009                       */
/*                                                                        */
/*      This module is not part of the CSTR/University of Edinburgh       */
/*               release of the Festival TTS system.                      */
/*                                                                        */
/*  In addition to any conditions disclaimers below, please see the file  */
/*  "license_ohsu_tts.txt" distributed with this software for information */
/*  on usage and redistribution, and for a DISCLAIMER OF ALL WARRANTIES.  */
/*                                                                        */
/*      Authors: Mike Macon, Esther Klabbers, Alexander Kain              */
/*                          and David Brown                               */
/*                                                                        */
/****************************<--CSLU-->************************************/

#include "MSeqNam.h"

MetaSequenceNameEvent::MetaSequenceNameEvent()
{
}

MetaSequenceNameEvent::MetaSequenceNameEvent(unsigned long t, const char *str) :
    MetaTextEvent(t, str)
{
}

MetaSequenceNameEvent::MetaSequenceNameEvent(const MetaSequenceNameEvent &e) :
    MetaTextEvent(e)
{
}

MetaSequenceNameEvent::~MetaSequenceNameEvent()
{
}

MetaSequenceNameEvent &
MetaSequenceNameEvent::operator=(const MetaSequenceNameEvent &e)
{

	(MetaTextEvent)*this = (MetaTextEvent)e;
	return (*this);
}

string
MetaSequenceNameEvent::GetEventStr(void) const
{

	return (MetaTextEvent::GetEventStr());
}

ostream &
operator<<(ostream &os, const MetaSequenceNameEvent &e)
{
	const char *str = e.GetEventStr().c_str();
	os << str;
	delete str;
	return (os);
}
