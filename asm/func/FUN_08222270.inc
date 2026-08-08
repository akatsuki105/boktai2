	push {r4, r5, r6, r7, lr}
	sub sp, #0x20
	adds r6, r0, #0
	ldr r1, _082222E4 @ =0x08252894
	add r0, sp, #0x10
	movs r2, #8
	bl memcpy
	ldr r1, _082222E8 @ =0x0000FFFF
	ldr r0, [sp, #0x18]
	ands r0, r1
	movs r1, #0xe0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r2, _082222EC @ =0xFFFF0000
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r5, #0
	adds r7, r1, #0
	adds r4, r6, #0
	adds r4, #0x78
_082222A0:
	mov r0, sp
	adds r0, r0, r5
	adds r0, #0x10
	ldrb r2, [r0]
	ldr r1, _082222EC @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x18]
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0x18
	movs r2, #0
	movs r3, #0x30
	bl FUN_0822f3fc
	ldr r0, [r4, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #8]
	adds r4, #0x60
	adds r5, #1
	cmp r5, #7
	ble _082222A0
	add sp, #0x20
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082222E4: .4byte 0x08252894
_082222E8: .4byte 0x0000FFFF
_082222EC: .4byte 0xFFFF0000
