	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r2, r0, #0
	movs r0, #0xa4
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r3, #0
	ldrsh r4, [r1, r3]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne _080670C2
	adds r5, r4, #1
	movs r0, #7
	ands r5, r0
	mov sb, r5
	adds r3, r4, #7
	ands r3, r0
	movs r6, #1
	mov r8, r1
	movs r7, #1
	rsbs r7, r7, #0
	mov ip, r7
	ldr r0, _080670D0 @ =0x00000292
	adds r1, r2, r0
_0806709E:
	movs r5, #0
	ldrsh r2, [r1, r5]
	cmp r2, ip
	beq _080670BA
	adds r0, r2, #0
	cmp r0, sb
	beq _080670C4
	cmp r0, r3
	beq _080670C4
	mov r5, r8
	movs r7, #0
	ldrsh r0, [r5, r7]
	cmp r2, r0
	bne _080670C2
_080670BA:
	adds r1, #2
	adds r6, #1
	cmp r6, #4
	ble _0806709E
_080670C2:
	adds r0, r4, #0
_080670C4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080670D0: .4byte 0x00000292
