	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x33
	movs r5, #0
	strb r5, [r0]
	ldr r0, _0804E2B4 @ =0x030000E0
	str r5, [r0]
	bl InitRfuAPI
	cmp r0, #0
	blt _0804E2AE
	strb r5, [r4, #0x1d]
	adds r0, r4, #0
	bl FUN_0804ba64
	movs r0, #1
	strb r5, [r4, #0x1c]
	movs r1, #1
	strh r0, [r4, #0x38]
	str r5, [r4, #0x44]
	adds r0, r4, #0
	adds r0, #0x32
	strb r1, [r0]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetNamedArgValue
	str r0, [r4, #0x4c]
	movs r0, #0x61
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0804E2AE
	bl FUN_0823d340
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	bne _0804E2B8
_0804E2AE:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804E2BA
	.align 2, 0
_0804E2B4: .4byte 0x030000E0
_0804E2B8:
	movs r0, #0
_0804E2BA:
	pop {r4, r5}
	pop {r1}
	bx r1
