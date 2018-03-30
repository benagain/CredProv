#pragma once

#define	LB_ERROR		-1				// Error condition

typedef struct elementheader
{
	unsigned char tag;			// Items tag
	int headerSize;
	unsigned char header[ 8 ];		//	Tag+length data 
	unsigned char id;							//	Tag class + primitive/constructed
	unsigned int length;				//	Data length
} BERHEADER;

class CBerFunctions
{
public:
	CBerFunctions(void){};
	~CBerFunctions(void){};
	static BERHEADER* read_header( char* pdata);
	static unsigned long peek_tag(char * pdata, unsigned long *puLen);
	static unsigned char peek_class(char* pData);
	static unsigned char *skip_tag( char* pData );
};
