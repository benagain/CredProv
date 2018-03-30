#pragma once

// You can hide these messages by defining HIDE_PRAGMA_MESSAGES
#if !defined(NDEBUG) && !defined(HIDE_PRAGMA_MESSAGES)

#define PRAGMA_MESSAGE_MAKE_STRING_HASH(x) #x
#define PRAGMA_MESSAGE_MAKE_STRING(x) PRAGMA_MESSAGE_MAKE_STRING_HASH(x)
#define PRAGMA_MESSAGE_LINE PRAGMA_MESSAGE_MAKE_STRING(__LINE__)

#define PRAGMA_MESSAGE_BUILDER(typ, _msg) message(__FILE__ "(" PRAGMA_MESSAGE_LINE ") : " typ ": " _msg)

#define TODO(_msg) message(__FILE__ "(" PRAGMA_MESSAGE_LINE ") : to do: " _msg)
#define TO_TEST(_msg) PRAGMA_MESSAGE_BUILDER("to test", _msg)
#define TODO_TEST(_msg) TO_TEST(_msg)

#else

#define TODO(x)
#define BUG(x)
#define MESSAGE(x)

#endif
