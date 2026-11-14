	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r4, r1, #0
	mov sb, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805BE58
	movs r0, #0
	strb r0, [r4]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
	adds r1, r4, #0
	adds r1, #0x14
	movs r2, #0
	bl Hitbox_SetPos
_0805BE58:
	mov r0, r8
	ldrb r1, [r0, #0x1c]
	cmp r1, #0
	beq _0805BE66
	movs r0, #5
	movs r1, #0
	b _0805BE70
_0805BE66:
	mov r2, r8
	ldrb r0, [r2, #0x1e]
	cmp r0, #0
	beq _0805BE7A
	movs r0, #9
_0805BE70:
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805BF52
_0805BE7A:
	movs r0, #8
	ldrsb r0, [r4, r0]
	adds r5, r4, #0
	adds r5, #0x14
	cmp r0, #0
	blt _0805BEF4
	ldrh r0, [r4, #4]
	movs r3, #7
	ands r3, r0
	movs r6, #8
	ldrsb r6, [r4, r6]
	movs r7, #0x28
	add r7, r8
	mov ip, r7
	cmp r3, #0
	bne _0805BED4
	lsls r0, r6, #2
	add r0, ip
	ldr r1, [r0]
	movs r0, #0
	ldrsh r2, [r1, r0]
	movs r7, #0x14
	ldrsh r0, [r4, r7]
	subs r2, r2, r0
	movs r7, #4
	ldrsh r0, [r1, r7]
	movs r7, #4
	ldrsh r1, [r5, r7]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0805BED0 @ =0x00022E24
	cmp r1, r0
	ble _0805BED4
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4]
	strh r3, [r4, #4]
	b _0805BF52
	.align 2, 0
_0805BED0: .4byte 0x00022E24
_0805BED4:
	lsls r0, r6, #2
	add r0, ip
	ldr r2, [r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r7, #0x14
	ldrsh r1, [r4, r7]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r7, #4
	ldrsh r2, [r5, r7]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #6]
_0805BEF4:
	adds r0, r4, #0
	adds r0, #0x7c
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r0, r8
	adds r1, r4, #0
	movs r2, #0
	bl RingoBat_SetAnim
	ldrh r0, [r4, #4]
	cmp r0, #0x3f
	bls _0805BF1C
	movs r0, #4
	movs r1, #0
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	strh r1, [r4, #4]
_0805BF1C:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0805BF4C
	subs r0, #1
	strb r0, [r4, #9]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0805BF4C
	mov r2, r8
	ldrb r0, [r2, #0x1f]
	cmp r0, #2
	bne _0805BF44
	mov r3, sb
	cmp r3, #7
	bgt _0805BF40
	movs r0, #1
	b _0805BF4A
_0805BF40:
	strb r1, [r4, #8]
	b _0805BF4C
_0805BF44:
	cmp r0, #0
	beq _0805BF4A
	movs r0, #0xff
_0805BF4A:
	strb r0, [r4, #8]
_0805BF4C:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
_0805BF52:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
