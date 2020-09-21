
//*********************
//l7tlcrw.h
//TLC record structures
//*********************

struct tlchdr{
	char name[NAMBUF];
	char lv[LVLEN];
	char tv[TVLEN];
	double scale;
	char punit[PULEN];
	char date[10];
	char time[10];
    int rank;
	long l;
	long b;
	long r;
	long t;
	int nb;
	int np;
	int nv;
	int nc;
} TLCh={"",VERS,VERSX,1.,"um","","",1,0,0,0,0,0,0,0,0};

#if defined MULTI_LEVEL_C
struct tlccel{
	char name[NAMBUF];
	int o;
	long x;
	long y;
	int r;
} TLCc[NRANK+1];
#else
struct tlccel{
	char name[NAMBUF];
	int o;
	long x;
	long y;
	int r;
} TLCc;
#endif

struct tlcbox{
	int lyr;
	long l;
	long b;
	long r;
	long t;
} TLCb;

struct tlcpath{
	int lyr;
	long w;
	long nv;
	long x[PVSIZ];
	long y[PVSIZ];
} TLCp;

struct tlctext{
	int lyr;
	long size;
	long nv;
	int o;
	long x;
	long y;
	char text[TXTBUF];
} TLCt;

