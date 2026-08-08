	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r1, #0
	adds r7, r2, #0
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080E3CF6
	cmp r1, #0
	blt _080E3CF6
	ldr r0, _080E3CFC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080E3CF6
	ldr r0, _080E3D00 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080E3D04
_080E3CF6:
	movs r6, #0
	b _080E3D12
	.align 2, 0
_080E3CFC: .4byte 0x030046A8
_080E3D00: .4byte 0x030046AC
_080E3D04:
	ldr r0, _080E3D24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080E3D12:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E3D28
	adds r0, #4
	b _080E3D34
	.align 2, 0
_080E3D24: .4byte 0x030046A4
_080E3D28:
	ldr r0, _080E3D50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E3D34:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r8, r0
	adds r4, r6, #0
	cmp r5, #1
	beq _080E3DAC
	cmp r5, #1
	bgt _080E3D54
	cmp r5, #0
	beq _080E3D60
	b _080E3ECC
	.align 2, 0
_080E3D50: .4byte 0x030046A4
_080E3D54:
	cmp r5, #2
	beq _080E3E08
	cmp r5, #3
	bne _080E3D5E
	b _080E3E50
_080E3D5E:
	b _080E3ECC
_080E3D60:
	movs r5, #0
	cmp r5, r7
	bge _080E3DA0
	lsls r0, r6, #2
	adds r6, r0, #0
	adds r6, #0xc
_080E3D6C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E3D7C
	adds r0, #4
	b _080E3D84
_080E3D7C:
	ldr r0, _080E3DA8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_080E3D84:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	subs r0, r1, r0
	cmp r0, #0
	bge _080E3D96
	b _080E3EAC
_080E3D96:
	adds r6, #4
	adds r4, #1
	adds r5, #1
	cmp r5, r7
	blt _080E3D6C
_080E3DA0:
	subs r4, #1
	adds r0, r4, #0
	b _080E3ECE
	.align 2, 0
_080E3DA8: .4byte 0x030046A4
_080E3DAC:
	movs r5, #0
	cmp r5, r7
	bge _080E3DF4
	ldr r6, _080E3DC4 @ =0x030046A4
_080E3DB4:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E3DC8
	adds r0, #4
	b _080E3DD2
	.align 2, 0
_080E3DC4: .4byte 0x030046A4
_080E3DC8:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E3DD2:
	ldr r2, _080E3E04 @ =0x030046A4
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	subs r0, r1, r0
	cmp r0, #0
	blt _080E3EB0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, r7
	blt _080E3DB4
_080E3DF4:
	ldr r0, _080E3E04 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r0, r4, #0
	b _080E3ECE
	.align 2, 0
_080E3E04: .4byte 0x030046A4
_080E3E08:
	movs r5, #0
	cmp r5, r7
	bge _080E3E46
	lsls r0, r6, #2
	adds r6, r0, #0
	adds r6, #0xc
_080E3E14:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E3E24
	adds r0, #4
	b _080E3E2C
_080E3E24:
	ldr r0, _080E3E4C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_080E3E2C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	subs r0, r1, r0
	cmp r0, #0
	blt _080E3EBC
	subs r6, #4
	subs r4, #1
	adds r5, #1
	cmp r5, r7
	blt _080E3E14
_080E3E46:
	adds r4, #1
	adds r0, r4, #0
	b _080E3ECE
	.align 2, 0
_080E3E4C: .4byte 0x030046A4
_080E3E50:
	movs r5, #0
	cmp r5, r7
	bge _080E3E98
	ldr r6, _080E3E68 @ =0x030046A4
_080E3E58:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E3E6C
	adds r0, #4
	b _080E3E76
	.align 2, 0
_080E3E68: .4byte 0x030046A4
_080E3E6C:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_080E3E76:
	ldr r2, _080E3EA8 @ =0x030046A4
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	subs r0, r1, r0
	cmp r0, #0
	blt _080E3EC0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, r7
	blt _080E3E58
_080E3E98:
	ldr r0, _080E3EA8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r0, r4, #0
	b _080E3ECE
	.align 2, 0
_080E3EA8: .4byte 0x030046A4
_080E3EAC:
	subs r0, r4, #1
	b _080E3ECE
_080E3EB0:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r0, r4, r0
	b _080E3ECE
_080E3EBC:
	adds r0, r4, #1
	b _080E3ECE
_080E3EC0:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r0, r4, r0
	b _080E3ECE
_080E3ECC:
	adds r0, r6, #0
_080E3ECE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
