#pragma once

std::wstring& operator<<(std::wstring& lhs, int rhs)
{
	std::wstringstream s;
	s << rhs;
	return lhs += s.str();
}

std::wstring& operator<<(std::wstring& lhs, long rhs)
{
	std::wstringstream s;
	s << rhs;
	return lhs += s.str();
}

std::wstring& operator<<(std::wstring& lhs, unsigned long rhs)
{
	std::wstringstream s;
	s << rhs;
	return lhs += s.str();
}

std::string& operator<<(std::string& lhs, int rhs)
{
	std::stringstream s;
	s << rhs;
	return lhs += s.str();
}

std::string& operator<<(std::string& lhs, long rhs)
{
	std::stringstream s;
	s << rhs;
	return lhs += s.str();
}

std::string& operator<<(std::string& lhs, unsigned long rhs)
{
	std::stringstream s;
	s << rhs;
	return lhs += s.str();
}

