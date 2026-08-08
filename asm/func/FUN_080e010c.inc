	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r5, #0
	movs r0, #0xda
	lsls r0, r0, #1
	mov sb, r0
_080E011E:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080E012E
	movs r0, #1
	b _080E0130
_080E012E:
	movs r0, #0
_080E0130:
	adds r1, r5, #1
	mov r8, r1
	cmp r0, #0
	beq _080E0178
	mov r0, sb
	muls r0, r5, r0
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x3c
	adds r4, r7, r4
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08236424
	adds r0, r4, #0
	bl FUN_0822a4e0
	movs r6, #0
_080E0156:
	movs r0, #0x5c
	adds r1, r6, #0
	muls r1, r0, r1
	adds r0, r1, r5
	adds r0, r7, r0
	adds r0, #0x7c
	ldrb r0, [r0]
	cmp r0, #0
	beq _080E0172
	adds r0, r1, #0
	adds r0, #0x3c
	adds r0, r4, r0
	bl FUN_0822a4e0
_080E0172:
	adds r6, #1
	cmp r6, #1
	ble _080E0156
_080E0178:
	mov r5, r8
	cmp r5, #7
	ble _080E011E
	ldr r1, _080E0190 @ =0x0300017C
	movs r0, #0
	str r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080E0190: .4byte 0x0300017C
