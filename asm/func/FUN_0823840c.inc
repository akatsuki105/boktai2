	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r1, #0xc3
	lsls r1, r1, #2
	bl ClearMemory
	adds r0, r4, #0
	bl FUN_08238148
	adds r0, r4, #0
	adds r0, #0x40
	bl FUN_08238148
	adds r0, r4, #0
	adds r0, #0x80
	bl FUN_08238148
	adds r0, r4, #0
	adds r0, #0xc0
	bl FUN_08238148
	movs r6, #0
	movs r0, #0x82
	lsls r0, r0, #1
	mov r8, r0
	movs r7, #0
	adds r5, r4, r0
_08238446:
	lsls r0, r6, #5
	mov r2, r8
	adds r1, r4, r2
	adds r1, r1, r0
	str r7, [r1]
	movs r2, #0x84
	lsls r2, r2, #1
	adds r1, r4, r2
	adds r1, r1, r0
	str r7, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	adds r1, r5, #0
	bl FUN_08238178
	adds r5, #0x20
	adds r6, #1
	cmp r6, #0xf
	ble _08238446
	ldr r0, _0823847C @ =0x03000820
	str r4, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823847C: .4byte 0x03000820
