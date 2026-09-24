	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r6, #0
	adds r7, #0xb8
	ldr r0, [r7]
	mov r8, r0
	cmp r0, #0
	beq _080CB860
	adds r1, r6, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _080CB7F0
	movs r0, #4
	strh r0, [r6, #0x28]
	b _080CB8DC
_080CB7F0:
	cmp r0, #4
	bne _080CB854
	adds r0, r6, #0
	adds r0, #0xbc
	adds r4, r6, #0
	adds r4, #0x18
	ldrh r1, [r0]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _080CB80C
	movs r0, #7
	b _080CB81A
_080CB80C:
	asrs r0, r1, #1
	ands r0, r2
	cmp r0, #0
	beq _080CB818
	movs r0, #8
	b _080CB81A
_080CB818:
	movs r0, #6
_080CB81A:
	strh r0, [r4, #0x10]
	cmp r1, #2
	bgt _080CB828
	ldr r0, [r4]
	movs r1, #0xd
	rsbs r1, r1, #0
	b _080CB84E
_080CB828:
	cmp r1, #4
	bgt _080CB838
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #8
	b _080CB840
_080CB838:
	cmp r1, #5
	bgt _080CB846
	ldr r0, [r4]
	movs r1, #0xc
_080CB840:
	orrs r0, r1
	str r0, [r4]
	b _080CB8DC
_080CB846:
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	subs r1, #0xd
_080CB84E:
	ands r0, r1
	str r0, [r4]
	b _080CB8DC
_080CB854:
	cmp r0, #6
	bls _080CB8DC
	adds r0, r6, #0
	bl KillEntity
	b _080CB8DC
_080CB860:
	adds r0, r6, #0
	adds r0, #0xb0
	ldrh r0, [r0]
	ldrh r1, [r6, #0x34]
	adds r0, r0, r1
	strh r0, [r6, #0x34]
	adds r0, r6, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	ldrh r2, [r6, #0x38]
	adds r0, r0, r2
	strh r0, [r6, #0x38]
	adds r4, r6, #0
	adds r4, #0x60
	adds r5, r6, #0
	adds r5, #0x34
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	ldr r0, _080CB8BC @ =0x03002BE0
	ldr r2, [r0]
	ldr r1, _080CB8C0 @ =0x00080002
	ldr r0, [r2, #0x20]
	orrs r0, r1
	str r0, [r2, #0x20]
	adds r0, r5, #0
	bl FUN_082328ec
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0x36
	ldrsh r1, [r6, r2]
	cmp r0, r1
	ble _080CB8C4
	movs r0, #1
	str r0, [r7]
	adds r0, r6, #0
	adds r0, #0xbe
	mov r1, r8
	strh r1, [r0]
	b _080CB8DC
	.align 2, 0
_080CB8BC: .4byte 0x03002BE0
_080CB8C0: .4byte 0x00080002
_080CB8C4:
	adds r1, r6, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080CB8DC
	adds r0, r6, #0
	bl KillEntity
_080CB8DC:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
