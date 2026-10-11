	push {lr}
	adds r3, r0, #0
	movs r0, #0xdf
	adds r0, r0, r3
	mov ip, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809FAF4
	adds r2, r3, #0
	adds r2, #0xe5
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	mov r0, ip
	strb r1, [r0]
	adds r2, #9
	ldrh r1, [r2]
	cmp r1, #0x3f
	bls _0809FAEE
	ldrh r0, [r2]
	subs r0, #0x40
	movs r1, #0x1f
	ands r0, r1
	asrs r0, r0, #1
	b _0809FAF2
_0809FAEE:
	movs r0, #0xf
	ands r0, r1
_0809FAF2:
	strh r0, [r2]
_0809FAF4:
	movs r1, #0xe5
	adds r1, r1, r3
	mov ip, r1
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809FB46
	adds r2, r3, #0
	adds r2, #0xee
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5f
	bls _0809FB22
	movs r0, #2
	strh r0, [r3, #0x10]
	movs r0, #0
	mov r1, ip
	strb r0, [r1]
	movs r0, #0
	strh r0, [r2]
	b _0809FB46
_0809FB22:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bhi _0809FB36
	movs r0, #0xf
	ands r1, r0
	cmp r1, #7
	bhi _0809FB42
	movs r0, #1
	b _0809FB44
_0809FB36:
	movs r0, #0x1f
	ands r1, r0
	cmp r1, #0xf
	bhi _0809FB42
	movs r0, #1
	b _0809FB44
_0809FB42:
	movs r0, #2
_0809FB44:
	strh r0, [r3, #0x10]
_0809FB46:
	ldr r0, _0809FB78 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809FB7C @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	cmp r2, #0
	bne _0809FBA8
	adds r0, r3, #0
	adds r0, #0xdd
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809FB80
	adds r1, r3, #0
	adds r1, #0xec
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0809FBEE
	strh r2, [r1]
	b _0809FBEE
	.align 2, 0
_0809FB78: .4byte 0x030046A0
_0809FB7C: .4byte 0x00000942
_0809FB80:
	adds r0, r3, #0
	adds r0, #0xec
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r0, _0809FBA0 @ =0xFFFFFED4
	cmp r1, r0
	bge _0809FBEE
	ldr r2, _0809FBA4 @ =FUN_0809f840
	adds r0, r3, #0
	movs r1, #1
	bl Entity1DBEElem_SetState
	b _0809FBEE
	.align 2, 0
_0809FBA0: .4byte 0xFFFFFED4
_0809FBA4: .4byte FUN_0809f840
_0809FBA8:
	cmp r2, #7
	ble _0809FBEE
	adds r0, r3, #0
	adds r0, #0xdd
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809FBD0
	adds r1, r3, #0
	adds r1, #0xec
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0809FBEE
	movs r0, #0
	strh r0, [r1]
	b _0809FBEE
_0809FBD0:
	adds r0, r3, #0
	adds r0, #0xec
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	movs r0, #0x96
	lsls r0, r0, #0x11
	cmp r1, r0
	ble _0809FBEE
	ldr r2, _0809FBF4 @ =FUN_0809f938
	adds r0, r3, #0
	movs r1, #2
	bl Entity1DBEElem_SetState
_0809FBEE:
	pop {r0}
	bx r0
	.align 2, 0
_0809FBF4: .4byte FUN_0809f938
