#include "stdafx.h"
#include "VscPipe.h"

namespace Pipe
{
cmd::cmd()
	: command(Cmd::EXIT)
{}

cmd::cmd(Cmd rhs)
	: command(rhs)
{}

void cmd::set(_In_z_ LPCWSTR data, _Out_writes_bytes_(size) LPWSTR where, _In_ size_t size)
{
	if (data != nullptr)
	{
		wcscpy_s(where, size / sizeof(WCHAR), data);
	}
	else
	{
		where[0] = 0;
	}
}

void cmd::set(_In_ const std::wstring& data, _Out_writes_bytes_(size) LPWSTR where, _In_ size_t size)
{
	size_t chars = size / sizeof(WCHAR);
	data._Copy_s(where, size, chars - 1);
	if (data.size() >= chars)
		where[chars - 1] = 0;
	else
		where[data.size()] = 0;
}

cmdExit::cmdExit()
	: cmd(Cmd::EXIT)
{}

cmdIPT::cmdIPT()
	: cmd(Cmd::IPTSTART)
{}

cmdGen::cmdGen()
	: cmd(Cmd::GENKEY)
{}

cmdDelete::cmdDelete()
	: cmd(Cmd::DELKEY)
{}

cmdKey::cmdKey()
	: cmd(Cmd::PUBKEY)
{}

cmdSign::cmdSign()
	: cmd(Cmd::SIGN)
{}

cmdDecrypt::cmdDecrypt()
	: cmd(Cmd::DECRYPT)
{}

resp::resp()
{}

void resp::clear()
{
	status = Process::Status::SUCCESS;
	response = ERROR_SUCCESS;
	memset(error, 0, sizeof(error));
}

respIPT::respIPT()
{}

void respIPT::clear()
{
	resp::clear();
	processId = 0;
	threadId = 0;
}

respData::respData()
{}

void respData::clear()
{
	resp::clear();
	len = 0;
	memset(data, 0, sizeof(data));
}

} // namespace Pipe
