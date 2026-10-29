	push {r4, r5, r6, lr}
	ldr r0, _08086CB4 @ =0x03002C00
	ldr r5, [r0]
	cmp r5, #0
	bne _08086C5C
	b _08086D56
_08086C5C:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08086D40
	bl VM_GetValue
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r4, r5, r1
	strh r0, [r4]
	bl VM_GetValue
	movs r2, #0xfd
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	bl VM_GetValue
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	adds r6, r4, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08086CB0
	cmp r1, #0
	blt _08086CB0
	ldr r0, _08086CB8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08086CB0
	ldr r0, _08086CBC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08086CC0
_08086CB0:
	movs r4, #0
	b _08086CCE
	.align 2, 0
_08086CB4: .4byte 0x03002C00
_08086CB8: .4byte 0x030046A8
_08086CBC: .4byte 0x030046AC
_08086CC0:
	ldr r0, _08086CE0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08086CCE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08086CE4
	adds r0, #4
	b _08086CF0
	.align 2, 0
_08086CE0: .4byte 0x030046A4
_08086CE4:
	ldr r0, _08086D04 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08086CF0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08086D08
	cmp r2, #2
	beq _08086D0C
	b _08086D10
	.align 2, 0
_08086D04: .4byte 0x030046A4
_08086D08:
	ldrb r0, [r6, #4]
	b _08086D0E
_08086D0C:
	ldrb r0, [r6]
_08086D0E:
	subs r1, r1, r0
_08086D10:
	movs r2, #0xfd
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x48]
	str r1, [r5, #0x4c]
	adds r3, r5, #0
	adds r3, #0xa0
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r3, r5, r1
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
_08086D40:
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08086D56
	bl VM_GetValue
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
_08086D56:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
