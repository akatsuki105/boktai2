	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080519A2
	movs r1, #0
	strb r1, [r4, #0x1d]
	adds r0, r4, #0
	adds r0, #0x2c
	strb r1, [r0]
	movs r5, #0
	movs r6, #0
	adds r2, r4, #0
	adds r2, #0xec
_0805196C:
	movs r1, #3
	ands r1, r5
	cmp r5, #3
	bgt _08051996
	adds r0, r4, #0
	adds r0, #0x24
	adds r0, r0, r1
	adds r3, r2, #0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strb r1, [r2, #2]
	cmp r0, #0xa
	ble _0805198C
	movs r0, #0xa
	b _08051992
_0805198C:
	cmp r0, #0
	bge _08051992
	movs r0, #0
_08051992:
	strb r0, [r3, #3]
	b _0805199A
_08051996:
	strb r1, [r2, #2]
	strb r6, [r2, #3]
_0805199A:
	adds r2, #0x7c
	adds r5, #1
	cmp r5, #7
	ble _0805196C
_080519A2:
	ldr r0, [r4, #0x18]
	cmp r0, #0x59
	bls _080519BC
	ldr r0, [r4, #0x30]
	cmp r0, #0
	beq _080519B2
	bl _call_via_r0
_080519B2:
	movs r1, #0
	strb r1, [r4, #0x1c]
	movs r0, #1
	strb r0, [r4, #0x1d]
	str r1, [r4, #0x18]
_080519BC:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
