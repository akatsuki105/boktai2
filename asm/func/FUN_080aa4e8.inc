	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	movs r0, #0
	mov sb, r0
	movs r1, #0xb0
	lsls r1, r1, #1
	add r1, r8
	str r1, [sp]
	mov sl, r0
	movs r7, #0xb0
	lsls r7, r7, #1
	add r7, r8
_080AA50A:
	movs r0, #0xad
	lsls r0, r0, #1
	add r0, r8
	mov r1, sb
	adds r6, r0, r1
	ldrb r2, [r6]
	cmp r2, #0
	beq _080AA5B0
	movs r0, #0x2c
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, #0xe4
	mov r1, r8
	adds r5, r1, r0
	cmp r2, #1
	bne _080AA584
	ldrh r0, [r5, #0x1e]
	subs r0, #0x32
	movs r1, #0
	mov ip, r1
	movs r3, #0
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r4, #0xae
	lsls r4, r4, #1
	add r4, r8
	add r4, sl
	ldrh r1, [r4]
	cmp r0, r1
	bgt _080AA564
	ldr r0, _080AA560 @ =0x000001FF
	str r3, [sp, #4]
	bl PlaySound_082406e0
	ldrh r0, [r4]
	strh r0, [r5, #0x1e]
	movs r0, #2
	strb r0, [r6]
	ldr r3, [sp, #4]
	b _080AA5AE
	.align 2, 0
_080AA560: .4byte 0x000001FF
_080AA564:
	ldr r1, [sp]
	add r1, sl
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x18
	bls _080AA5B0
	ldr r0, [r5]
	orrs r0, r2
	str r0, [r5]
	mov r0, ip
	strb r0, [r6]
	strh r3, [r1]
	b _080AA5B0
_080AA584:
	ldrh r0, [r7]
	adds r1, r0, #1
	movs r2, #0
	movs r3, #0
	strh r1, [r7]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _080AA5A4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x12
	subs r1, #0xc
	ldrh r0, [r5, #0x1e]
	subs r0, r0, r1
	strh r0, [r5, #0x1e]
	b _080AA5B0
_080AA5A4:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	strb r2, [r6]
_080AA5AE:
	strh r3, [r7]
_080AA5B0:
	movs r1, #2
	add sl, r1
	adds r7, #2
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #1
	ble _080AA50A
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
