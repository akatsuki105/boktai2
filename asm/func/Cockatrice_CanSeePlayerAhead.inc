	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r1, _08159E28 @ =0x00000256
	adds r0, r4, r1
	ldrh r5, [r0]
	ldr r2, _08159E2C @ =0x00000472
	adds r0, r4, r2
	ldrh r0, [r0]
	lsrs r0, r0, #8
	mov r8, r0
	ldr r6, _08159E30 @ =0x030046A4
	ldr r2, [r6]
	ldr r0, [r2, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r3, #6
	ldrsh r0, [r0, r3]
	adds r7, r1, #0
	muls r7, r0, r7
	ldr r0, _08159E34 @ =0x03002BE0
	ldr r1, [r0]
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _08159E24
	cmp r1, #0
	blt _08159E24
	ldr r0, _08159E38 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08159E24
	ldr r0, _08159E3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08159E40
_08159E24:
	movs r0, #0
	b _08159E4C
	.align 2, 0
_08159E28: .4byte 0x00000256
_08159E2C: .4byte 0x00000472
_08159E30: .4byte 0x030046A4
_08159E34: .4byte 0x03002BE0
_08159E38: .4byte 0x030046A8
_08159E3C: .4byte 0x030046AC
_08159E40:
	lsls r0, r1, #1
	adds r1, r2, #0
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r3
_08159E4C:
	mov sb, r0
	ldrb r0, [r4, #5]
	lsrs r0, r0, #6
	cmp r0, #1
	beq _08159ECE
	cmp r0, #1
	bgt _08159E60
	cmp r0, #0
	beq _08159E6C
	b _08159FB2
_08159E60:
	cmp r0, #2
	beq _08159F16
	cmp r0, #3
	bne _08159E6A
	b _08159F6C
_08159E6A:
	b _08159FB2
_08159E6C:
	adds r4, r5, #1
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	cmp r5, r0
	blt _08159E8C
	b _08159FB2
_08159E8C:
	adds r7, r6, #0
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_08159E94:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08159EA4
	adds r0, #4
	b _08159EAA
_08159EA4:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_08159EAA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bls _08159EB6
	b _08159FB2
_08159EB6:
	cmp r4, sb
	beq _08159F68
	adds r6, #4
	adds r4, #1
	adds r5, #1
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _08159E94
	b _08159FB2
_08159ECE:
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r5, r0
	cmp r7, r4
	ble _08159FB2
	adds r5, r6, #0
_08159EDE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08159EEE
	adds r0, #4
	b _08159EF8
_08159EEE:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08159EF8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bhi _08159FB2
	cmp r4, sb
	beq _08159F68
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	adds r4, r4, r0
	cmp r7, r4
	bgt _08159EDE
	b _08159FB2
_08159F16:
	subs r4, r5, #1
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	cmp r5, #0
	blt _08159FB2
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_08159F32:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08159F42
	adds r0, #4
	b _08159F4A
_08159F42:
	ldr r0, _08159F64 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_08159F4A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bhi _08159FB2
	cmp r4, sb
	beq _08159F68
	subs r6, #4
	subs r4, #1
	subs r5, #1
	cmp r5, #0
	bge _08159F32
	b _08159FB2
	.align 2, 0
_08159F64: .4byte 0x030046A4
_08159F68:
	movs r0, #1
	b _08159FB4
_08159F6C:
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r4, r5, r0
	cmp r4, #0
	blt _08159FB2
	adds r5, r6, #0
_08159F7C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08159F8C
	adds r0, #4
	b _08159F96
_08159F8C:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08159F96:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bhi _08159FB2
	cmp r4, sb
	beq _08159F68
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	cmp r4, #0
	bge _08159F7C
_08159FB2:
	movs r0, #0
_08159FB4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
