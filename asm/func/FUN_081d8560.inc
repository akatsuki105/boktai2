	push {r4, r5, lr}
	sub sp, #0x20
	adds r5, r0, #0
	movs r4, #0
_081D8568:
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r4, #5
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x40
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	movs r0, #0
	str r0, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x1c]
	adds r0, r5, #0
	adds r0, #0x1c
	movs r1, #8
	movs r2, #0x10
	movs r3, #4
	bl FUN_081ee584
	adds r4, #1
	cmp r4, #2
	ble _081D8568
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
