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

#ifndef METASEQSPEC_H
#define METASEQSPEC_H

#include "MEvent.h"

class MetaSequencerSpecificEvent : public MetaEvent {
	friend ostream &operator<<(ostream &os,
	    const MetaSequencerSpecificEvent &e);
public:
	MetaSequencerSpecificEvent();
	MetaSequencerSpecificEvent(unsigned long t, const unsigned char *data,
	    long length);
	MetaSequencerSpecificEvent(const MetaSequencerSpecificEvent &e);
	virtual ~MetaSequencerSpecificEvent();
	virtual Event *Dup(void) const
	    {return (new MetaSequencerSpecificEvent(*this));}

	virtual EventType GetType(void) const {return (METASEQUENCERSPECIFIC);}
	virtual char *GetTypeStr(void) const
	    {return ("MetaSequencerSpecificEvent");}
	virtual string GetEventStr(void) const;
	const unsigned char *GetData(void) const {
		if (GetWildcard(wc_data))
			return (WC_DATA);
		else
			return (data);
	}
	long GetLength(void) const {
		if (GetWildcard(wc_data))
			return (WC_LENGTH);
		else
			return (length);
	}

	void SetData(const unsigned char *data, long length);

	MetaSequencerSpecificEvent &operator=(
	    const MetaSequencerSpecificEvent &e);

	virtual const char *SMFRead(SMFTrack &t);
	virtual const char *SMFWrite(SMFTrack &t) const;

	static const unsigned char *WC_DATA;
	static const long WC_LENGTH;
protected:
	virtual int Equal(const Event *e) const;
private:
	static const  unsigned long wc_data;
	unsigned char *data;
	long length;
};
#endif
