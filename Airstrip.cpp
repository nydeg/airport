#include "Airstrip.h"
#include<math.h>

Airstrip::Airstrip()
{
	start = { 0,0 };
	end = { 0,0 };
	length = 0;
}

Airstrip::Airstrip(pair<int, int> st, pair<int, int> ed)
{
	start = st;
	end = ed;
	length = sqrt((st.first - ed.first) * (st.first - ed.first) + (st.second - ed.second) * (st.second - ed.second));
	status = "free";
	cout << "airstrip was created with parameters\n";
}
