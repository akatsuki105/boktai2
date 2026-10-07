	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r2, r0, #0
	ldr r1, _080811CC @ =0x03003584
	ldr r3, _080811D0 @ =0x0000094C
	adds r0, r2, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	ldr r0, _080811D4 @ =0x0000094E
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _080811D8
	movs r5, #0
	movs r3, #0xa9
	lsls r3, r3, #2
	adds r1, r2, r3
_080811B2:
	subs r0, r5, #5
	cmp r0, #1
	bls _080811C0
	cmp r5, #0xd
	beq _080811C0
	ldrh r0, [r6]
	strh r0, [r1]
_080811C0:
	adds r6, #2
	adds r1, #2
	adds r5, #1
	cmp r5, #0xf
	ble _080811B2
	b _08081234
	.align 2, 0
_080811CC: .4byte 0x03003584
_080811D0: .4byte 0x0000094C
_080811D4: .4byte 0x0000094E
_080811D8:
	movs r5, #0
	mov r8, r1
	movs r0, #0xa9
	lsls r0, r0, #2
	adds r7, r2, r0
_080811E2:
	subs r0, r5, #5
	cmp r0, #1
	bls _0808122A
	cmp r5, #0xd
	beq _0808122A
	ldrh r1, [r6]
	movs r3, #0x1f
	mov ip, r3
	movs r0, #0x1f
	ands r0, r1
	mov r3, r8
	ldrb r2, [r3]
	adds r4, r0, r2
	cmp r4, #0x1f
	ble _08081202
	movs r4, #0x1f
_08081202:
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	adds r1, r0, r2
	cmp r1, #0x1f
	ble _08081212
	movs r1, #0x1f
_08081212:
	lsrs r0, r3, #0x1a
	mov r3, ip
	ands r0, r3
	adds r0, r0, r2
	cmp r0, #0x1f
	ble _08081220
	movs r0, #0x1f
_08081220:
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r7]
_0808122A:
	adds r6, #2
	adds r7, #2
	adds r5, #1
	cmp r5, #0xf
	ble _080811E2
_08081234:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
