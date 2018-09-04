#pragma once
// band edge definitions

typedef int FREQ;
enum SIDEBAND  {USB = 0, LSB = 1};

class BandInfo
{
public:
   BandInfo() : _name("ALL"), _lowerEdge(0), _upperEdge(0), _sideband(LSB) {}

   BandInfo(
	  QString name,
	  FREQ low,
	  FREQ high,
	  FREQ defaultCW,
	  FREQ defaultSSB,
	  FREQ defaultRTTY,
	  SIDEBAND sb)
	  :  _name				(name),
		 _lowerEdge			(low),
		 _upperEdge			(high),
		 _defaultFreqCW		(defaultCW),
		 _defaultFreqSSB	(defaultSSB),
		 _defaultFreqRTTY	(defaultRTTY),
		 _sideband			(sb)
   {}

   virtual ~BandInfo() {}

   BandInfo(BandInfo const & b)
	  :  _name				( b._name			),
		 _lowerEdge			( b._lowerEdge		),
		 _upperEdge			( b._upperEdge		),
		 _defaultFreqCW		( b._defaultFreqCW	),
		 _defaultFreqSSB	( b._defaultFreqSSB	),
		 _defaultFreqRTTY	( b._defaultFreqRTTY),
		 _sideband			( b._sideband		)
   {}

   BandInfo & operator=(BandInfo const & b)
   {
	  _name				= b._name;
	  _lowerEdge		= b._lowerEdge;
	  _upperEdge		= b._upperEdge;
	  _defaultFreqCW	= b._defaultFreqCW;
	  _defaultFreqSSB	= b._defaultFreqSSB;
	  _defaultFreqRTTY  = b._defaultFreqRTTY;
	  _sideband			= b._sideband;
	  return *this;
   }

   FREQ        LowerEdge()            const { return _lowerEdge;      }
   void        LowerEdge(FREQ f)            { _lowerEdge = f;         }
   FREQ        UpperEdge()            const { return _upperEdge;      }
   void        UpperEdge(FREQ f)            {   _upperEdge = f;       }
   FREQ        DefaultFreqCW()        const { return _defaultFreqCW;  }
   void        DefaultFreqCW(FREQ f)        { _defaultFreqCW = f;     }
   FREQ        DefaultFreqSSB()       const { return _defaultFreqSSB; }
   void        DefaultFreqSSB(FREQ f)       { _defaultFreqSSB = f;    }
   FREQ        DefaultFreqRTTY()      const { return _defaultFreqRTTY;}
   void        DefaultFreqRTTY(FREQ f)      { _defaultFreqRTTY = f;   }
   SIDEBAND    Sideband()             const { return _sideband;       }
   void        Sideband(SIDEBAND sb)        { _sideband = sb;         }
   QString     Name()                 const { return _name;           }
   void        Name(char const * name)      { _name = name;           }

private:
   QString     _name;
   FREQ        _lowerEdge;
   FREQ        _upperEdge;
   FREQ        _defaultFreqCW;
   FREQ        _defaultFreqSSB;
   FREQ        _defaultFreqRTTY;
   SIDEBAND    _sideband;
};
extern BandInfo  B160  ;
extern BandInfo  B80   ;
extern BandInfo  B40   ;
extern BandInfo  B30   ;
extern BandInfo  B20   ;
extern BandInfo  B17   ;
extern BandInfo  B15   ;
extern BandInfo  B12   ;
extern BandInfo  B10   ;
extern BandInfo  B6    ;
extern BandInfo  B2    ;
extern BandInfo  B222  ;
extern BandInfo  B432  ;
extern BandInfo  B903  ;
extern BandInfo  B1296 ;
extern BandInfo  B2304 ;
extern BandInfo  B3456 ;
extern BandInfo  B5760 ;
extern BandInfo  B10G  ;
extern BandInfo  B24G  ;
extern BandInfo  B47G  ;
extern BandInfo  B75G  ;
extern BandInfo  B119G ;
extern BandInfo  B142G ;
extern BandInfo  B241G ;
extern BandInfo  BLight;
extern BandInfo  BSat;
extern BandInfo  BNone;
