	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r7, r1, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1CA0
	bl VM_GetValue
	asrs r0, r0, #8
	lsls r0, r0, #8
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080A1C98 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080A1C9C @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl VM_GetValue
	asrs r0, r0, #8
	lsls r0, r0, #8
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _080A1CAA
	.align 2, 0
_080A1C98: .4byte 0xFFFF0000
_080A1C9C: .4byte 0x0000FFFF
_080A1CA0:
	ldr r1, _080A1CD8 @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_080A1CAA:
	add r6, sp, #8
	adds r0, r6, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A1CD2
	cmp r1, #0
	blt _080A1CD2
	ldr r0, _080A1CDC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A1CD2
	ldr r0, _080A1CE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A1CE4
_080A1CD2:
	movs r4, #0
	b _080A1CF2
	.align 2, 0
_080A1CD8: .4byte 0xFFFF0000
_080A1CDC: .4byte 0x030046A8
_080A1CE0: .4byte 0x030046AC
_080A1CE4:
	ldr r0, _080A1D04 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A1CF2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080A1D08
	adds r0, #4
	b _080A1D14
	.align 2, 0
_080A1D04: .4byte 0x030046A4
_080A1D08:
	ldr r0, _080A1D28 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A1D14:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080A1D2C
	cmp r3, #2
	beq _080A1D30
	b _080A1D34
	.align 2, 0
_080A1D28: .4byte 0x030046A4
_080A1D2C:
	ldrb r0, [r6, #4]
	b _080A1D32
_080A1D30:
	ldrb r0, [r6]
_080A1D32:
	subs r2, r2, r0
_080A1D34:
	add r1, sp, #8
	strh r2, [r1, #2]
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A1D5E
	cmp r1, #0
	blt _080A1D5E
	ldr r0, _080A1D64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A1D5E
	ldr r0, _080A1D68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A1D6C
_080A1D5E:
	movs r0, #0
	b _080A1D7A
	.align 2, 0
_080A1D64: .4byte 0x030046A8
_080A1D68: .4byte 0x030046AC
_080A1D6C:
	ldr r0, _080A1DD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A1D7A:
	adds r1, r5, #0
	adds r1, #0xc2
	strh r0, [r1]
	add r0, sp, #8
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #1
	adds r2, r5, #0
	adds r2, #0xc1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xb0
	ldrh r1, [r1]
	ldrb r3, [r2]
	movs r2, #0xff
	str r2, [sp]
	adds r2, #4
	str r2, [sp, #4]
	movs r2, #0
	bl Map_AddTileOverride
	adds r0, r5, #0
	add r1, sp, #8
	bl Entity3DB0_InitSprite
	adds r0, r5, #0
	adds r1, r7, #0
	add r2, sp, #8
	bl Entity3DB0_InitHitbox
	movs r0, #0x52
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A1DD4
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xc8
	str r0, [r1]
	b _080A1DDA
	.align 2, 0
_080A1DD0: .4byte 0x030046A4
_080A1DD4:
	adds r0, r5, #0
	adds r0, #0xc8
	str r1, [r0]
_080A1DDA:
	movs r0, #0
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
