	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A2350
	bl VM_GetValue
	adds r4, r7, #0
	adds r4, #0xac
	strh r0, [r4]
	bl VM_GetValue
	adds r5, r7, #0
	adds r5, #0xae
	strh r0, [r5]
	bl VM_GetValue
	adds r1, r7, #0
	adds r1, #0xb0
	strh r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sl, r4
	cmp r2, #0
	blt _080A22F0
	cmp r1, #0
	blt _080A22F0
	ldr r0, _080A22F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A22F0
	ldr r0, _080A22F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A22FC
_080A22F0:
	movs r6, #0
	b _080A230A
	.align 2, 0
_080A22F4: .4byte 0x030046A8
_080A22F8: .4byte 0x030046AC
_080A22FC:
	ldr r0, _080A231C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080A230A:
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080A2320
	adds r0, #4
	b _080A232C
	.align 2, 0
_080A231C: .4byte 0x030046A4
_080A2320:
	ldr r0, _080A2340 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A232C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A2344
	cmp r2, #2
	beq _080A2348
	b _080A234C
	.align 2, 0
_080A2340: .4byte 0x030046A4
_080A2344:
	ldrb r0, [r4, #4]
	b _080A234A
_080A2348:
	ldrb r0, [r4]
_080A234A:
	subs r1, r1, r0
_080A234C:
	strh r1, [r5]
	b _080A2362
_080A2350:
	adds r1, r7, #0
	adds r1, #0xac
	strh r2, [r1]
	adds r0, r7, #0
	adds r0, #0xae
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	mov sl, r1
_080A2362:
	adds r4, r7, #0
	adds r4, #0x44
	ldr r0, _080A2428 @ =0x00000BA8
	mov sb, r0
	adds r0, r4, #0
	mov r1, sb
	bl Video_GetAuxSprite
	adds r5, r7, #0
	adds r5, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r6, #6
	strh r6, [r5, #0x10]
	adds r0, r4, #0
	movs r1, #0x63
	bl Video_SetAuxSpritePltt
	ldr r0, [r7, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r7, #0x18]
	movs r1, #3
	mov r8, r1
	mov r2, r8
	strb r2, [r7, #0x1f]
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldrh r0, [r7, #0x36]
	adds r0, #0x1e
	strh r0, [r7, #0x36]
	adds r4, #0x48
	adds r0, r4, #0
	mov r1, sb
	bl Video_GetAuxSprite
	adds r5, #0x48
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	strh r6, [r5, #0x10]
	adds r0, r4, #0
	movs r1, #0x61
	bl Video_SetAuxSpritePltt
	ldr r0, [r7, #0x60]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r7, #0x60]
	adds r0, r7, #0
	adds r0, #0x67
	mov r1, r8
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0x7c
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl FUN_080a21fc
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A2430
	bl VM_GetValue
	cmp r0, #0
	beq _080A2430
	ldr r0, [r7, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x18]
	ldr r0, [r7, #0x60]
	orrs r0, r1
	str r0, [r7, #0x60]
	adds r1, r7, #0
	adds r1, #0xb4
	ldr r0, _080A242C @ =FUN_080a2114
	str r0, [r1]
	movs r0, #0xaf
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080A2438
	.align 2, 0
_080A2428: .4byte 0x00000BA8
_080A242C: .4byte FUN_080a2114
_080A2430:
	adds r1, r7, #0
	adds r1, #0xb4
	ldr r0, _080A2458 @ =FUN_080a1fc4
	str r0, [r1]
_080A2438:
	adds r1, r7, #0
	adds r1, #0xaa
	movs r0, #0
	strh r0, [r1]
	adds r0, r7, #0
	bl IsCoffinInside
	adds r1, r0, #0
	cmp r1, #0
	beq _080A245C
	adds r1, r7, #0
	adds r1, #0xa8
	movs r0, #1
	strh r0, [r1]
	adds r4, r1, #0
	b _080A2464
	.align 2, 0
_080A2458: .4byte FUN_080a1fc4
_080A245C:
	adds r0, r7, #0
	adds r0, #0xa8
	strh r1, [r0]
	adds r4, r0, #0
_080A2464:
	movs r0, #0x69
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A247E
	bl VM_GetValue
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A2486
_080A247E:
	movs r3, #0x98
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A2486:
	movs r0, #0x6f
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A24A0
	bl VM_GetValue
	movs r2, #0x99
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A24A8
_080A24A0:
	movs r3, #0x99
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A24A8:
	adds r0, r7, #0
	bl IsCoffinInside
	cmp r0, #0
	beq _080A24BC
	movs r0, #1
	strh r0, [r4]
	bl Coffin_SetInsideSolarCircle
	b _080A24C4
_080A24BC:
	strh r0, [r4]
	movs r0, #0
	bl Coffin_SetInsideSolarCircle
_080A24C4:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
