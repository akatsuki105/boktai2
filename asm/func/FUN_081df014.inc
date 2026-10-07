	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DF036
	ldr r1, _081DF04C @ =0x000002E2
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	bl VM_ExecByID
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0xff
	strb r0, [r1]
_081DF036:
	adds r0, r4, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DF050
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF0F0
	.align 2, 0
_081DF04C: .4byte 0x000002E2
_081DF050:
	movs r5, #0
	movs r7, #0
	movs r3, #0
	ldrh r6, [r4, #0x1a]
	cmp r5, r6
	bge _081DF0A6
	movs r0, #0xf0
	lsls r0, r0, #6
	mov ip, r0
_081DF062:
	cmp r3, #0
	bge _081DF070
	ldr r0, _081DF06C @ =0x0000FFFF
	b _081DF078
	.align 2, 0
_081DF06C: .4byte 0x0000FFFF
_081DF070:
	ldr r1, [r4, #0x44]
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r0, [r0]
_081DF078:
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r0, r2, #0
	mov r1, ip
	ands r0, r1
	movs r1, #0xb0
	lsls r1, r1, #6
	cmp r0, r1
	bne _081DF08E
	movs r0, #1
	b _081DF090
_081DF08E:
	movs r0, #0
_081DF090:
	cmp r0, #0
	beq _081DF0A0
	movs r0, #0x3f
	ands r0, r2
	cmp r0, #0
	beq _081DF09E
	adds r7, #1
_081DF09E:
	adds r5, #1
_081DF0A0:
	adds r3, #1
	cmp r3, r6
	blt _081DF062
_081DF0A6:
	cmp r5, r6
	bne _081DF0D0
	cmp r5, r7
	bne _081DF0C0
	ldr r2, _081DF0BC @ =FUN_081df0f8
	adds r0, r4, #0
	movs r1, #0x11
	bl Entity9A9F_SetState
	b _081DF0EE
	.align 2, 0
_081DF0BC: .4byte FUN_081df0f8
_081DF0C0:
	ldr r2, _081DF0CC @ =FUN_081df3f0
	adds r0, r4, #0
	movs r1, #0x14
	bl Entity9A9F_SetState
	b _081DF0EE
	.align 2, 0
_081DF0CC: .4byte FUN_081df3f0
_081DF0D0:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _081DF0EE
	lsls r0, r0, #0x10
	movs r1, #0xb0
	lsls r1, r1, #0x16
	orrs r1, r0
	lsls r1, r1, #2
	lsrs r1, r1, #0x12
	adds r0, r4, #0
	adds r0, #0x42
	strh r1, [r0]
_081DF0EE:
	movs r0, #0
_081DF0F0:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
