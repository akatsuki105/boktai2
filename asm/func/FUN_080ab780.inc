	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	ldr r7, [r0, #0x48]
	adds r0, #0x6d
	ldrb r0, [r0]
	movs r1, #0x10
	subs r1, r1, r0
	lsls r0, r1, #4
	subs r5, r0, r1
	movs r6, #0
	movs r0, #0x1f
	mov r8, r0
_080AB79C:
	ldrh r1, [r7]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	mov r2, r8
	ands r3, r2
	lsrs r1, r1, #0x1a
	ands r1, r2
	mov r2, ip
	adds r2, #0x6d
	ldrb r2, [r2]
	muls r0, r2, r0
	adds r0, r5, r0
	asrs r4, r0, #4
	adds r0, r3, #0
	muls r0, r2, r0
	adds r0, r5, r0
	asrs r3, r0, #4
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r5, r0
	asrs r1, r0, #4
	lsls r0, r6, #1
	mov r2, ip
	adds r2, #0x4c
	adds r2, r2, r0
	lsls r0, r1, #0xa
	lsls r1, r3, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r2]
	adds r7, #2
	adds r6, #1
	cmp r6, #0xf
	ble _080AB79C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
