#ifndef POS_H
#define POS_H
//------------------------------

namespace Kha{
	typedef struct _Pos{
		int row;
		int col;
		_Pos(int r, int c): row(r), col(c){}
	} Pos;
}

//------------------------------
#endif
