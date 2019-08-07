#include <iostream>
#include <string>
#include <cassert>

#include "Date.h"
#include "ZodiacReader.h"

using namespace std;

int main()
{
	// test code
	Date jan1(1, 1);
	ZodiacReader reader(jan1);
	assert(reader.stringifySign(reader.checkSign()) == "Capricorn");
	assert(reader.checkSign() == ZodiacReader::CAPRICORN);
	assert(!reader.onCusp());

	Date jan20(1, 20);
	ZodiacReader reader1(jan20);
	assert(reader1.stringifySign(reader1.checkSign()) == "Aquarius");
	assert(reader1.checkSign() == ZodiacReader::AQUARIUS);
	assert(reader1.onCusp());
	assert(reader1.stringifySign(reader1.cuspSign()) == "Capricorn");
	assert(reader1.cuspSign() == ZodiacReader::CAPRICORN);
	Date jan21(1, 21);
	ZodiacReader reader2(jan21);
	assert(reader2.stringifySign(reader2.checkSign()) == "Aquarius");
	assert(reader2.checkSign() == ZodiacReader::AQUARIUS);
	assert(reader2.onCusp());
	assert(reader2.stringifySign(reader2.cuspSign()) == "Capricorn");
	assert(reader2.cuspSign() == ZodiacReader::CAPRICORN);
	Date jan19(1, 19);
	ZodiacReader reader3(jan19);
	assert(reader3.stringifySign(reader3.checkSign()) == "Capricorn");
	assert(reader3.checkSign() == ZodiacReader::CAPRICORN);
	assert(reader3.onCusp());
	assert(reader3.stringifySign(reader3.cuspSign()) == "Aquarius");
	assert(reader3.cuspSign() == ZodiacReader::AQUARIUS);
	Date feb18(2, 18);
	ZodiacReader reader4(feb18);
	assert(reader4.stringifySign(reader4.checkSign()) == "Aquarius");
	assert(reader4.checkSign() == ZodiacReader::AQUARIUS);
	assert(reader4.onCusp());
	assert(reader4.stringifySign(reader4.cuspSign()) == "Pisces");
	assert(reader4.cuspSign() == ZodiacReader::PISCES);
	Date feb17(2, 17);
	ZodiacReader reader5(feb17);
	assert(reader5.stringifySign(reader5.checkSign()) == "Aquarius");
	assert(reader5.checkSign() == ZodiacReader::AQUARIUS);
	assert(reader5.onCusp());
	assert(reader5.stringifySign(reader5.cuspSign()) == "Pisces");
	assert(reader5.cuspSign() == ZodiacReader::PISCES);
	Date feb19(2, 19);
	ZodiacReader reader6(feb19);
	assert(reader6.stringifySign(reader6.checkSign()) == "Pisces");
	assert(reader6.checkSign() == ZodiacReader::PISCES);
	assert(reader6.onCusp());
	assert(reader6.stringifySign(reader6.cuspSign()) == "Aquarius");
	assert(reader6.cuspSign() == ZodiacReader::AQUARIUS);

	cout << "all tests passed!" << endl;

	return 0;

}