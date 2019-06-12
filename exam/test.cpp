#include "MED.h"

int main()
{
	MB1 med;
	std::ifstream in("input_items.bin", std::ios::binary);
	med.GetMeds(in);
	med.SortUp();
	std::ofstream out("out.txt");
	med.PutMeds(out);

	return 0;
}