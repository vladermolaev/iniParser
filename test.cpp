#include "CppUnitTest.h"
#include "iniSectionParser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IniParser
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(TwoPairs)
		{
      const char buf[] = "a1=df\0a2=jjk\0";
      const int sz = sizeof(buf)/sizeof(buf[0]);
      int len = strlen(buf);
      std::vector<NameValuePair> values;
      ParseIniSection(buf, sz, values);
      Assert::AreEqual(2U, values.size());
      Assert::AreEqual("a1", values[0].first.c_str());
      Assert::AreEqual("df", values[0].second.c_str());
      Assert::AreEqual("a2", values[1].first.c_str());
      Assert::AreEqual("jjk", values[1].second.c_str());
    }
	};
}