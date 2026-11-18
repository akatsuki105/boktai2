	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #2
	cmp r5, r3
	bgt _0819F948
	movs r0, #0
	cmp r5, r2
	ble _0819F948
	movs r0, #1
_0819F948:
	ldr r1, _0819F970 @ =0x085ADDD4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	cmp r0, #0
	bne _0819F978
	ldr r1, [r4]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _0819F974
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _0819F976
	.align 2, 0
_0819F970: .4byte 0x085ADDD4
_0819F974:
	orrs r1, r2
_0819F976:
	str r1, [r4]
_0819F978:
	cmp r5, #0x3c
	bgt _0819F980
	movs r0, #0
	b _0819F98A
_0819F980:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r0, #1
_0819F98A:
	pop {r4, r5}
	pop {r1}
	bx r1
