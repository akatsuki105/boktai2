	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #2
	cmp r5, r3
	bgt _0819F8EC
	movs r0, #0
	cmp r5, r2
	ble _0819F8EC
	movs r0, #1
_0819F8EC:
	ldr r1, _0819F914 @ =0x085ADDCC
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	cmp r0, #0
	bne _0819F91C
	ldr r1, [r4]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _0819F918
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _0819F91A
	.align 2, 0
_0819F914: .4byte 0x085ADDCC
_0819F918:
	orrs r1, r2
_0819F91A:
	str r1, [r4]
_0819F91C:
	cmp r5, #0x3c
	bgt _0819F924
	movs r0, #0
	b _0819F92E
_0819F924:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r0, #1
_0819F92E:
	pop {r4, r5}
	pop {r1}
	bx r1
