	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r0, r4
	mov sb, r0
	movs r3, #0
	ldr r1, _0804CD78 @ =0x030057E0
	adds r0, r4, #0
	adds r0, #0x21
	ldrb r2, [r0]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r0, [r0, #0x12]
	cmp r0, #0
	beq _0804CDD4
	adds r5, r4, #0
	adds r5, #0x90
	adds r0, r2, #0
	bl rfu_UNI_clearRecvNewDataFlag
	adds r0, r4, #0
	adds r0, #0xd0
	ldrb r6, [r0]
	adds r1, r6, #1
	adds r2, r4, #0
	adds r2, #0x94
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrb r3, [r2]
	mov r8, r0
	adds r7, r2, #0
	cmp r1, r3
	bne _0804CD7C
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r7, #0
	bl FUN_0823a790
	b _0804CD94
	.align 2, 0
_0804CD78: .4byte 0x030057E0
_0804CD7C:
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r3
	bne _0804CD8A
	adds r1, r4, #0
	adds r1, #0xd4
	b _0804CD8E
_0804CD8A:
	adds r1, r4, #0
	adds r1, #0xd8
_0804CD8E:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0804CD94:
	ldrb r0, [r7]
	movs r1, #0
	mov r2, r8
	strb r0, [r2]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	strb r1, [r5, #1]
	adds r3, r4, #0
	adds r3, #0xec
	adds r2, r4, #0
	adds r2, #0xfa
	movs r4, #1
_0804CDAE:
	mov r6, sb
	ldrb r0, [r6, #2]
	asrs r0, r1
	ands r0, r4
	cmp r0, #0
	beq _0804CDC0
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
_0804CDC0:
	adds r1, #1
	cmp r1, #4
	ble _0804CDAE
	ldrh r0, [r3]
	movs r1, #0
	strh r0, [r5, #2]
	ldr r0, _0804CDE4 @ =0x0000FFFF
	strh r0, [r3]
	strb r1, [r2]
	movs r3, #1
_0804CDD4:
	adds r0, r3, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804CDE4: .4byte 0x0000FFFF
