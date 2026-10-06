	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A6A88
	bl VM_GetValue
	b _080A6A8A
_080A6A88:
	movs r0, #0
_080A6A8A:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl FindZonesByID
	adds r5, r0, #0
	cmp r5, #0
	beq _080A6B80
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r1, r1, r0
	lsls r1, r1, #0xf
	lsrs r1, r1, #0x10
	ldr r3, _080A6AF8 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	movs r0, #2
	ldrsh r1, [r5, r0]
	movs r2, #6
	ldrsh r0, [r5, r2]
	adds r1, r1, r0
	lsls r1, r1, #0xf
	lsrs r1, r1, #0x10
	add r2, sp, #4
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	adds r6, r2, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r7, r6, #0
	cmp r2, #0
	blt _080A6AF2
	cmp r1, #0
	blt _080A6AF2
	ldr r0, _080A6AFC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A6AF2
	ldr r0, _080A6B00 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A6B04
_080A6AF2:
	movs r4, #0
	b _080A6B12
	.align 2, 0
_080A6AF8: .4byte 0xFFFF0000
_080A6AFC: .4byte 0x030046A8
_080A6B00: .4byte 0x030046AC
_080A6B04:
	ldr r0, _080A6B24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A6B12:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080A6B28
	adds r0, #4
	b _080A6B34
	.align 2, 0
_080A6B24: .4byte 0x030046A4
_080A6B28:
	ldr r0, _080A6B48 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A6B34:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A6B4C
	cmp r2, #2
	beq _080A6B50
	b _080A6B54
	.align 2, 0
_080A6B48: .4byte 0x030046A4
_080A6B4C:
	ldrb r0, [r6, #4]
	b _080A6B52
_080A6B50:
	ldrb r0, [r6]
_080A6B52:
	subs r1, r1, r0
_080A6B54:
	strh r1, [r7, #2]
	adds r0, r5, #0
	bl FUN_080a64cc
	adds r4, r0, #0
	cmp r4, #0
	blt _080A6B80
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A6B74
	bl VM_GetValue
	adds r2, r0, #0
	b _080A6B76
_080A6B74:
	movs r2, #0
_080A6B76:
	adds r0, r7, #0
	adds r1, r4, #0
	movs r3, #0
	bl Map_AddLoadingZoneIndicator
_080A6B80:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
