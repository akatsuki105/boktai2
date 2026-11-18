	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	ldr r2, _080CD5F8 @ =0x03003584
	ldr r1, _080CD5FC @ =0x0000094C
	adds r0, r3, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #1
	ldr r4, _080CD600 @ =0x00000938
	adds r0, r3, r4
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r2]
	adds r6, r1, r0
	ldr r0, _080CD604 @ =0x0000094E
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _080CD624
	ldr r1, _080CD608 @ =0x00000359
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CD60C
	movs r5, #0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r1, r3, r2
_080CD5DE:
	subs r0, r5, #5
	cmp r0, #1
	bls _080CD5EC
	cmp r5, #0xd
	beq _080CD5EC
	ldrh r0, [r6]
	strh r0, [r1]
_080CD5EC:
	adds r6, #2
	adds r1, #2
	adds r5, #1
	cmp r5, #0xf
	ble _080CD5DE
	b _080CD6E2
	.align 2, 0
_080CD5F8: .4byte 0x03003584
_080CD5FC: .4byte 0x0000094C
_080CD600: .4byte 0x00000938
_080CD604: .4byte 0x0000094E
_080CD608: .4byte 0x00000359
_080CD60C:
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r1, r3, r4
	movs r5, #0xf
_080CD614:
	ldrh r0, [r6]
	strh r0, [r1]
	adds r6, #2
	adds r1, #2
	subs r5, #1
	cmp r5, #0
	bge _080CD614
	b _080CD6E2
_080CD624:
	ldr r2, _080CD68C @ =0x00000359
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CD690
	movs r5, #0
	mov r8, r1
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r7, r3, r4
_080CD638:
	subs r0, r5, #5
	cmp r0, #1
	bls _080CD680
	cmp r5, #0xd
	beq _080CD680
	ldrh r1, [r6]
	movs r0, #0x1f
	mov ip, r0
	movs r0, #0x1f
	ands r0, r1
	mov r3, r8
	ldrb r2, [r3]
	adds r4, r0, r2
	cmp r4, #0x1f
	ble _080CD658
	movs r4, #0x1f
_080CD658:
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	adds r1, r0, r2
	cmp r1, #0x1f
	ble _080CD668
	movs r1, #0x1f
_080CD668:
	lsrs r0, r3, #0x1a
	mov r3, ip
	ands r0, r3
	adds r0, r0, r2
	cmp r0, #0x1f
	ble _080CD676
	movs r0, #0x1f
_080CD676:
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r7]
_080CD680:
	adds r6, #2
	adds r7, #2
	adds r5, #1
	cmp r5, #0xf
	ble _080CD638
	b _080CD6E2
	.align 2, 0
_080CD68C: .4byte 0x00000359
_080CD690:
	movs r4, #0x1f
	mov ip, r4
	mov r8, r1
	movs r0, #0xa9
	lsls r0, r0, #2
	adds r7, r3, r0
	movs r5, #0xf
_080CD69E:
	ldrh r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	mov r3, r8
	ldrb r2, [r3]
	adds r4, r0, r2
	cmp r4, #0x1f
	ble _080CD6B0
	movs r4, #0x1f
_080CD6B0:
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	adds r1, r0, r2
	cmp r1, #0x1f
	ble _080CD6C0
	movs r1, #0x1f
_080CD6C0:
	lsrs r0, r3, #0x1a
	mov r3, ip
	ands r0, r3
	adds r0, r0, r2
	cmp r0, #0x1f
	ble _080CD6CE
	movs r0, #0x1f
_080CD6CE:
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r7]
	adds r6, #2
	adds r7, #2
	subs r5, #1
	cmp r5, #0
	bge _080CD69E
_080CD6E2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
