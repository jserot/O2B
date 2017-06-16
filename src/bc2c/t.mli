type value =
| Int         of int
| Int32       of Int32.t
| Int64       of Int64.t
| Nativeint   of Nativeint.t
| Float       of float
| Float_array of float array
| Bytes       of bytes
| Object      of value array
| Block       of int * value array
| Closure     of closure
| CodePtr     of code_ptr

and closure = {
  ofs  : int;
  ptrs : code_ptr array;
  env  : value array;
}

and code_ptr = int
and stack = value list
and globals = value array

type dword =
| INT     of int
| FLOAT   of int list
| CHARS   of char list
| BYTES   of int list
| CUSTOM  of string
| HEADER  of int * int
| POINTER of int
| CODEPTR of code_ptr

type cword =
| SBYTE of int
| UBYTE of int
| OPCODE of Opcode.t
