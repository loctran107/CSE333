#ifndef _INTPAIR_H_
#define _INTPAIR_H_

class IntPair {

	public:
		//Constructor
		IntPair(const int x, const int y) : x_(x), y_(y) { };
		
		//accessor
		void Get(int* const x, int* const y);

		//mutator
		void Set(const int x, const int y);
	
	private:
		int x_, y_;


};


#endif // _INTPAIR_H

