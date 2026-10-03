	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _08049DD8 @ =0x030000C8
	str r6, [r0]
	adds r5, r6, #0
	adds r5, #0x18
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r4, #0
	strb r4, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r4, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r4, [r0]
	adds r1, #6
	adds r0, r6, r1
	str r4, [r0]
	adds r1, #0xc
	adds r0, r6, r1
	str r4, [r0]
	subs r1, #4
	adds r0, r6, r1
	str r4, [r0]
	movs r0, #2
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x12
	movs r3, #2
	bl TextRenderer_Init
	strb r4, [r5, #0x14]
	movs r0, #0xca
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08049DDC @ =0x085AB548
	str r0, [r1]
	str r0, [r5, #0x1c]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0804990c
	strb r4, [r5, #0x11]
	movs r0, #1
	strb r0, [r5, #0xa]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r6, r1
	str r4, [r0]
	ldr r0, _08049DE0 @ =0x03002CE8
	str r4, [r0]
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08049DD8: .4byte 0x030000C8
_08049DDC: .4byte 0x085AB548
_08049DE0: .4byte 0x03002CE8
