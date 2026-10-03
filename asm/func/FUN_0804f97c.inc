	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	adds r7, r1, #0
	adds r7, #0x3c
	adds r4, r1, #0
	adds r4, #0x48
	movs r3, #0
	ldrb r0, [r7, #6]
	cmp r0, #0
	beq _0804F9B8
	movs r2, #0
	adds r5, r1, #0
	adds r5, #0x38
	adds r1, r5, #0
	movs r6, #0
_0804F99A:
	adds r0, r1, r2
	strb r6, [r0]
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r3, r3, r0
	adds r2, #1
	cmp r2, #3
	ble _0804F99A
	cmp r3, #0
	ble _0804F9CE
	movs r0, #3
	movs r1, #1
	bl FUN_08050e50
	b _0804F9CE
_0804F9B8:
	movs r2, #0
	adds r5, r1, #0
	adds r5, #0x38
	adds r3, r5, #0
_0804F9C0:
	adds r0, r3, r2
	adds r1, r4, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #3
	ble _0804F9C0
_0804F9CE:
	ldrb r0, [r4, #6]
	cmp r0, #0
	beq _0804F9EC
	movs r2, #0
	adds r3, r5, #0
_0804F9D8:
	adds r1, r3, r2
	adds r0, r7, r2
	ldrb r0, [r0]
	ldrb r4, [r1]
	adds r0, r0, r4
	strb r0, [r1]
	adds r2, #1
	cmp r2, #3
	ble _0804F9D8
	b _0804F9F4
_0804F9EC:
	movs r2, #3
_0804F9EE:
	subs r2, #1
	cmp r2, #0
	bge _0804F9EE
_0804F9F4:
	movs r2, #3
_0804F9F6:
	subs r2, #1
	cmp r2, #0
	bge _0804F9F6
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
