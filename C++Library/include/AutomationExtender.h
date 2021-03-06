/*AutomationExtender.h */
//================================================================================
// BOOST SOFTWARE LICENSE
//
// Copyright 2020 BitWise Laboratories Inc.
// Author.......Jim Waschura
// Contact......info@bitwiselabs.com
//
//Permission is hereby granted, free of charge, to any person or organization
//obtaining a copy of the software and accompanying documentation covered by
//this license (the "Software") to use, reproduce, display, distribute,
//execute, and transmit the Software, and to prepare derivative works of the
//Software, and to permit third-parties to whom the Software is furnished to
//do so, all subject to the following:
//
//The copyright notices in the Software and this entire statement, including
//the above license grant, this restriction and the following disclaimer,
//must be included in all copies of the Software, in whole or in part, and
//all derivative works of the Software, unless such copies or derivative
//works are solely in the form of machine-executable object code generated by
//a source language processor.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
//SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
//FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
//ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//DEALINGS IN THE SOFTWARE.
//================================================================================

#ifndef BITWISE_AUTOMATION_EXTENDER
#define  BITWISE_AUTOMATION_EXTENDER

#include <string.h> /* strlen */

#include "AutomationInterface.h"

class AutomationExtender :
	public AutomationInterface
{
protected:
	AutomationExtender( AutomationInterface *device, const char *prefix ) :
		m_Debugging(false),
		m_Extender(device),
		m_Prefix(prefix) {}
	virtual ~AutomationExtender() {}

public:
	virtual bool getDebugging();
	virtual void setDebugging(bool newValue);

protected:
	/* Provide AutomationInterface methods */

	virtual void SendCommand( const char *command, ... );
	virtual char * QueryResponse( char *buffer, int buflen, const char *command, ... );
	virtual void SendBinaryCommand( const char *buffer, int count, const char *command, ... );
	virtual char *QueryBinaryResponse( int *pcount, const char *command, ... ); /* caller responsible for free(return_value) */
	virtual int QueryResponse_int( const char *command, ... );
	virtual long long QueryResponse_int64( const char *command, ... );
	virtual bool QueryResponse_bool( const char *command, ... );
	virtual double QueryResponse_double( const char *command, ... );
	virtual int QueryResponse_enum( const char *enum_strings_null_terminated[], const char *command, ... );
	/* end */

private:
	AutomationInterface *getExtender() { return m_Extender; }
	const char *getPrefix() { return m_Prefix; }
	int getPrefixLength() { return strlen(m_Prefix); }

private:
	bool m_Debugging;
	AutomationInterface *m_Extender;
	const char *m_Prefix;
};


#endif // BITWISE_AUTOMATION_EXTENDER

