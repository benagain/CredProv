#pragma once

namespace myid
{

// base 64 conversions not using DataExchange
VectorOfBytePtr fromBase64(const std::string& b64);

std::string toBase64String(VectorOfByte const & bin);
std::wstring toBase64Wstr(VectorOfByte const & bin);

}
