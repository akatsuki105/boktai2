	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0804ED58 @ =0x030000E8
	str r4, [r0]
	bl MosaicFader_Stop
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0804ED50
	bl FUN_0823d340
	str r0, [r4, #0x28]
	cmp r0, #0
	bne _0804ED5C
_0804ED50:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804ED78
	.align 2, 0
_0804ED58: .4byte 0x030000E8
_0804ED5C:
	movs r0, #0x72
	movs r1, #0
	bl VM_GetNamedArgValue
	str r0, [r4, #0x2c]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x20]
	movs r1, #0
	strb r1, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x1c]
	movs r0, #0
_0804ED78:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
