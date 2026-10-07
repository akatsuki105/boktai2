	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	mov r8, r0
	adds r5, r1, #0
	movs r0, #0x48
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	adds r0, r5, #0
	adds r0, #0x50
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800D4C6
	cmp r1, #0
	blt _0800D4C6
	ldr r0, _0800D4CC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800D4C6
	ldr r0, _0800D4D0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800D4D4
_0800D4C6:
	movs r0, #0
	b _0800D4E2
	.align 2, 0
_0800D4CC: .4byte 0x030046A8
_0800D4D0: .4byte 0x030046AC
_0800D4D4:
	ldr r0, _0800D508 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0800D4E2:
	movs r1, #1
	bl Map_FindTileOverride
	adds r0, r5, #0
	adds r0, #0x48
	bl Mover_ApplyMove
	ldrh r1, [r5, #0x28]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800D50C
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	bl FUN_08234660
	b _0800D53C
	.align 2, 0
_0800D508: .4byte 0x030046A4
_0800D50C:
	ldrb r0, [r5, #3]
	cmp r0, #1
	bne _0800D530
	adds r2, r5, #0
	adds r2, #0x4a
	ldrh r0, [r2]
	ldr r1, _0800D52C @ =0x0000FFFD
	ands r1, r0
	strh r1, [r2]
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r5, r3
	bl FUN_08234660
	b _0800D53C
	.align 2, 0
_0800D52C: .4byte 0x0000FFFD
_0800D530:
	adds r2, r5, #0
	adds r2, #0x4a
	ldrh r0, [r2]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
_0800D53C:
	movs r2, #1
	ldrb r0, [r5, #2]
	ands r0, r2
	cmp r0, #0
	beq _0800D5B0
	mov r4, r8
	movs r6, #0x24
	ldrsh r0, [r4, r6]
	cmp r0, #0xf
	ble _0800D558
	ldrh r1, [r5, #0x2a]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r5, #0x2a]
_0800D558:
	ldrh r1, [r5, #0x38]
	movs r3, #0x38
	ldrsh r0, [r5, r3]
	cmp r0, #0
	ble _0800D5B0
	adds r0, r5, #0
	adds r0, #0x42
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	blt _0800D5B0
	subs r0, r1, #1
	strh r0, [r5, #0x38]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800D5B0
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r5, #2]
	ands r0, r1
	strb r0, [r5, #2]
	cmp r0, #0
	bne _0800D58A
	movs r0, #0x78
	b _0800D5AE
_0800D58A:
	movs r0, #8
	ldrb r1, [r5, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800D598
	movs r0, #0x7b
	b _0800D5AE
_0800D598:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D5A4
	movs r0, #0x7c
	b _0800D5AE
_0800D5A4:
	ands r1, r2
	movs r0, #0x7a
	cmp r1, #0
	beq _0800D5AE
	movs r0, #0x79
_0800D5AE:
	strh r0, [r5, #0x2e]
_0800D5B0:
	adds r4, r5, #0
	adds r4, #0xa8
	movs r1, #0xc
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D5C8
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	b _0800D5FC
_0800D5C8:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, r5, #0
	adds r2, #0xc4
	mov r6, sl
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r5, #0x34]
	ldrh r1, [r4, #0x1e]
	adds r0, r0, r1
	strh r0, [r4, #0x1e]
	movs r1, #1
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D5FC
	mov r2, r8
	ldrh r0, [r2, #0x20]
	ldrh r3, [r5, #0x36]
	adds r0, r0, r3
	strh r0, [r5, #0x34]
_0800D5FC:
	adds r4, r5, #0
	adds r4, #0xf0
	movs r1, #4
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D614
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	b _0800D658
_0800D614:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r6, #0x86
	lsls r6, r6, #1
	adds r2, r5, r6
	mov r3, sl
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, sb
	ldrh r6, [r0, #2]
	adds r0, r6, #0
	movs r1, #3
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0800D642
	adds r0, #4
	b _0800D64E
_0800D642:
	ldr r0, _0800D6AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800D64E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r4, #0x1e]
_0800D658:
	ldrh r0, [r5, #0x3a]
	cmp r0, #0
	beq _0800D66C
	subs r0, #1
	strh r0, [r5, #0x3a]
	strh r0, [r5, #0x3c]
	ldrh r1, [r5, #0x2a]
	movs r0, #2
	orrs r0, r1
	strh r0, [r5, #0x2a]
_0800D66C:
	movs r1, #2
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D720
	ldr r2, _0800D6B0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800D6B4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0800D6B8 @ =0x0203B400
	adds r0, r0, r1
	add r4, sp, #0x20
	ldrh r3, [r0]
	ldrh r6, [r5, #0x3c]
	ldr r2, _0800D6BC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r4, #0
	cmp r0, #0
	blt _0800D6C0
	asrs r1, r0, #0xc
	b _0800D6C6
	.align 2, 0
_0800D6AC: .4byte 0x030046A4
_0800D6B0: .4byte 0x030046B8
_0800D6B4: .4byte 0x000003FF
_0800D6B8: .4byte 0x0203B400
_0800D6BC: .4byte 0x085B0A08
_0800D6C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0800D6C6:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0800D6E2
	asrs r0, r0, #0xc
	b _0800D6E8
_0800D6E2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0800D6E8:
	strh r0, [r4, #4]
	adds r1, r5, #0
	adds r1, #0xc4
	add r0, sp, #0x20
	ldrh r4, [r0]
	ldrh r3, [r1]
	adds r0, r4, r3
	strh r0, [r1]
	ldrh r3, [r7, #2]
	ldrh r6, [r1, #2]
	adds r0, r3, r6
	strh r0, [r1, #2]
	ldrh r2, [r7, #4]
	ldrh r6, [r1, #4]
	adds r0, r2, r6
	strh r0, [r1, #4]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r6, [r0]
	adds r4, r4, r6
	strh r4, [r0]
	ldrh r1, [r0, #2]
	adds r3, r3, r1
	strh r3, [r0, #2]
	ldrh r3, [r0, #4]
	adds r2, r2, r3
	strh r2, [r0, #4]
_0800D720:
	movs r6, #0x96
	lsls r6, r6, #1
	adds r4, r5, r6
	movs r1, #0x10
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D738
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	b _0800D762
_0800D738:
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r1, r5, #0
	adds r1, #0x40
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800D75A
	subs r0, #1
	strb r0, [r1]
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	b _0800D762
_0800D75A:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
_0800D762:
	strh r0, [r4, #6]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r1, #0x20
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D7E4
	ldr r0, [r5, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800D7A8
	ldr r3, _0800D7A0 @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r1, #0x90
	orrs r0, r1
	ldr r1, _0800D7A4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x40
	b _0800D7C6
	.align 2, 0
_0800D7A0: .4byte 0xFFFF0000
_0800D7A4: .4byte 0x0000FFFF
_0800D7A8:
	ldr r3, _0800D82C @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r1, #0x40
	orrs r0, r1
	ldr r1, _0800D830 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x90
_0800D7C6:
	orrs r0, r1
	str r0, [r2, #4]
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_0800D7E4:
	adds r0, r5, #0
	adds r0, #0x45
	ldrb r0, [r0]
	ldrb r1, [r5, #3]
	cmp r0, r1
	beq _0800D7FE
	cmp r1, #0
	beq _0800D7FE
	ldr r0, _0800D834 @ =0xFFFFFDFF
	mov r2, sb
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_0800D7FE:
	adds r1, r5, #0
	adds r1, #0x41
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800D838
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800D85A
	adds r4, r5, #0
	adds r4, #0x8c
	ldrh r1, [r5, #0x2e]
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	ldrh r0, [r5, #0x2e]
	cmp r0, #0x79
	bne _0800D850
	mov r0, r8
	adds r0, #0x34
	b _0800D858
	.align 2, 0
_0800D82C: .4byte 0xFFFF0000
_0800D830: .4byte 0x0000FFFF
_0800D834: .4byte 0xFFFFFDFF
_0800D838:
	adds r4, r5, #0
	adds r4, #0x8c
	ldrh r1, [r5, #0x2e]
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	ldrh r0, [r5, #0x2e]
	cmp r0, #0x79
	bne _0800D850
	mov r0, r8
	adds r0, #0x34
	b _0800D858
_0800D850:
	cmp r0, #0x7a
	bne _0800D85A
	mov r0, r8
	adds r0, #0x54
_0800D858:
	str r0, [r4, #0xc]
_0800D85A:
	adds r2, r5, #0
	adds r2, #0x46
	ldrb r3, [r5, #2]
	ldrb r1, [r2]
	cmp r3, r1
	beq _0800D8AC
	ldr r6, [r5, #8]
	cmp r6, #0
	beq _0800D8AC
	mov r4, sl
	ldrh r0, [r4]
	str r0, [sp]
	ldrb r0, [r5, #2]
	str r0, [sp, #4]
	bics r0, r1
	str r0, [sp, #8]
	ldrb r0, [r2]
	bics r0, r3
	str r0, [sp, #0xc]
	add r4, sp, #0x30
	adds r3, r5, #0
	adds r3, #0xc
	add r2, sp, #0x10
	movs r1, #3
_0800D88A:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _0800D88A
	ldr r0, _0800D8C4 @ =0xFFFF0000
	ldr r1, [sp, #0x30]
	ands r1, r0
	movs r0, #8
	orrs r1, r0
	str r1, [sp, #0x30]
	mov r0, sp
	str r0, [r4, #4]
	adds r0, r6, #0
	adds r1, r4, #0
	bl VM_ExecByID
_0800D8AC:
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D8C4: .4byte 0xFFFF0000
