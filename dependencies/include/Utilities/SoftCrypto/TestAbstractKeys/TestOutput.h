#pragma once

#include "TestDefinitions.h"
#include "Arguments.h"

void SaveOutput(TListTest const & listPassedTests, TListFailedTest const & listFailedTests, TListFailedTest const &, Arguments& arguments, const long& threadID = -1, const long& iteration = -1);
void SaveOutput(Arguments& arguments);
void SaveOutput(const eXML::xmlwriter& xmlOutput,  Arguments& arguments, const std::wstring& filenameSuffix);

bool WasOutputSaved(void);