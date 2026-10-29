	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _080592B8 @ =0x0300012C
	ldr r5, [r1]
	cmp r5, #0
	bne _080592BC
	movs r0, #0
	b _080592F2
	.align 2, 0
_080592B8: .4byte 0x0300012C
_080592BC:
	movs r4, #0
	movs r6, #1
	movs r1, #9
	mov r8, r1
	mov ip, r4
	adds r3, r5, #0
	adds r3, #0x60
	movs r7, #0x8c
	lsls r7, r7, #1
_080592CE:
	adds r2, r6, #0
	lsls r2, r4
	ldr r1, [r5, #0x1c]
	ands r1, r2
	cmp r1, #0
	beq _080592EA
	ldrb r1, [r3]
	cmp r1, #7
	beq _080592EA
	mov r1, r8
	strb r1, [r3]
	strb r6, [r3, #4]
	mov r1, ip
	str r1, [r3, #0x10]
_080592EA:
	adds r3, r3, r7
	adds r4, #1
	cmp r4, #0xb
	ble _080592CE
_080592F2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
