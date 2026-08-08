	push {lr}
	cmp r0, #1
	beq _0822EE9C
	cmp r0, #1
	bgt _0822EE8C
	cmp r0, #0
	beq _0822EE92
	b _0822EEAC
_0822EE8C:
	cmp r0, #2
	beq _0822EEA4
	b _0822EEAC
_0822EE92:
	ldr r0, _0822EE98 @ =0x04000010
	b _0822EEAE
	.align 2, 0
_0822EE98: .4byte 0x04000010
_0822EE9C:
	ldr r0, _0822EEA0 @ =0x04000014
	b _0822EEAE
	.align 2, 0
_0822EEA0: .4byte 0x04000014
_0822EEA4:
	ldr r0, _0822EEA8 @ =0x04000018
	b _0822EEAE
	.align 2, 0
_0822EEA8: .4byte 0x04000018
_0822EEAC:
	ldr r0, _0822EEB4 @ =0x0400001C
_0822EEAE:
	pop {r1}
	bx r1
	.align 2, 0
_0822EEB4: .4byte 0x0400001C
