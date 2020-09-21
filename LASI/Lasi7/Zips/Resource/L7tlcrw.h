
//***********************************
//l7tlcrw.h
//read/write TLC to/from memory
//use with utilities not main program
//***********************************

//#define CDATA_WRITE

//global define
FILE *rTLCfile,*wTLCfile;


void TlcRighteousBox(void);

//righteous box
void TlcRighteousBox(void)
{

	if(TLCb.l>TLCb.r)
		lswap(&TLCb.l,&TLCb.r);

	if(TLCb.b>TLCb.t)
		lswap(&TLCb.b,&TLCb.t);
}

int WriteOldTlc=0;

#if !defined READ_TLC_ONLY	//basic read code only
#if !defined WRITE_TLC_ONLY //basic write code only

int AlimFlag,BlimFlag,PlimFlag,VlimFlag;

int ReadH(void);

#if defined MULTI_LEVEL_C
int ReadC(int);
#else
int ReadC(void);
#endif

int ReadB(void);
int ReadP(void);
int ReadT(void);

void WriteB(void);
void WriteP(void);
void WriteT(void);

#if defined MULTI_LEVEL_C
void WriteC(int);
#else
void WriteC(void);
#endif

#if defined MULTI_LEVEL_A
int TlcMakeC(int);
#else
int TlcMakeC(void);
#endif

int TlcMakeB(void);
int TlcMakeP(void);
int TlcMakeT(void);
int TlcBLim(void);
int TlcPLim(void);
int TlcVLim(void);
int TlcALim(void);


//read BPV records from TLC to memory 
//base Bbn,Pbn,Vbn set before call

int TlcReadBPV(char *name)
{
	int err=0;
	static char buf[2*NAMBUF+5];
	static char tlcinbuf[TLCBUF];

	if(name==NULL || !strlen(name)) 
		return 1;

	errno=0;
	nB=nP=nV=0;
	freeBPV();

	sprintf(buf,"%s.TLC",name);
	if((rTLCfile=fopen(buf,"rt"))==NULL)	//no file 
		return 1;

	while(!feof(rTLCfile)){
		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
        if(feof(rTLCfile))   //eof/abrt check
            break;
		if(!strcmp(strclip(tlcinbuf,0),"=B")||!strcmp(strclip(tlcinbuf,0),"<B>")){
			if(ReadB()){
				if(!BlimFlag)
					TlcMakeB();
			}
			else{
				MessageBoxPause(hWinProc,"Box Record Read Error",ERRTTL,MB_OK);
				err=1;
			}
			continue;
		}
		if(!strcmp(strclip(tlcinbuf,0),"=P")||!strcmp(strclip(tlcinbuf,0),"<P>")){
			if(ReadP()){
				if(!PlimFlag && !VlimFlag)
					TlcMakeP();
			}
			else{
				MessageBoxPause(hWinProc,"Path Record Read Error",ERRTTL,MB_OK);
				err=1;
			}
			continue;
		}
		if(!strcmp(strclip(tlcinbuf,0),"=T")||!strcmp(strclip(tlcinbuf,0),"<T>")){
			if(ReadT()){

#if defined (LL_OPTION)	//LL
				continue;
#endif
#if defined (DRC_OPTION)	//DRC
				continue;
#endif
#if defined (CKT_OPTION)
				if(TLCt.lyr==NodeLyr || TLCt.lyr==ConLyr || TLCt.lyr==DevLyr || TLCt.lyr==ParamLyr)	//CKT						 
#endif
					if(!PlimFlag && !VlimFlag)
						TlcMakeT();
			}
			else{
				MessageBoxPause(hWinProc,"Text Record Read Error",ERRTTL,MB_OK);
				err=1;
			}
		}
	}

	closefile(rTLCfile);
	return (err || errno);
}


#if defined MULTI_LEVEL_A
#if defined MULTI_LEVEL_C

int TlcReadC(char *name, int level)
{

	int i,err=0;
	static char buf[NAMBUF+5];
	static char tlcinbuf[TLCBUF];

	if(name==NULL || !strlen(name)) 
		return 1;

	if(level>NRANK-1) 
		return 1;	//rank load limit

	errno=0;
	nA[level]=0;

	for(i=level;i<NRANK;i++){	//free same and all above
		freeCEL(i);
	}

	sprintf(buf,"%s.TLC",name);
	if((rTLCfile=fopen(buf,"rt"))==NULL)
		return 1;

	while(!feof(rTLCfile)){
		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
        if(feof(rTLCfile))   //eof/abrt check
            break;

		if(!strcmp(strclip(tlcinbuf,0),"=C")||!strcmp(strclip(tlcinbuf,0),"<C>")){
			if(ReadC(level)){
				if(!AlimFlag)
					TlcMakeC(level);
			}
			else
				MessageBoxPause(hWinProc,"Cell Record Read Error",ERRTTL,MB_OK);
		}
	}

	closefile(rTLCfile);

	return (err || errno);	//return any error
}

#endif
#endif

#if defined MULTI_LEVEL_A
#if !defined MULTI_LEVEL_C

//read C records from TLC to memory A level single C level
int TlcReadC(char *name, int level)
{

	int i,err=0;
	static char buf[NAMBUF+5];
	static char tlcinbuf[TLCBUF];

	if(name==NULL || !strlen(name)) 
		return 1;

	if(level>NRANK-1) 
		return 1;

	sprintf(buf,"%s.TLC",name);
	if((rTLCfile=fopen(buf,"rt"))==NULL)
		return 1;

	errno=0;
	nA[level]=0;

	for(i=level;i<NRANK;i++){	//free same and all above
		freeCEL(i);
	}

	while(!feof(rTLCfile)){
		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
        if(feof(rTLCfile))   //eof/abrt check
            break;

		if(!strcmp(strclip(tlcinbuf,0),"=C")||!strcmp(strclip(tlcinbuf,0),"<C>")){
			if(ReadC()){
				if(!AlimFlag)
					TlcMakeC(level);
			}
			else
				MessageBoxPause(hWinProc,"Cell Record Read Error",ERRTTL,MB_OK);
		}
	}

	closefile(rTLCfile);

	return (err || errno);
}
#endif
#endif

#if !defined MULTI_LEVEL_A
#if !defined MULTI_LEVEL_C

//read C records from TLC to memory single A level multi C level
int TlcReadC(char *name)
{
	int err=0;
	static char buf[NAMBUF+5];
	static char tlcinbuf[TLCBUF];

	if(name==NULL || !strlen(name)) 
		return 1;

	sprintf(buf,"%s.TLC",name);
	if((rTLCfile=fopen(buf,"rt"))==NULL)	//no file
		return 1;

	errno=0;
	nA=0;
	freeCEL();

	while(!feof(rTLCfile)){
		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
        if(feof(rTLCfile))   //eof/abrt check
            break;

		if(!strcmp(strclip(tlcinbuf,0),"=C")||!strcmp(strclip(tlcinbuf,0),"<C>")){
			if(ReadC()){
				if(!AlimFlag)
					TlcMakeC();
			}
			else
				MessageBoxPause(hWinProc,"Cell Record Read Error",ERRTTL,MB_OK);
		}
	}

	closefile(rTLCfile);

	return (err || errno);	//return any error
}
#endif
#endif


#if defined MULTI_LEVEL_A
#if defined MULTI_LEVEL_C

int TlcMakeC(int level)
{
	int h;

	if(!TlcALim())	{
		nA[level]++;
		h=CNHB(GetCinfo(TLCc[level].name))| ORHB(TLCc[level].o) | OTHB(TLCc[level].r);
		putA(h,level,0,nA[level]);
		putA(TLCc[level].x,level,1,nA[level]);
		putA(TLCc[level].y,level,2,nA[level]);
		return 1;
	}
	return 0;
}
#endif
#endif

#if defined MULTI_LEVEL_A
#if !defined MULTI_LEVEL_C

int TlcMakeC(int level)	//A level
{
	int h;

	if(!TlcALim())	{
		nA[level]++;
		h=CNHB(GetCinfo(TLCc.name))| ORHB(TLCc.o) | OTHB(TLCc.r);
		putA(h,level,0,nA[level]);
		putA(TLCc.x,level,1,nA[level]);
		putA(TLCc.y,level,2,nA[level]);
		return 1;
	}
	return 0;
}
#endif
#endif

#if !defined MULTI_LEVEL_A
#if !defined MULTI_LEVEL_C

int TlcMakeC(void)	//no levels
{
	int h;

	if(!TlcALim())	{
		nA++;
		h=CNHB(GetCinfo(TLCc.name))| ORHB(TLCc.o) | OTHB(TLCc.r);
		putA(h,0,nA);
		putA(TLCc.x,1,nA);
		putA(TLCc.y,2,nA);
		return 1;
	}
	return 0;
}
#endif
#endif

#if defined CKT_OPTION
int TlcMakeB(void)
{
	if(!TlcBLim())	{	//at least one more box
		nB++;
		putB(TLCb.lyr,0,nB);
		putB(TLCb.l,1,nB);
		putB(TLCb.b,2,nB);
		putB(TLCb.r,3,nB);
		putB(TLCb.t,4,nB);
		putB(0,5,nB);		//null node
		return 1;
	}
	return 0;
}

//make path and vertex internal, return 1 of OK
int TlcMakeP(void)
{
	long i;

	if(!TlcPLim())	{	//at least one more path space
		nP++;

		putP(TLCp.lyr,0,nP);
		putP(TLCp.w,1,nP);
		putP(0,3,nP);		//null node
		if(!TlcVLim())	{	//at least one more vtx space
			putP(nV+1,2,nP);
			for(i=0;i<TLCp.nv;i++){	//make vertex loop
				if(!TlcVLim()){
					nV++;
					putV(nP,0,nV);
					putV(TLCp.x[i],1,nV);
					putV(TLCp.y[i],2,nV);
					putV(nV+1,3,nV);
				}
			}
			putV(0,3,nV);		//terminate vtx
			if(i==TLCp.nv)
				return 1;		//success
			else
				return 0;		//ran out of vtx space
		}
		else{
			putP(0,2,nP);		//null path
			return 0;
		}
	}
	return 0;
}


#else

int TlcMakeB(void)
{
	if(!TlcBLim())	{	//at least one more box
		nB++;
		putB(TLCb.lyr,0,nB);
		putB(TLCb.l,1,nB);
		putB(TLCb.b,2,nB);
		putB(TLCb.r,3,nB);
		putB(TLCb.t,4,nB);
		return 1;
	}
	return 0;
}

//make path and vertex internal, return 1 of OK
int TlcMakeP(void)
{
	long i;

	if(!TlcPLim())	{	//at least one more path space
		nP++;

		putP(TLCp.lyr,0,nP);
		putP(TLCp.w,1,nP);
		if(!TlcVLim())	{			//at least one more vtx space
			putP(nV+1,2,nP);		//new start vtx number
			for(i=0;i<TLCp.nv;i++){	//make vertex loop
				if(!TlcVLim()){
					nV++;
					putV(nP,0,nV);
					putV(TLCp.x[i],1,nV);
					putV(TLCp.y[i],2,nV);
					putV(nV+1,3,nV);
				}
			}
			putV(0,3,nV);		//terminate vtx
			if(i==TLCp.nv)
				return 1;		//success
			else
				return 0;		//ran out of vtx space
		}
		else{
			putP(0,2,nP);		//null path
			return 0;
		}
	}
	return 0;
}
#endif


//maketext	internal, return 1 if OK
int TlcMakeT(void)
{
	int i;
	static char txtbuf[TLCBUF];

	if(!TlcPLim())	{	//at least one more path space
		nP++;
		putP(TLCt.lyr | ORHB(TLCt.o) | TXHB,0,nP);
		putP(TLCt.size,1,nP);
		if(!TlcVLim()){			//at least one more vtx space
			nV++;
			putP(nV,2,nP);		//text record
			putV(nP,0,nV);
			putV(TLCt.x,1,nV);
			putV(TLCt.y,2,nV);
			putV(nV+1,3,nV);

			for(i=0;i<TLCLEN;i++)	//zero string
				txtbuf[i]=0;

			strcpy(txtbuf,TLCt.text);
			i=0;
			while(i<(int)strlen(txtbuf)){
				if(!TlcVLim()){
					putV(nV+1,3,nV);
					nV++;
					putV(nP | TXHB,0,nV);
					putV(txtbuf[i]<<24 | txtbuf[i+1]<<16 | txtbuf[i+2]<<8 | txtbuf[i+3],1,nV);
					putV(txtbuf[i+4]<<24 | txtbuf[i+5]<<16 | txtbuf[i+6]<<8 | txtbuf[i+7],2,nV);
					i+=8;
				}
				else break;
			}
			putV(0,3,nV);		//last vtx pointer
			return 1;			//success
		}
		else{
			putP(0,2,nP);		//null path
			return 0;
		}
	}
	return 0;
}


//limiters
int TlcBLim(void)
{
	if(nB>=BMAX){
		MessageBoxPause(hWinProc,"TLC Boxes Exceed Limit ... Load Aborted",WRNTTL,MB_OK);
		BlimFlag=1;
		return 1;
	}
	else
		return 0;
}

int TlcPLim(void)
{
	if(nP>=PMAX){
		MessageBoxPause(hWinProc,"TLC Paths Exceed Limit ... Load Aborted",WRNTTL,MB_OK);
		PlimFlag=1;
		return 1;
	}
	else return 0;
}

int TlcVLim(void)
{
	if(nV>=VMAX){
		MessageBoxPause(hWinProc,"TLC Vertices Exceed Limit ... Load Aborted",WRNTTL,MB_OK);
		VlimFlag=1;
		return 1;
	}
	else return 0;
}

int TlcALim(void)
{
#if defined MULTI_LEVEL_A
	if(nA[0]>=AMAX){
#else
	if(nA>=AMAX){
#endif
		MessageBoxPause(hWinProc,"TLC Cells Exceed Limit ... Load Aborted",WRNTTL,MB_OK);
		AlimFlag=1;
		return 1;
	}
	else return 0;

}

//duplicate read code
int ReadH(void)
{
	char *s;
	static char tlcinbuf[TLCBUF];

	if(!feof(rTLCfile)){
		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		strcpy(TLCh.name,_strupr(strclip(tlcinbuf,NAMLEN)));
		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		strcpy(TLCh.lv,strclip(tlcinbuf,LVLEN));

		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		strcpy(TLCh.tv,strclip(tlcinbuf,TVLEN));

		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		TLCh.scale=atof(tlcinbuf);

		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		strcpy(TLCh.punit,strclip(tlcinbuf,PULEN));

		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		strcpy(TLCh.date,strclip(tlcinbuf,8));

		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		strcpy(TLCh.time,strclip(tlcinbuf,8));

		fGetLine(tlcinbuf,TLCLEN,rTLCfile);	//outline

		if((s=strtok(tlcinbuf," "))==NULL) return 0;
		TLCh.rank=atoi(s);

		if((s=strtok(NULL," "))==NULL) return 0;
		TLCh.l=atol(s);
		if((s=strtok(NULL," "))==NULL) return 0;
		TLCh.b=atol(s);
		if((s=strtok(NULL," "))==NULL) return 0;
		TLCh.r=atol(s);
		if((s=strtok(NULL," "))==NULL) return 0;
		TLCh.t=atol(s);

		fGetLine(tlcinbuf,TLCLEN,rTLCfile);	//counts
		if((s=strtok(tlcinbuf," "))==NULL) return 0;
		TLCh.nb=atoi(s);
		if((s=strtok(NULL," "))==NULL) return 0;
		TLCh.np=atoi(s);
		if((s=strtok(NULL," "))==NULL) return 0;
		TLCh.nv=atol(s);
		if((s=strtok(NULL," "))==NULL) return 0;
		TLCh.nc=atoi(s);
		return 1;
	}
	return 0;
}

#if defined MULTI_LEVEL_C
//read a cell record at level
int ReadC(int level)
{
	char *s;
	static char tlcinbuf[TLCBUF];

	if(!feof(rTLCfile)){
		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		strcpy(TLCc[level].name,_strupr(strclip(tlcinbuf,NAMLEN)));

		strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TLCLEN);

		if((s=strtok(tlcinbuf," "))==NULL)
			return 0;
		TLCc[level].o=atoi(s) & 0x07;

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCc[level].x=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCc[level].y=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCc[level].r=atoi(s);

		return 1;
	}
	return 0;
}
#else
//read a cell record no level
int ReadC(void)
{
	char *s;
	static char tlcinbuf[TLCBUF];

	if(!feof(rTLCfile)){
		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		strcpy(TLCc.name,_strupr(strclip(tlcinbuf,NAMLEN)));

		strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TLCLEN);

		if((s=strtok(tlcinbuf," "))==NULL)
			return 0;
		TLCc.o=atoi(s) & 0x07;

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCc.x=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCc.y=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCc.r=atoi(s);
		return 1;
	}
	return 0;
}
#endif

//read a box record
int ReadB(void)
{
	char *s;
	static char tlcinbuf[TLCBUF];

	if(!feof(rTLCfile)){
		strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TLCLEN);

		if((s=strtok(tlcinbuf," "))==NULL)
			return 0;
		TLCb.lyr=atoi(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCb.l=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCb.b=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCb.r=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCb.t=atol(s);

		TlcRighteousBox();	//fix order
		return 1;
	}
	return 0;
}

//read a path record
int ReadP(void)
{
	char *s;
	int nv=0,p=0;
	static char tlcinbuf[TLCBUF];

	if(!feof(rTLCfile)){
		strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TLCLEN);

		if((s=strtok(tlcinbuf," "))==NULL)
			return 0;
		TLCp.lyr=atoi(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCp.w=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		nv=TLCp.nv=atoi(s);

		strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TLCLEN);

		if((s=strtok(tlcinbuf," "))==NULL) return 0;
		TLCp.x[p]=atol(s);				//1st X

		if((s=strtok(NULL," "))==NULL) return 0;
		TLCp.y[p]=atol(s);				//1st Y
		p++;
		nv--;
		while(nv>0){
			if((s=strtok(NULL," "))==NULL){	//end of line read new line
				strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TLCLEN);

				if((s=strtok(tlcinbuf," "))==NULL) return 0;
			}
			TLCp.x[p]=atol(s);	//next X

			if((s=strtok(NULL," "))==NULL) return 0;
			TLCp.y[p]=atol(s);	//next Y
			p++;
			nv--;
		}
		return 1;
	}
	return 0;
}

//read a text record
int ReadT(void)
{
	char *s;
	static char tlcinbuf[TLCBUF];

	if(!feof(rTLCfile)){
		strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TLCLEN);

		if((s=strtok(tlcinbuf," "))==NULL)
			return 0;
		TLCt.lyr=atoi(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCt.size=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCt.nv=atoi(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCt.o=atoi(s);

		//coords
		strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TLCLEN);

		if((s=strtok(tlcinbuf," "))==NULL)
			return 0;
		TLCt.x=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCt.y=atol(s);

		//text string
		strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TXTLEN+16);
		strcpy(TLCt.text,getCDATAtext(tlcinbuf));
		
		return 1;
	}
	return 0;
}


#if defined MULTI_LEVEL_C
void WriteC(int level)
{
	if(!WriteOldTlc)
		fprintf(wTLCfile,"<C>\n");
	else
		fprintf(wTLCfile,"=C\n");

	fprintf(wTLCfile,"%s\n",TLCc[level].name);
	fprintf(wTLCfile,"%d %ld %ld %d\n",TLCc[level].o,TLCc[level].x,TLCc[level].y,0);

	if(!WriteOldTlc)
		fprintf(wTLCfile,"</C>\n");
}
#else
void WriteC(void)
{
	if(!WriteOldTlc)
		fprintf(wTLCfile,"<C>\n");
	else
		fprintf(wTLCfile,"=C\n");

	fprintf(wTLCfile,"%s\n",TLCc.name);
	fprintf(wTLCfile,"%d %ld %ld %d\n",TLCc.o,TLCc.x,TLCc.y,0);

	if(!WriteOldTlc)
		fprintf(wTLCfile,"</C>\n");
}
#endif

//write a box record
void WriteB(void)
{
	if(!WriteOldTlc)
		fprintf(wTLCfile,"<B>\n");
	else
		fprintf(wTLCfile,"=B\n");

	TlcRighteousBox();	//fix order
	fprintf(wTLCfile,"%d %ld %ld %ld %ld\n",TLCb.lyr,TLCb.l,TLCb.b,TLCb.r,TLCb.t);

	if(!WriteOldTlc)
		fprintf(wTLCfile,"</B>\n");
}

//write a path record
void WriteP(void)
{
	long n=0;	//coords start at 0 element

	if(!WriteOldTlc)
		fprintf(wTLCfile,"<P>\n");
	else
		fprintf(wTLCfile,"=P\n");


	fprintf(wTLCfile,"%d %ld %ld\n",TLCp.lyr,TLCp.w,TLCp.nv);

	while(n<TLCp.nv){
		fprintf(wTLCfile,"%ld %ld ",TLCp.x[n],TLCp.y[n]);
		n++;
		if(!(n % 5)){
			fprintf(wTLCfile,"\n");
		}
	}
	if((n % 5)){
		fprintf(wTLCfile,"\n");
	}

	if(!WriteOldTlc)
		fprintf(wTLCfile,"</P>\n");
}

//write a text record
void WriteT(void)
{
	if(!WriteOldTlc)
		fprintf(wTLCfile,"<T>\n");
	else
		fprintf(wTLCfile,"=T\n");

	fprintf(wTLCfile,"%d %ld %ld %d\n",TLCt.lyr,TLCt.size,TLCt.nv,TLCt.o);
	fprintf(wTLCfile,"%ld %ld\n",TLCt.x,TLCt.y);

	if(!WriteOldTlc){

#if defined CDATA_WRITE
		fprintf(wTLCfile,"<![CDATA[%s]]>\n",TLCt.text);
#else
		fprintf(wTLCfile,"%s\n",TLCt.text);
#endif

		fprintf(wTLCfile,"</T>\n");
	}
	else
		fprintf(wTLCfile,"%s\n",TLCt.text);
}


#endif //end of #if !defined WRITE_TLC_ONLY
#endif //end of #if !defined READ_TLC_ONLY


/////////////////////////
//write TLC records only
/////////////////////////

#if defined WRITE_TLC_ONLY

void WriteB(void);
void WriteP(void);
void WriteT(void);

#if defined MULTI_LEVEL_C
void WriteC(int);
#else
void WriteC(void);
#endif

#if defined MULTI_LEVEL_C
void WriteC(int level)
{
	if(!WriteOldTlc)
		fprintf(wTLCfile,"<C>\n");
	else
		fprintf(wTLCfile,"=C\n");

	fprintf(wTLCfile,"%s\n",TLCc[level].name);
	fprintf(wTLCfile,"%d %ld %ld %d\n",TLCc[level].o,TLCc[level].x,TLCc[level].y,0);
}
#else
void WriteC(void)
{
	if(!WriteOldTlc)
		fprintf(wTLCfile,"<C>\n");
	else
		fprintf(wTLCfile,"=C\n");

	fprintf(wTLCfile,"%s\n",TLCc.name);
	fprintf(wTLCfile,"%d %ld %ld %d\n",TLCc.o,TLCc.x,TLCc.y,0);

	if(!WriteOldTlc)
		fprintf(wTLCfile,"</C>\n");
}
#endif

//write a box record
void WriteB(void)
{
	if(!WriteOldTlc)
		fprintf(wTLCfile,"<B>\n");
	else
		fprintf(wTLCfile,"=B\n");

	fprintf(wTLCfile,"%d %ld %ld %ld %ld\n",TLCb.lyr,TLCb.l,TLCb.b,TLCb.r,TLCb.t);

	if(!WriteOldTlc)
		fprintf(wTLCfile,"</B>\n");
}

//write a path record
void WriteP(void)
{
	long n=0;	//coords start at 0 element

	if(!WriteOldTlc)
		fprintf(wTLCfile,"<P>\n");
	else
		fprintf(wTLCfile,"=P\n");

	fprintf(wTLCfile,"%d %ld %ld\n",TLCp.lyr,TLCp.w,TLCp.nv);

	while(n<TLCp.nv){
		fprintf(wTLCfile,"%ld %ld ",TLCp.x[n],TLCp.y[n]);
		n++;
		if(!(n % 5)){
			fprintf(wTLCfile,"\n");
		}
	}
	if((n % 5)){
		fprintf(wTLCfile,"\n");
	}

	if(!WriteOldTlc)
		fprintf(wTLCfile,"</P>\n");
}

//write a text record
void WriteT(void)
{
	if(!WriteOldTlc)
		fprintf(wTLCfile,"<T>\n");
	else
		fprintf(wTLCfile,"=T\n");

	fprintf(wTLCfile,"%d %ld %ld %d\n",TLCt.lyr,TLCt.size,TLCt.nv,TLCt.o);
	fprintf(wTLCfile,"%ld %ld\n",TLCt.x,TLCt.y);
	fprintf(wTLCfile,"%s\n",TLCt.text);

	if(!WriteOldTlc){

#if defined CDATA_WRITE
		fprintf(wTLCfile,"<![CDATA[%s]]>\n",TLCt.text);
#else
		fprintf(wTLCfile,"%s\n",TLCt.text);
#endif

		fprintf(wTLCfile,"</T>\n");
	}
	else
		fprintf(wTLCfile,"%s\n",TLCt.text);}

#endif //end of #if defined WRITE_TLC_ONLY


/////////////////////////
//read TLC records only
/////////////////////////

#if defined READ_TLC_ONLY

int ReadH(void);

#if defined MULTI_LEVEL_C
int ReadC(int);
#else
int ReadC(void);
#endif

int ReadB(void);
int ReadP(void);
int ReadT(void);

int ReadH(void)
{
	char *s;
	static char tlcinbuf[TLCBUF];

	if(!feof(rTLCfile)){
		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		strcpy(TLCh.name,_strupr(strclip(tlcinbuf,NAMLEN)));
		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		strcpy(TLCh.lv,strclip(tlcinbuf,LVLEN));

		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		strcpy(TLCh.tv,strclip(tlcinbuf,TVLEN));

		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		TLCh.scale=atof(tlcinbuf);

		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		strcpy(TLCh.punit,strclip(tlcinbuf,PULEN));

		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		strcpy(TLCh.date,strclip(tlcinbuf,8));

		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		strcpy(TLCh.time,strclip(tlcinbuf,8));

		fGetLine(tlcinbuf,TLCLEN,rTLCfile);	//outline

		if((s=strtok(tlcinbuf," "))==NULL) return 0;
		TLCh.rank=atoi(s);

		if((s=strtok(NULL," "))==NULL) return 0;
		TLCh.l=atol(s);
		if((s=strtok(NULL," "))==NULL) return 0;
		TLCh.b=atol(s);
		if((s=strtok(NULL," "))==NULL) return 0;
		TLCh.r=atol(s);
		if((s=strtok(NULL," "))==NULL) return 0;
		TLCh.t=atol(s);

		fGetLine(tlcinbuf,TLCLEN,rTLCfile);	//counts
		if((s=strtok(tlcinbuf," "))==NULL) return 0;
		TLCh.nb=atoi(s);
		if((s=strtok(NULL," "))==NULL) return 0;
		TLCh.np=atoi(s);
		if((s=strtok(NULL," "))==NULL) return 0;
		TLCh.nv=atol(s);
		if((s=strtok(NULL," "))==NULL) return 0;
		TLCh.nc=atoi(s);
		return 1;
	}
	return 0;
}

#if defined MULTI_LEVEL_C
//read a cell record at level
int ReadC(int level)
{
	char *s;
	static char tlcinbuf[TLCBUF];

	if(!feof(rTLCfile)){
		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		strcpy(TLCc[level].name,_strupr(strclip(tlcinbuf,NAMLEN)));

		strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TLCLEN);

		if((s=strtok(tlcinbuf," "))==NULL)
			return 0;
		TLCc[level].o=atoi(s) & 0x07;

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCc[level].x=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCc[level].y=atol(s);
		return 1;
	}
	return 0;
}
#else
//read a cell record no level
int ReadC(void)
{
	char *s;
	static char tlcinbuf[TLCBUF];

	if(!feof(rTLCfile)){
		fGetLine(tlcinbuf,TLCLEN,rTLCfile);
		strcpy(TLCc.name,_strupr(strclip(tlcinbuf,NAMLEN)));

		strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TLCLEN);

		if((s=strtok(tlcinbuf," "))==NULL)
			return 0;
		TLCc.o=atoi(s) & 0x07;

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCc.x=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCc.y=atol(s);
		return 1;
	}
	return 0;
}
#endif

//read a box record
int ReadB(void)
{
	char *s;
	static char tlcinbuf[TLCBUF];

	if(!feof(rTLCfile)){
		strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TLCLEN);

		if((s=strtok(tlcinbuf," "))==NULL)
			return 0;
		TLCb.lyr=atoi(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCb.l=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCb.b=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCb.r=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCb.t=atol(s);

		TlcRighteousBox();	//fix order
		return 1;
	}
	return 0;
}

//read a path record
int ReadP(void)
{
	char *s;
	int nv=0,p=0;
	static char tlcinbuf[TLCBUF];

	if(!feof(rTLCfile)){
		strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TLCLEN);

		if((s=strtok(tlcinbuf," "))==NULL)
			return 0;
		TLCp.lyr=atoi(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCp.w=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		nv=TLCp.nv=atoi(s);

		strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TLCLEN);

		if((s=strtok(tlcinbuf," "))==NULL) return 0;
		TLCp.x[p]=atol(s);				//1st X

		if((s=strtok(NULL," "))==NULL) return 0;
		TLCp.y[p]=atol(s);				//1st Y
		p++;
		nv--;
		while(nv>0){
			if((s=strtok(NULL," "))==NULL){	//end of line read new line
				strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TLCLEN);

				if((s=strtok(tlcinbuf," "))==NULL) return 0;
			}
			TLCp.x[p]=atol(s);	//next X

			if((s=strtok(NULL," "))==NULL) return 0;
			TLCp.y[p]=atol(s);	//next Y
			p++;
			nv--;
		}
		return 1;
	}
	return 0;
}

//read a text record
int ReadT(void)
{
	char *s;
	static char tlcinbuf[TLCBUF];

	if(!feof(rTLCfile)){
		strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TLCLEN);

		if((s=strtok(tlcinbuf," "))==NULL)
			return 0;
		TLCt.lyr=atoi(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCt.size=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCt.nv=atoi(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCt.o=atoi(s);

		//coords
		strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TLCLEN);

		if((s=strtok(tlcinbuf," "))==NULL)
			return 0;
		TLCt.x=atol(s);

		if((s=strtok(NULL," "))==NULL)
			return 0;
		TLCt.y=atol(s);

		//text string
		strclip(fGetLine(tlcinbuf,TLCLEN,rTLCfile),TXTLEN+16);
		strcpy(TLCt.text,getCDATAtext(tlcinbuf));		
		
		return 1;
	}
	return 0;
}
#endif //end of #if defined READ_TLC_ONLY

