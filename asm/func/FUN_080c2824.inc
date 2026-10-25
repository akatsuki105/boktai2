	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov ip, r0
	ldrh r0, [r0, #4]
	cmp r0, #0
	bne _080C289A
	mov r1, ip
	ldrb r0, [r1, #1]
	strh r0, [r1, #0x34]
	ldr r2, _080C28C8 @ =0x0203B400
	mov sb, r2
	ldr r7, _080C28CC @ =0x030046B8
	mov r8, r7
	ldr r6, _080C28D0 @ =0x000003FF
	movs r5, #0x1f
	mov r3, ip
	movs r4, #7
_080C284A:
	mov r0, r8
	ldr r1, [r0]
	adds r1, #1
	ands r1, r6
	lsls r0, r1, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	subs r0, #0x10
	movs r7, #0x99
	lsls r7, r7, #2
	adds r2, r3, r7
	strh r0, [r2]
	adds r1, #1
	ands r1, r6
	lsls r0, r1, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	subs r0, #0x18
	adds r7, #2
	adds r2, r3, r7
	strh r0, [r2]
	adds r1, #1
	ands r1, r6
	mov r0, r8
	str r1, [r0]
	lsls r1, r1, #1
	add r1, sb
	ldrh r0, [r1]
	ands r0, r5
	subs r0, #0x10
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r1, r3, r2
	strh r0, [r1]
	adds r3, #8
	subs r4, #1
	cmp r4, #0
	bge _080C284A
_080C289A:
	mov r7, ip
	ldrh r0, [r7, #4]
	adds r1, r0, #1
	strh r1, [r7, #4]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080C28D4
	movs r0, #0
	strb r0, [r7]
	movs r3, #1
	mov r1, ip
	adds r1, #0x24
	movs r2, #0xac
	lsls r2, r2, #1
	add r2, ip
_080C28BA:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _080C28BA
	b _080C296C
	.align 2, 0
_080C28C8: .4byte 0x0203B400
_080C28CC: .4byte 0x030046B8
_080C28D0: .4byte 0x000003FF
_080C28D4:
	movs r5, #0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3c
	bls _080C28E4
	lsrs r5, r1, #0x12
	movs r0, #1
	ands r5, r0
_080C28E4:
	ldr r4, _080C2904 @ =0x00000266
	add r4, ip
	mov r2, ip
	adds r2, #0x40
	mov r3, ip
	adds r3, #0x24
	movs r6, #0xac
	lsls r6, r6, #1
	add r6, ip
_080C28F6:
	cmp r5, #0
	beq _080C2908
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	b _080C2910
	.align 2, 0
_080C2904: .4byte 0x00000266
_080C2908:
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_080C2910:
	str r0, [r3]
	movs r0, #0x99
	lsls r0, r0, #2
	add r0, ip
	ldrh r0, [r0]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r4]
	ldrh r7, [r2, #2]
	adds r0, r0, r7
	strh r0, [r2, #2]
	movs r0, #0x9a
	lsls r0, r0, #2
	add r0, ip
	ldrh r0, [r0]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	movs r7, #2
	ldrsh r0, [r2, r7]
	cmp r0, #0xff
	bgt _080C295E
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r2, #2]
	movs r0, #0
	ldrsh r1, [r4, r0]
	rsbs r0, r1, #0
	cmp r0, #0
	blt _080C2958
	asrs r0, r0, #1
	b _080C295C
_080C2958:
	asrs r0, r1, #1
	rsbs r0, r0, #0
_080C295C:
	strh r0, [r4]
_080C295E:
	adds r4, #8
	movs r1, #8
	add ip, r1
	adds r2, #0x2c
	adds r3, #0x2c
	cmp r3, r6
	ble _080C28F6
_080C296C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
