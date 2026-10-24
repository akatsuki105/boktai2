	push {lr}
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x6b
	bl VM_GetNamedArgValue
	adds r3, r0, #0
	cmp r3, #0x38
	bhi _0820D004
	cmp r3, #0x1f
	bgt _0820CFEC
	ldr r0, _0820CFE8 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	movs r1, #1
	lsls r1, r3
	b _0820CFFE
	.align 2, 0
_0820CFE8: .4byte 0x030046A0
_0820CFEC:
	ldr r0, _0820D008 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_0820CFFE:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0820D004:
	pop {r0}
	bx r0
	.align 2, 0
_0820D008: .4byte 0x030046A0
