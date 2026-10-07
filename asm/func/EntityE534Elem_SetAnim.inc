	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r1, #0
	movs r0, #6
	ldrsb r0, [r5, r0]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	add r4, sp, #4
	mov r3, sp
	adds r3, #5
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r3, #0
	cmp r0, #1
	bhi _080118A4
	movs r0, #1
	b _080118A6
_080118A4:
	movs r0, #0
_080118A6:
	strb r0, [r4]
	cmp r1, #1
	bls _080118B0
	movs r0, #1
	b _080118B2
_080118B0:
	movs r0, #0
_080118B2:
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x30
	ldr r1, [r6, #0x20]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r3, sp, #4
	ldrb r3, [r3]
	ldrb r4, [r7]
	str r4, [sp]
	bl AuxAnim_SetAnim
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
