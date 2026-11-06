	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _08051920
	movs r1, #0
	strb r1, [r4, #0x1d]
	adds r0, r4, #0
	adds r0, #0x2c
	strb r1, [r0]
	movs r5, #0
	movs r6, #3
	movs r7, #0
	adds r2, r4, #0
	adds r2, #0xec
_080518B6:
	adds r1, r5, #0
	ands r1, r6
	cmp r5, #3
	bgt _080518E0
	adds r0, r4, #0
	adds r0, #0x24
	adds r0, r0, r1
	adds r3, r2, #0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strb r1, [r2, #2]
	cmp r0, #0xa
	ble _080518D6
	movs r0, #0xa
	b _080518DC
_080518D6:
	cmp r0, #0
	bge _080518DC
	movs r0, #0
_080518DC:
	strb r0, [r3, #3]
	b _08051918
_080518E0:
	adds r0, r4, #0
	adds r0, #0x20
	adds r0, r0, r1
	adds r3, r2, #0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strb r1, [r2, #2]
	cmp r0, #0xa
	ble _080518F8
	movs r0, #0xa
	b _080518FE
_080518F8:
	cmp r0, #0
	bge _080518FE
	movs r0, #0
_080518FE:
	strb r0, [r3, #3]
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	movs r0, #0x88
	lsls r0, r0, #1
	adds r1, r1, r0
	strh r1, [r2, #0xc]
	movs r0, #0x20
	strh r0, [r2, #0xe]
	strh r7, [r2, #0x10]
_08051918:
	adds r2, #0x7c
	adds r5, #1
	cmp r5, #7
	ble _080518B6
_08051920:
	adds r0, r4, #0
	movs r1, #2
	bl Entity08051b70_LaunchNext
	ldr r0, [r4, #0x18]
	cmp r0, #0x59
	bls _08051942
	ldr r0, [r4, #0x30]
	cmp r0, #0
	beq _08051938
	bl _call_via_r0
_08051938:
	movs r1, #0
	strb r1, [r4, #0x1c]
	movs r0, #1
	strb r0, [r4, #0x1d]
	str r1, [r4, #0x18]
_08051942:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
