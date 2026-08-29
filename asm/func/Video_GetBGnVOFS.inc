	push {lr}
	cmp r0, #1
	beq _0822EED8
	cmp r0, #1
	bgt _0822EEC8
	cmp r0, #0
	beq _0822EECE
	b _0822EEE8
_0822EEC8:
	cmp r0, #2
	beq _0822EEE0
	b _0822EEE8
_0822EECE:
	ldr r0, _0822EED4 @ =0x04000012
	b _0822EEEA
	.align 2, 0
_0822EED4: .4byte 0x04000012
_0822EED8:
	ldr r0, _0822EEDC @ =0x04000016
	b _0822EEEA
	.align 2, 0
_0822EEDC: .4byte 0x04000016
_0822EEE0:
	ldr r0, _0822EEE4 @ =0x0400001A
	b _0822EEEA
	.align 2, 0
_0822EEE4: .4byte 0x0400001A
_0822EEE8:
	ldr r0, _0822EEF0 @ =0x0400001E
_0822EEEA:
	pop {r1}
	bx r1
	.align 2, 0
_0822EEF0: .4byte 0x0400001E
