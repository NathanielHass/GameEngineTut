//manually import function from other solution
namespace GE
{
	__declspec(dllimport) void Print();
}

void main()
{
	GE::Print();
}