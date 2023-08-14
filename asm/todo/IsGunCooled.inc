	push {r4, r5, r6, lr}
	sub sp, #0x20
	bl GetDate
	ldr r6, _08241954 @ =0x030046A0
	ldr r1, [r6]
	movs r2, #0xd4
	lsls r2, r2, #1
	adds r1, r1, r2
	ldr r1, [r1]
	cmp r0, r1
	bne _08241958
	movs r6, #0
	b _0824199A
	.align 2, 0
_08241954: .4byte 0x030046A0
_08241958:
	add r4, sp, #0xc
	add r5, sp, #0x10
	bl GetDate
	adds r3, r0, #0
	add r0, sp, #8
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0823db08
	add r0, sp, #0x14
	add r1, sp, #0x18
	add r2, sp, #0x1c
	ldr r3, [r6]
	movs r4, #0xd4
	lsls r4, r4, #1
	adds r3, r3, r4
	ldr r3, [r3]
	bl FUN_0823db08
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #0x14]
	ldr r4, [sp, #0x18]
	str r4, [sp]
	ldr r4, [sp, #0x1c]
	str r4, [sp, #4]
	bl FUN_0823d9ec
	cmp r0, #1
	bhi _082419F8
	ldr r6, _082419F0 @ =0x00015180
_0824199A:
	bl GetHour
	adds r4, r0, #0
	bl GetMinute
	adds r5, r0, #0
	bl GetSecond
	lsls r1, r4, #4
	subs r1, r1, r4
	lsls r1, r1, #2
	adds r1, r1, r5
	lsls r2, r1, #4
	subs r2, r2, r1
	lsls r2, r2, #2
	adds r2, r2, r0
	ldr r0, _082419F4 @ =0x030046A0
	ldr r3, [r0]
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r0, [r0]
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #2
	movs r4, #0xd8
	lsls r4, r4, #1
	adds r0, r3, r4
	ldr r0, [r0]
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r4, #4
	adds r1, r3, r4
	ldr r1, [r1]
	adds r0, r0, r1
	subs r2, r2, r0
	adds r6, r6, r2
	cmp r6, #0xb3
	bgt _082419F8
	movs r0, #0
	b _082419FA
	.align 2, 0
_082419F0: .4byte 0x00015180
_082419F4: .4byte 0x030046A0
_082419F8:
	movs r0, #1
_082419FA:
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r1}
	bx r1
