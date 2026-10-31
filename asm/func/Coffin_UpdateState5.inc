	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r1, _08088DBC @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _08088D5E
	adds r0, r4, #0
	movs r1, #5
	bl Coffin_SetState
_08088D5E:
	ldr r0, _08088DC0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08088D6E
	b _08088FAE
_08088D6E:
	ldr r2, _08088DC4 @ =0x0000032A
	adds r1, r4, r2
	movs r2, #0
	movs r0, #2
	strh r0, [r1]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0xe2
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	movs r5, #0
	mov r8, r5
	movs r0, #0xfb
	lsls r0, r0, #1
	adds r3, r4, r0
	ldrh r2, [r3]
	lsls r0, r2, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x3f
	bhi _08088DCC
	adds r2, r4, #0
	adds r2, #0x4a
	movs r3, #0
	ldrsh r1, [r2, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	ldr r3, _08088DC8 @ =0x000003CE
	adds r1, r4, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	asrs r0, r0, #3
	strh r0, [r2]
	b _08088E56
	.align 2, 0
_08088DBC: .4byte 0x000001F5
_08088DC0: .4byte 0x030047A4
_08088DC4: .4byte 0x0000032A
_08088DC8: .4byte 0x000003CE
_08088DCC:
	cmp r1, #0x7f
	bhi _08088E1C
	ldr r2, _08088E0C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08088E10 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08088E14 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r1, r0
	lsls r0, r1, #4
	adds r0, r0, r1
	subs r0, #8
	ldr r2, _08088E18 @ =0x0000031E
	adds r1, r4, r2
	strh r0, [r1]
	rsbs r0, r0, #0
	adds r2, #4
	adds r1, r4, r2
	strh r0, [r1]
	movs r5, #1
	ldrh r1, [r3]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08088E52
	mov r8, r5
	b _08088E52
	.align 2, 0
_08088E0C: .4byte 0x030046B8
_08088E10: .4byte 0x000003FF
_08088E14: .4byte 0x0203B400
_08088E18: .4byte 0x0000031E
_08088E1C:
	cmp r1, #0xbf
	bhi _08088E3A
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _08088E2C
	movs r5, #1
_08088E2C:
	movs r0, #0xf
	ands r0, r2
	cmp r0, #0
	bne _08088E52
	movs r3, #1
	mov r8, r3
	b _08088E52
_08088E3A:
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08088E46
	movs r5, #1
_08088E46:
	movs r0, #0xf
	ands r0, r2
	cmp r0, #0
	bne _08088E52
	movs r0, #1
	mov r8, r0
_08088E52:
	cmp r5, #0
	beq _08088F04
_08088E56:
	adds r3, r4, #0
	adds r3, #0x84
	ldr r0, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r3]
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r7, r4, r1
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	cmp r2, #0
	blt _08088E9C
	cmp r1, #0
	blt _08088E9C
	ldr r0, _08088EA0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08088E9C
	ldr r0, _08088EA4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08088EA8
_08088E9C:
	movs r5, #0
	b _08088EB6
	.align 2, 0
_08088EA0: .4byte 0x030046A8
_08088EA4: .4byte 0x030046AC
_08088EA8:
	ldr r0, _08088EC8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08088EB6:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08088ECC
	adds r0, #4
	b _08088ED8
	.align 2, 0
_08088EC8: .4byte 0x030046A4
_08088ECC:
	ldr r0, _08088EEC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08088ED8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08088EF0
	cmp r2, #2
	beq _08088EF4
	b _08088EF8
	.align 2, 0
_08088EEC: .4byte 0x030046A4
_08088EF0:
	ldrb r0, [r7, #4]
	b _08088EF6
_08088EF4:
	ldrb r0, [r7]
_08088EF6:
	subs r1, r1, r0
_08088EF8:
	ldr r2, _08088F00 @ =0x0000035A
	adds r0, r4, r2
	strh r1, [r0]
	b _08088F1E
	.align 2, 0
_08088F00: .4byte 0x0000035A
_08088F04:
	adds r2, r4, #0
	adds r2, #0x84
	ldr r0, [r2]
	movs r3, #1
	orrs r0, r3
	str r0, [r2]
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r6, r2, #0
_08088F1E:
	mov r1, r8
	cmp r1, #0
	beq _08088F32
	adds r0, r4, #0
	adds r0, #0x48
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r1, r4, r2
	bl FUN_08085a74
_08088F32:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
	movs r3, #0xfb
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xff
	bls _08088FAE
	adds r0, r4, #0
	bl Coffin_RemoveEffSprite
	ldr r0, _08088F8C @ =0x03002C00
	ldr r0, [r0]
	movs r1, #0
	bl Coffin_SetState
	movs r0, #0xec
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r2, [r1]
	cmp r2, #0
	beq _08088FA0
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl VM_ExecByID
	ldr r1, _08088F90 @ =0x0000040B
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08088F94
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	b _08088FAE
	.align 2, 0
_08088F8C: .4byte 0x03002C00
_08088F90: .4byte 0x0000040B
_08088F94:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	b _08088FAE
_08088FA0:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	ldr r2, _08088FB8 @ =0x0000040B
	adds r0, r4, r2
	strb r1, [r0]
_08088FAE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08088FB8: .4byte 0x0000040B
