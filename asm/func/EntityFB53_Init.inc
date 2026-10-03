	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0804B990 @ =0x03002B54
	movs r0, #0
	str r0, [r1]
	ldr r0, _0804B994 @ =0x030000D8
	str r4, [r0]
	bl SuspendSunlight
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0804B98A
	bl FUN_0823d340
	str r0, [r4, #0x28]
	cmp r0, #0
	beq _0804B98A
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0804B98A
	bl FUN_0823d340
	str r0, [r4, #0x2c]
	cmp r0, #0
	bne _0804B998
_0804B98A:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804B9B2
	.align 2, 0
_0804B990: .4byte 0x03002B54
_0804B994: .4byte 0x030000D8
_0804B998:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetNamedArgValue
	str r0, [r4, #0x34]
	adds r0, r4, #0
	bl FUN_0804b3f8
	movs r0, #0
	movs r1, #0
	bl FUN_0804e9f4
	movs r0, #0
_0804B9B2:
	pop {r4}
	pop {r1}
	bx r1
