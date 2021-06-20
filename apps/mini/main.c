#define OCAML_STACK_WOSIZE                64
#define OCAML_STATIC_HEAP_WOSIZE           0
#define OCAML_DYNAMIC_HEAP_WOSIZE        256
#define OCAML_FLASH_HEAP_WOSIZE           48
#define OCAML_STACK_INITIAL_WOSIZE         0
#define OCAML_RAM_GLOBDATA_NUMBER         23
#define OCAML_FLASH_GLOBDATA_NUMBER        2
#define OCAML_BYTECODE_BSIZE             692
#define OCAML_PRIMITIVE_NUMBER            17
#define OCAML_VIRTUAL_ARCH                32
#define OCAML_STARTING_OOID                0
#define OCAML_NO_FLASH_HEAP                0
#define OCAML_NO_FLASH_GLOBALS             0

#define OCAML_GC_MARK_AND_COMPACT

#include </media/sf_SF2/ml/O2B/omicrob/include/vm/values.h>

#define OCAML_ACC0                        0
#define OCAML_ACC1                        1
#define OCAML_ACC2                        2
#define OCAML_PUSH                        3
#define OCAML_PUSHACC1                    4
#define OCAML_PUSHACC2                    5
#define OCAML_PUSHACC3                    6
#define OCAML_PUSHACC4                    7
#define OCAML_PUSHACC5                    8
#define OCAML_PUSHACC6                    9
#define OCAML_PUSHACC7                   10
#define OCAML_PUSHACC                    11
#define OCAML_POP                        12
#define OCAML_ASSIGN                     13
#define OCAML_ENVACC1                    14
#define OCAML_ENVACC2                    15
#define OCAML_ENVACC3                    16
#define OCAML_PUSHENVACC1                17
#define OCAML_PUSHENVACC3                18
#define OCAML_APPLY1                     19
#define OCAML_APPLY2                     20
#define OCAML_APPLY3                     21
#define OCAML_APPTERM1                   22
#define OCAML_APPTERM2                   23
#define OCAML_APPTERM3                   24
#define OCAML_RETURN                     25
#define OCAML_RESTART                    26
#define OCAML_GRAB                       27
#define OCAML_CLOSURE_1B                 28
#define OCAML_CLOSURE_2B                 29
#define OCAML_CLOSUREREC_1B              30
#define OCAML_PUSHOFFSETCLOSURE0         31
#define OCAML_GETRAMGLOBAL_1B            32
#define OCAML_GETFLASHGLOBAL_1B          33
#define OCAML_PUSHGETRAMGLOBAL_1B        34
#define OCAML_PUSHGETFLASHGLOBAL_1B      35
#define OCAML_SETRAMGLOBAL_1B            36
#define OCAML_MAKEBLOCK_1B               37
#define OCAML_MAKEBLOCK2                 38
#define OCAML_MAKEBLOCK3                 39
#define OCAML_GETFIELD0                  40
#define OCAML_GETFIELD1                  41
#define OCAML_GETFIELD2                  42
#define OCAML_GETFIELD3                  43
#define OCAML_GETFIELD                   44
#define OCAML_GETBYTESCHAR               45
#define OCAML_BRANCH_1B                  46
#define OCAML_BRANCH_2B                  47
#define OCAML_BRANCHIF_1B                48
#define OCAML_BRANCHIFNOT_1B             49
#define OCAML_RAISE                      50
#define OCAML_CHECK_SIGNALS              51
#define OCAML_C_CALL1                    52
#define OCAML_C_CALL2                    53
#define OCAML_C_CALL3                    54
#define OCAML_C_CALL4                    55
#define OCAML_C_CALL5                    56
#define OCAML_CONST0                     57
#define OCAML_CONST1                     58
#define OCAML_CONSTINT_1B                59
#define OCAML_PUSHCONST0                 60
#define OCAML_PUSHCONSTINT_1B            61
#define OCAML_ADDINT                     62
#define OCAML_SUBINT                     63
#define OCAML_MULINT                     64
#define OCAML_NEQ                        65
#define OCAML_LTINT                      66
#define OCAML_GTINT                      67
#define OCAML_OFFSETINT_1B               68
#define OCAML_BLTINT_1B                  69
#define OCAML_BGTINT_1B                  70
#define OCAML_STOP                       71

value ocaml_stack[OCAML_STACK_WOSIZE];
value ocaml_ram_heap[OCAML_STATIC_HEAP_WOSIZE + OCAML_DYNAMIC_HEAP_WOSIZE];
value ocaml_ram_global_data[OCAML_RAM_GLOBDATA_NUMBER];

PROGMEM value const ocaml_flash_heap[OCAML_FLASH_HEAP_WOSIZE] = {
  /*  0 */  Make_header(0, 0, Color_white),
  /*  1 */  Make_header(2, Object_tag, Color_white),
  /*  2 */  Val_flash_block(&ocaml_flash_heap[5]),
  /*  3 */  Val_int(-1),
  /*  4 */  Make_header(4, String_tag, Color_white),
  /*  5 */  Make_string_data('O', 'u', 't', '_'),
  /*  6 */  Make_string_data('o', 'f', '_', 'm'),
  /*  7 */  Make_string_data('e', 'm', 'o', 'r'),
  /*  8 */  Make_string_data('y', '\0', '\0', '\2'),
  /*  9 */  Make_header(2, Object_tag, Color_white),
  /* 10 */  Val_flash_block(&ocaml_flash_heap[13]),
  /* 11 */  Val_int(-3),
  /* 12 */  Make_header(2, String_tag, Color_white),
  /* 13 */  Make_string_data('F', 'a', 'i', 'l'),
  /* 14 */  Make_string_data('u', 'r', 'e', '\0'),
  /* 15 */  Make_header(2, Object_tag, Color_white),
  /* 16 */  Val_flash_block(&ocaml_flash_heap[19]),
  /* 17 */  Val_int(-4),
  /* 18 */  Make_header(5, String_tag, Color_white),
  /* 19 */  Make_string_data('I', 'n', 'v', 'a'),
  /* 20 */  Make_string_data('l', 'i', 'd', '_'),
  /* 21 */  Make_string_data('a', 'r', 'g', 'u'),
  /* 22 */  Make_string_data('m', 'e', 'n', 't'),
  /* 23 */  Make_string_data('\0', '\0', '\0', '\3'),
  /* 24 */  Make_header(2, Object_tag, Color_white),
  /* 25 */  Val_flash_block(&ocaml_flash_heap[28]),
  /* 26 */  Val_int(-6),
  /* 27 */  Make_header(5, String_tag, Color_white),
  /* 28 */  Make_string_data('D', 'i', 'v', 'i'),
  /* 29 */  Make_string_data('s', 'i', 'o', 'n'),
  /* 30 */  Make_string_data('_', 'b', 'y', '_'),
  /* 31 */  Make_string_data('z', 'e', 'r', 'o'),
  /* 32 */  Make_string_data('\0', '\0', '\0', '\3'),
  /* 33 */  Make_header(2, Object_tag, Color_white),
  /* 34 */  Val_flash_block(&ocaml_flash_heap[37]),
  /* 35 */  Val_int(-9),
  /* 36 */  Make_header(4, String_tag, Color_white),
  /* 37 */  Make_string_data('S', 't', 'a', 'c'),
  /* 38 */  Make_string_data('k', '_', 'o', 'v'),
  /* 39 */  Make_string_data('e', 'r', 'f', 'l'),
  /* 40 */  Make_string_data('o', 'w', '\0', '\1'),
  /* 41 */  Make_header(6, String_tag, Color_white),
  /* 42 */  Make_string_data('S', 't', 'r', 'i'),
  /* 43 */  Make_string_data('n', 'g', '.', 's'),
  /* 44 */  Make_string_data('u', 'b', ' ', '/'),
  /* 45 */  Make_string_data(' ', 'B', 'y', 't'),
  /* 46 */  Make_string_data('e', 's', '.', 's'),
  /* 47 */  Make_string_data('u', 'b', '\0', '\1')
};

PROGMEM value const ocaml_initial_static_heap[OCAML_STATIC_HEAP_WOSIZE] = {
};

PROGMEM value const ocaml_initial_stack[OCAML_STACK_INITIAL_WOSIZE] = {
};

PROGMEM value const ocaml_flash_global_data[OCAML_FLASH_GLOBDATA_NUMBER] = {
  /* 0 */  Val_flash_block(&ocaml_flash_heap[16]),
  /* 1 */  Val_flash_block(&ocaml_flash_heap[42])
};

value acc = Val_unit;
value env = Val_unit;

#define OCAML_Out_of_memory        Val_flash_block(&ocaml_flash_heap[2])
#define OCAML_Failure              Val_flash_block(&ocaml_flash_heap[10])
#define OCAML_Invalid_argument     Val_flash_block(&ocaml_flash_heap[16])
#define OCAML_Division_by_zero     Val_flash_block(&ocaml_flash_heap[25])
#define OCAML_Stack_overflow       Val_flash_block(&ocaml_flash_heap[34])

#define OCAML_atom0                Val_flash_block(&ocaml_flash_heap[1])

PROGMEM opcode_t const ocaml_bytecode[OCAML_BYTECODE_BSIZE] = {
  /*   0 */  OCAML_BRANCH_1B, 47,
  /*   2 */  OCAML_ACC0,
  /*   3 */  OCAML_C_CALL1, 0,
  /*   5 */  OCAML_RETURN, 1,
  /*   7 */  OCAML_RESTART,
  /*   8 */  OCAML_GRAB, 1,
  /*  10 */  OCAML_ACC0,
  /*  11 */  OCAML_C_CALL1, 1,
  /*  13 */  OCAML_PUSHACC2,
  /*  14 */  OCAML_C_CALL1, 1,
  /*  16 */  OCAML_PUSH,
  /*  17 */  OCAML_PUSHACC2,
  /*  18 */  OCAML_ADDINT,
  /*  19 */  OCAML_C_CALL1, 2,
  /*  21 */  OCAML_PUSHACC2,
  /*  22 */  OCAML_PUSHCONST0,
  /*  23 */  OCAML_PUSHACC2,
  /*  24 */  OCAML_PUSHCONST0,
  /*  25 */  OCAML_PUSHACC7,
  /*  26 */  OCAML_C_CALL5, 3,
  /*  28 */  OCAML_ACC1,
  /*  29 */  OCAML_PUSHACC3,
  /*  30 */  OCAML_PUSHACC2,
  /*  31 */  OCAML_PUSHCONST0,
  /*  32 */  OCAML_PUSHACC, 8,
  /*  34 */  OCAML_C_CALL5, 3,
  /*  36 */  OCAML_ACC0,
  /*  37 */  OCAML_C_CALL1, 4,
  /*  39 */  OCAML_RETURN, 5,
  /*  41 */  OCAML_ACC0,
  /*  42 */  OCAML_PUSHGETFLASHGLOBAL_1B, 0,
  /*  44 */  OCAML_MAKEBLOCK2, 0,
  /*  46 */  OCAML_RAISE,
  /*  47 */  OCAML_CLOSURE_1B, 0, (opcode_t) -6,
  /*  50 */  OCAML_SETRAMGLOBAL_1B, 0,
  /*  52 */  OCAML_CONST0,
  /*  53 */  OCAML_C_CALL1, 5,
  /*  55 */  OCAML_CLOSURE_1B, 0, (opcode_t) -47,
  /*  58 */  OCAML_SETRAMGLOBAL_1B, 14,
  /*  60 */  OCAML_CLOSURE_1B, 0, (opcode_t) -58,
  /*  63 */  OCAML_SETRAMGLOBAL_1B, 8,
  /*  65 */  OCAML_BRANCH_1B, 90,
  /*  67 */  OCAML_ACC0,
  /*  68 */  OCAML_C_CALL1, 6,
  /*  70 */  OCAML_RETURN, 1,
  /*  72 */  OCAML_ACC0,
  /*  73 */  OCAML_C_CALL1, 7,
  /*  75 */  OCAML_RETURN, 1,
  /*  77 */  OCAML_RESTART,
  /*  78 */  OCAML_GRAB, 2,
  /*  80 */  OCAML_ACC1,
  /*  81 */  OCAML_BGTINT_1B, 0, 16,
  /*  84 */  OCAML_ACC2,
  /*  85 */  OCAML_BGTINT_1B, 0, 12,
  /*  88 */  OCAML_ACC2,
  /*  89 */  OCAML_PUSHACC1,
  /*  90 */  OCAML_C_CALL1, 8,
  /*  92 */  OCAML_SUBINT,
  /*  93 */  OCAML_PUSHACC2,
  /*  94 */  OCAML_GTINT,
  /*  95 */  OCAML_BRANCHIFNOT_1B, 8,
  /*  97 */  OCAML_GETFLASHGLOBAL_1B, 1,
  /*  99 */  OCAML_PUSHGETRAMGLOBAL_1B, 0,
  /* 101 */  OCAML_APPTERM1, 4,
  /* 103 */  OCAML_ACC2,
  /* 104 */  OCAML_C_CALL1, 2,
  /* 106 */  OCAML_PUSHACC3,
  /* 107 */  OCAML_PUSHCONST0,
  /* 108 */  OCAML_PUSHACC2,
  /* 109 */  OCAML_PUSHACC5,
  /* 110 */  OCAML_PUSHACC5,
  /* 111 */  OCAML_C_CALL5, 9,
  /* 113 */  OCAML_ACC0,
  /* 114 */  OCAML_RETURN, 4,
  /* 116 */  OCAML_ACC0,
  /* 117 */  OCAML_PUSHGETRAMGLOBAL_1B, 1,
  /* 119 */  OCAML_APPLY1,
  /* 120 */  OCAML_C_CALL1, 6,
  /* 122 */  OCAML_RETURN, 1,
  /* 124 */  OCAML_ACC0,
  /* 125 */  OCAML_C_CALL1, 8,
  /* 127 */  OCAML_PUSH,
  /* 128 */  OCAML_C_CALL1, 2,
  /* 130 */  OCAML_PUSHACC1,
  /* 131 */  OCAML_PUSHCONST0,
  /* 132 */  OCAML_PUSHACC2,
  /* 133 */  OCAML_PUSHCONST0,
  /* 134 */  OCAML_PUSHACC6,
  /* 135 */  OCAML_C_CALL5, 9,
  /* 137 */  OCAML_ACC0,
  /* 138 */  OCAML_RETURN, 3,
  /* 140 */  OCAML_RESTART,
  /* 141 */  OCAML_GRAB, 1,
  /* 143 */  OCAML_ACC0,
  /* 144 */  OCAML_C_CALL1, 2,
  /* 146 */  OCAML_PUSHACC2,
  /* 147 */  OCAML_PUSHACC2,
  /* 148 */  OCAML_PUSHCONST0,
  /* 149 */  OCAML_PUSHACC3,
  /* 150 */  OCAML_C_CALL4, 10,
  /* 152 */  OCAML_ACC0,
  /* 153 */  OCAML_RETURN, 3,
  /* 155 */  OCAML_CLOSURE_1B, 0, (opcode_t) -14,
  /* 158 */  OCAML_SETRAMGLOBAL_1B, 5,
  /* 160 */  OCAML_CONST0,
  /* 161 */  OCAML_C_CALL1, 2,
  /* 163 */  OCAML_CLOSURE_1B, 0, (opcode_t) -39,
  /* 166 */  OCAML_SETRAMGLOBAL_1B, 1,
  /* 168 */  OCAML_CLOSURE_1B, 0, (opcode_t) -52,
  /* 171 */  OCAML_SETRAMGLOBAL_1B, 19,
  /* 173 */  OCAML_CLOSURE_1B, 0, (opcode_t) -95,
  /* 176 */  OCAML_SETRAMGLOBAL_1B, 3,
  /* 178 */  OCAML_CLOSURE_1B, 0, (opcode_t) -106,
  /* 181 */  OCAML_SETRAMGLOBAL_1B, 7,
  /* 183 */  OCAML_CLOSURE_1B, 0, (opcode_t) -116,
  /* 186 */  OCAML_SETRAMGLOBAL_1B, 6,
  /* 188 */  OCAML_BRANCH_1B, 97,
  /* 190 */  OCAML_RESTART,
  /* 191 */  OCAML_GRAB, 1,
  /* 193 */  OCAML_CONST0,
  /* 194 */  OCAML_PUSHACC2,
  /* 195 */  OCAML_C_CALL1, 1,
  /* 197 */  OCAML_OFFSETINT_1B, (opcode_t) -1,
  /* 199 */  OCAML_PUSH,
  /* 200 */  OCAML_PUSHACC2,
  /* 201 */  OCAML_GTINT,
  /* 202 */  OCAML_BRANCHIF_1B, 19,
  /* 204 */  OCAML_CHECK_SIGNALS,
  /* 205 */  OCAML_ACC1,
  /* 206 */  OCAML_PUSHACC4,
  /* 207 */  OCAML_GETBYTESCHAR,
  /* 208 */  OCAML_PUSHACC2,
  /* 209 */  OCAML_PUSHACC4,
  /* 210 */  OCAML_APPLY2,
  /* 211 */  OCAML_ACC1,
  /* 212 */  OCAML_PUSH,
  /* 213 */  OCAML_OFFSETINT_1B, 1,
  /* 215 */  OCAML_ASSIGN, 2,
  /* 217 */  OCAML_ACC1,
  /* 218 */  OCAML_NEQ,
  /* 219 */  OCAML_BRANCHIF_1B, (opcode_t) -15,
  /* 221 */  OCAML_CONST0,
  /* 222 */  OCAML_RETURN, 4,
  /* 224 */  OCAML_RESTART,
  /* 225 */  OCAML_GRAB, 1,
  /* 227 */  OCAML_CONST0,
  /* 228 */  OCAML_PUSHACC2,
  /* 229 */  OCAML_C_CALL1, 1,
  /* 231 */  OCAML_OFFSETINT_1B, (opcode_t) -1,
  /* 233 */  OCAML_PUSH,
  /* 234 */  OCAML_PUSHACC2,
  /* 235 */  OCAML_GTINT,
  /* 236 */  OCAML_BRANCHIF_1B, 18,
  /* 238 */  OCAML_CHECK_SIGNALS,
  /* 239 */  OCAML_ACC1,
  /* 240 */  OCAML_PUSHACC4,
  /* 241 */  OCAML_GETBYTESCHAR,
  /* 242 */  OCAML_PUSHACC3,
  /* 243 */  OCAML_APPLY1,
  /* 244 */  OCAML_ACC1,
  /* 245 */  OCAML_PUSH,
  /* 246 */  OCAML_OFFSETINT_1B, 1,
  /* 248 */  OCAML_ASSIGN, 2,
  /* 250 */  OCAML_ACC1,
  /* 251 */  OCAML_NEQ,
  /* 252 */  OCAML_BRANCHIF_1B, (opcode_t) -14,
  /* 254 */  OCAML_CONST0,
  /* 255 */  OCAML_RETURN, 4,
  /* 257 */  OCAML_RESTART,
  /* 258 */  OCAML_GRAB, 2,
  /* 260 */  OCAML_ACC2,
  /* 261 */  OCAML_PUSHACC2,
  /* 262 */  OCAML_PUSHACC2,
  /* 263 */  OCAML_PUSHGETRAMGLOBAL_1B, 2,
  /* 265 */  OCAML_APPLY1,
  /* 266 */  OCAML_PUSHGETRAMGLOBAL_1B, 3,
  /* 268 */  OCAML_APPLY3,
  /* 269 */  OCAML_PUSHGETRAMGLOBAL_1B, 4,
  /* 271 */  OCAML_APPTERM1, 4,
  /* 273 */  OCAML_RESTART,
  /* 274 */  OCAML_GRAB, 1,
  /* 276 */  OCAML_ACC1,
  /* 277 */  OCAML_PUSHACC1,
  /* 278 */  OCAML_PUSHGETRAMGLOBAL_1B, 5,
  /* 280 */  OCAML_APPLY2,
  /* 281 */  OCAML_PUSHGETRAMGLOBAL_1B, 4,
  /* 283 */  OCAML_APPTERM1, 3,
  /* 285 */  OCAML_GETRAMGLOBAL_1B, 6,
  /* 287 */  OCAML_SETRAMGLOBAL_1B, 4,
  /* 289 */  OCAML_GETRAMGLOBAL_1B, 7,
  /* 291 */  OCAML_SETRAMGLOBAL_1B, 2,
  /* 293 */  OCAML_CLOSURE_1B, 0, (opcode_t) -19,
  /* 296 */  OCAML_SETRAMGLOBAL_1B, 13,
  /* 298 */  OCAML_CLOSURE_1B, 0, (opcode_t) -40,
  /* 301 */  OCAML_SETRAMGLOBAL_1B, 15,
  /* 303 */  OCAML_CLOSURE_1B, 0, (opcode_t) -78,
  /* 306 */  OCAML_SETRAMGLOBAL_1B, 20,
  /* 308 */  OCAML_CLOSURE_1B, 0, (opcode_t) -117,
  /* 311 */  OCAML_SETRAMGLOBAL_1B, 12,
  /* 313 */  OCAML_BRANCH_2B, 0, 220,
  /* 316 */  OCAML_ACC0,
  /* 317 */  OCAML_PUSHGETRAMGLOBAL_1B, 8,
  /* 319 */  OCAML_APPLY1,
  /* 320 */  OCAML_PUSHGETRAMGLOBAL_1B, 9,
  /* 322 */  OCAML_APPTERM1, 2,
  /* 324 */  OCAML_RESTART,
  /* 325 */  OCAML_GRAB, 1,
  /* 327 */  OCAML_ACC1,
  /* 328 */  OCAML_PUSHACC1,
  /* 329 */  OCAML_PUSHENVACC1,
  /* 330 */  OCAML_SUBINT,
  /* 331 */  OCAML_OFFSETINT_1B, (opcode_t) -1,
  /* 333 */  OCAML_C_CALL2, 11,
  /* 335 */  OCAML_RETURN, 2,
  /* 337 */  OCAML_ACC0,
  /* 338 */  OCAML_PUSHGETRAMGLOBAL_1B, 10,
  /* 340 */  OCAML_PUSHGETRAMGLOBAL_1B, 11,
  /* 342 */  OCAML_APPLY2,
  /* 343 */  OCAML_PUSHGETRAMGLOBAL_1B, 10,
  /* 345 */  OCAML_CLOSURE_1B, 1, (opcode_t) -20,
  /* 348 */  OCAML_PUSHGETRAMGLOBAL_1B, 12,
  /* 350 */  OCAML_APPTERM2, 3,
  /* 352 */  OCAML_RESTART,
  /* 353 */  OCAML_GRAB, 1,
  /* 355 */  OCAML_ACC1,
  /* 356 */  OCAML_C_CALL1, 1,
  /* 358 */  OCAML_PUSHACC1,
  /* 359 */  OCAML_PUSHACC1,
  /* 360 */  OCAML_LTINT,
  /* 361 */  OCAML_BRANCHIFNOT_1B, 15,
  /* 363 */  OCAML_CONSTINT_1B, 32,
  /* 365 */  OCAML_PUSHACC1,
  /* 366 */  OCAML_PUSHACC3,
  /* 367 */  OCAML_SUBINT,
  /* 368 */  OCAML_PUSHGETRAMGLOBAL_1B, 13,
  /* 370 */  OCAML_APPLY2,
  /* 371 */  OCAML_PUSHACC3,
  /* 372 */  OCAML_PUSHGETRAMGLOBAL_1B, 14,
  /* 374 */  OCAML_APPTERM2, 5,
  /* 376 */  OCAML_ACC1,
  /* 377 */  OCAML_PUSHACC1,
  /* 378 */  OCAML_GTINT,
  /* 379 */  OCAML_BRANCHIFNOT_1B, 9,
  /* 381 */  OCAML_ACC1,
  /* 382 */  OCAML_PUSHCONST0,
  /* 383 */  OCAML_PUSHACC4,
  /* 384 */  OCAML_PUSHGETRAMGLOBAL_1B, 15,
  /* 386 */  OCAML_APPTERM3, 6,
  /* 388 */  OCAML_ACC2,
  /* 389 */  OCAML_RETURN, 3,
  /* 391 */  OCAML_ACC0,
  /* 392 */  OCAML_PUSHGETRAMGLOBAL_1B, 8,
  /* 394 */  OCAML_APPLY1,
  /* 395 */  OCAML_PUSHGETRAMGLOBAL_1B, 16,
  /* 397 */  OCAML_APPTERM1, 2,
  /* 399 */  OCAML_CONST0,
  /* 400 */  OCAML_PUSHCONST0,
  /* 401 */  OCAML_PUSHGETRAMGLOBAL_1B, 17,
  /* 403 */  OCAML_APPLY2,
  /* 404 */  OCAML_PUSHGETRAMGLOBAL_1B, 18,
  /* 406 */  OCAML_APPTERM1, 2,
  /* 408 */  OCAML_RESTART,
  /* 409 */  OCAML_GRAB, 1,
  /* 411 */  OCAML_ENVACC1,
  /* 412 */  OCAML_C_CALL1, 1,
  /* 414 */  OCAML_PUSHACC1,
  /* 415 */  OCAML_LTINT,
  /* 416 */  OCAML_BRANCHIFNOT_1B, 32,
  /* 418 */  OCAML_ACC0,
  /* 419 */  OCAML_PUSHENVACC1,
  /* 420 */  OCAML_C_CALL2, 12,
  /* 422 */  OCAML_PUSH,
  /* 423 */  OCAML_BGTINT_1B, 48, 22,
  /* 426 */  OCAML_ACC0,
  /* 427 */  OCAML_BLTINT_1B, 57, 18,
  /* 430 */  OCAML_CONSTINT_1B, 48,
  /* 432 */  OCAML_PUSHACC1,
  /* 433 */  OCAML_PUSHCONSTINT_1B, 10,
  /* 435 */  OCAML_PUSHACC5,
  /* 436 */  OCAML_MULINT,
  /* 437 */  OCAML_ADDINT,
  /* 438 */  OCAML_SUBINT,
  /* 439 */  OCAML_PUSHACC2,
  /* 440 */  OCAML_OFFSETINT_1B, 1,
  /* 442 */  OCAML_PUSHOFFSETCLOSURE0,
  /* 443 */  OCAML_APPTERM2, 5,
  /* 445 */  OCAML_ACC2,
  /* 446 */  OCAML_RETURN, 3,
  /* 448 */  OCAML_ACC1,
  /* 449 */  OCAML_RETURN, 2,
  /* 451 */  OCAML_ACC0,
  /* 452 */  OCAML_CLOSUREREC_1B, 1, 1, (opcode_t) -43,
  /* 456 */  OCAML_CONST0,
  /* 457 */  OCAML_PUSHCONST0,
  /* 458 */  OCAML_PUSHACC2,
  /* 459 */  OCAML_APPTERM2, 4,
  /* 461 */  OCAML_CONST0,
  /* 462 */  OCAML_C_CALL1, 13,
  /* 464 */  OCAML_PUSHENVACC1,
  /* 465 */  OCAML_PUSHACC1,
  /* 466 */  OCAML_NEQ,
  /* 467 */  OCAML_BRANCHIFNOT_1B, 18,
  /* 469 */  OCAML_ENVACC2,
  /* 470 */  OCAML_PUSHACC2,
  /* 471 */  OCAML_LTINT,
  /* 472 */  OCAML_BRANCHIFNOT_1B, 13,
  /* 474 */  OCAML_ACC0,
  /* 475 */  OCAML_PUSHACC2,
  /* 476 */  OCAML_PUSHENVACC3,
  /* 477 */  OCAML_C_CALL3, 14,
  /* 479 */  OCAML_ACC1,
  /* 480 */  OCAML_OFFSETINT_1B, 1,
  /* 482 */  OCAML_PUSHOFFSETCLOSURE0,
  /* 483 */  OCAML_APPTERM1, 3,
  /* 485 */  OCAML_ENVACC3,
  /* 486 */  OCAML_RETURN, 2,
  /* 488 */  OCAML_RESTART,
  /* 489 */  OCAML_GRAB, 1,
  /* 491 */  OCAML_ACC0,
  /* 492 */  OCAML_BRANCHIFNOT_1B, 6,
  /* 494 */  OCAML_ACC0,
  /* 495 */  OCAML_GETFIELD0,
  /* 496 */  OCAML_BRANCH_1B, 4,
  /* 498 */  OCAML_CONSTINT_1B, 10,
  /* 500 */  OCAML_PUSHCONSTINT_1B, 32,
  /* 502 */  OCAML_PUSH,
  /* 503 */  OCAML_C_CALL1, 2,
  /* 505 */  OCAML_PUSH,
  /* 506 */  OCAML_PUSHACC2,
  /* 507 */  OCAML_PUSHACC4,
  /* 508 */  OCAML_CLOSUREREC_1B, 1, 3, (opcode_t) -47,
  /* 512 */  OCAML_CONST0,
  /* 513 */  OCAML_PUSHACC1,
  /* 514 */  OCAML_APPLY1,
  /* 515 */  OCAML_PUSHGETRAMGLOBAL_1B, 19,
  /* 517 */  OCAML_APPTERM1, 7,
  /* 519 */  OCAML_ACC0,
  /* 520 */  OCAML_C_CALL1, 15,
  /* 522 */  OCAML_RETURN, 1,
  /* 524 */  OCAML_ACC0,
  /* 525 */  OCAML_PUSH,
  /* 526 */  OCAML_CLOSURE_1B, 0, (opcode_t) -7,
  /* 529 */  OCAML_PUSHGETRAMGLOBAL_1B, 20,
  /* 531 */  OCAML_APPTERM2, 3,
  /* 533 */  OCAML_CLOSURE_1B, 0, (opcode_t) -9,
  /* 536 */  OCAML_PUSH,
  /* 537 */  OCAML_SETRAMGLOBAL_1B, 16,
  /* 539 */  OCAML_ACC0,
  /* 540 */  OCAML_POP, 1,
  /* 542 */  OCAML_PUSH,
  /* 543 */  OCAML_CLOSURE_1B, 0, (opcode_t) -54,
  /* 546 */  OCAML_PUSH,
  /* 547 */  OCAML_SETRAMGLOBAL_1B, 17,
  /* 549 */  OCAML_ACC0,
  /* 550 */  OCAML_POP, 1,
  /* 552 */  OCAML_PUSH,
  /* 553 */  OCAML_CLOSURE_1B, 0, (opcode_t) -102,
  /* 556 */  OCAML_PUSH,
  /* 557 */  OCAML_SETRAMGLOBAL_1B, 18,
  /* 559 */  OCAML_ACC0,
  /* 560 */  OCAML_POP, 1,
  /* 562 */  OCAML_PUSH,
  /* 563 */  OCAML_CLOSURE_2B, 0, (opcode_t) -1, 92,
  /* 567 */  OCAML_PUSH,
  /* 568 */  OCAML_CLOSURE_2B, 0, (opcode_t) -1, 79,
  /* 572 */  OCAML_PUSH,
  /* 573 */  OCAML_PUSHACC2,
  /* 574 */  OCAML_PUSHACC4,
  /* 575 */  OCAML_PUSHACC6,
  /* 576 */  OCAML_PUSHACC, 8,
  /* 578 */  OCAML_MAKEBLOCK_1B, 0, 5,
  /* 581 */  OCAML_POP, 5,
  /* 583 */  OCAML_PUSHCONSTINT_1B, 6,
  /* 585 */  OCAML_PUSH,
  /* 586 */  OCAML_SETRAMGLOBAL_1B, 10,
  /* 588 */  OCAML_ACC0,
  /* 589 */  OCAML_POP, 1,
  /* 591 */  OCAML_PUSH,
  /* 592 */  OCAML_CLOSURE_2B, 0, (opcode_t) -1, 17,
  /* 596 */  OCAML_PUSH,
  /* 597 */  OCAML_SETRAMGLOBAL_1B, 11,
  /* 599 */  OCAML_ACC0,
  /* 600 */  OCAML_POP, 1,
  /* 602 */  OCAML_PUSH,
  /* 603 */  OCAML_CLOSURE_2B, 0, (opcode_t) -2, 246,
  /* 607 */  OCAML_PUSH,
  /* 608 */  OCAML_SETRAMGLOBAL_1B, 9,
  /* 610 */  OCAML_ACC0,
  /* 611 */  OCAML_POP, 1,
  /* 613 */  OCAML_PUSH,
  /* 614 */  OCAML_CLOSURE_2B, 0, (opcode_t) -2, 214,
  /* 618 */  OCAML_PUSH,
  /* 619 */  OCAML_PUSHACC2,
  /* 620 */  OCAML_PUSHACC4,
  /* 621 */  OCAML_PUSHACC6,
  /* 622 */  OCAML_MAKEBLOCK_1B, 0, 4,
  /* 625 */  OCAML_POP, 4,
  /* 627 */  OCAML_PUSH,
  /* 628 */  OCAML_GETFIELD3,
  /* 629 */  OCAML_PUSHACC1,
  /* 630 */  OCAML_GETFIELD2,
  /* 631 */  OCAML_PUSHACC2,
  /* 632 */  OCAML_GETFIELD0,
  /* 633 */  OCAML_MAKEBLOCK3, 0,
  /* 635 */  OCAML_SETRAMGLOBAL_1B, 22,
  /* 637 */  OCAML_ACC1,
  /* 638 */  OCAML_GETFIELD1,
  /* 639 */  OCAML_PUSHACC2,
  /* 640 */  OCAML_GETFIELD3,
  /* 641 */  OCAML_PUSHACC3,
  /* 642 */  OCAML_GETFIELD0,
  /* 643 */  OCAML_PUSHACC4,
  /* 644 */  OCAML_GETFIELD, 4,
  /* 646 */  OCAML_MAKEBLOCK_1B, 0, 4,
  /* 649 */  OCAML_SETRAMGLOBAL_1B, 21,
  /* 651 */  OCAML_BRANCH_1B, 17,
  /* 653 */  OCAML_ACC0,
  /* 654 */  OCAML_BRANCHIF_1B, 5,
  /* 656 */  OCAML_CONST1,
  /* 657 */  OCAML_RETURN, 1,
  /* 659 */  OCAML_ACC0,
  /* 660 */  OCAML_OFFSETINT_1B, (opcode_t) -1,
  /* 662 */  OCAML_PUSHOFFSETCLOSURE0,
  /* 663 */  OCAML_APPLY1,
  /* 664 */  OCAML_PUSHACC1,
  /* 665 */  OCAML_MULINT,
  /* 666 */  OCAML_RETURN, 1,
  /* 668 */  OCAML_CLOSUREREC_1B, 1, 0, (opcode_t) -15,
  /* 672 */  OCAML_CONST0,
  /* 673 */  OCAML_C_CALL1, 16,
  /* 675 */  OCAML_CONSTINT_1B, 5,
  /* 677 */  OCAML_PUSHACC1,
  /* 678 */  OCAML_APPLY1,
  /* 679 */  OCAML_PUSH,
  /* 680 */  OCAML_PUSHGETRAMGLOBAL_1B, 21,
  /* 682 */  OCAML_GETFIELD0,
  /* 683 */  OCAML_APPLY1,
  /* 684 */  OCAML_ACC0,
  /* 685 */  OCAML_PUSHGETRAMGLOBAL_1B, 22,
  /* 687 */  OCAML_GETFIELD2,
  /* 688 */  OCAML_APPLY1,
  /* 689 */  OCAML_POP, 2,
  /* 691 */  OCAML_STOP
};

#include </media/sf_SF2/ml/O2B/omicrob/include/vm/runtime.c>

PROGMEM void * const ocaml_primitives[OCAML_PRIMITIVE_NUMBER] = {
  /*  0 */  (void *) &caml_string_of_int,
  /*  1 */  (void *) &caml_ml_string_length,
  /*  2 */  (void *) &caml_create_bytes,
  /*  3 */  (void *) &caml_blit_string,
  /*  4 */  (void *) &caml_string_of_bytes,
  /*  5 */  (void *) &caml_fresh_oo_id,
  /*  6 */  (void *) &caml_unsafe_string_of_bytes,
  /*  7 */  (void *) &caml_unsafe_bytes_of_string,
  /*  8 */  (void *) &caml_ml_bytes_length,
  /*  9 */  (void *) &caml_blit_bytes,
  /* 10 */  (void *) &caml_fill_bytes,
  /* 11 */  (void *) &caml_nios_ssd_display_char,
  /* 12 */  (void *) &caml_string_get,
  /* 13 */  (void *) &caml_nios_serial_read_char,
  /* 14 */  (void *) &caml_bytes_set,
  /* 15 */  (void *) &caml_nios_serial_write_char,
  /* 16 */  (void *) &caml_nios_get_sys_id,
};
