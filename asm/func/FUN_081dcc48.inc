	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	mov r8, r1
	ldr r0, _081DCCD4 @ =0x00000856
	add r0, ip
	ldrh r0, [r0]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r7, r0, #2
	ldr r4, _081DCCD8 @ =0x030046B4
	ldr r1, [r4]
	adds r1, #1
	ldr r5, _081DCCDC @ =0x000003FF
	ands r1, r5
	str r1, [r4]
	ldr r6, _081DCCE0 @ =0x085B0200
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	movs r3, #7
	ands r2, r3
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r3
	movs r2, #0x64
	muls r0, r2, r0
	adds r7, r7, r0
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	ands r1, r3
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r7, r7, r0
	ldr r0, _081DCCE4 @ =0x0000270F
	cmp r7, r0
	ble _081DCCB6
	adds r7, r0, #0
_081DCCB6:
	mov r0, r8
	lsls r1, r0, #1
	ldr r0, _081DCCE8 @ =0x000006E4
	add r0, ip
	adds r0, r0, r1
	strh r7, [r0]
	mov r0, ip
	mov r1, r8
	bl FUN_081dcb8c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCCD4: .4byte 0x00000856
_081DCCD8: .4byte 0x030046B4
_081DCCDC: .4byte 0x000003FF
_081DCCE0: .4byte 0x085B0200
_081DCCE4: .4byte 0x0000270F
_081DCCE8: .4byte 0x000006E4
