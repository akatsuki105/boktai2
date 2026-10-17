	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _080CF1CC @ =0x0000CB05
	ldr r1, _080CF1D0 @ =0x0000DE23
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _080CF23E
	adds r1, r6, #0
	adds r1, #0x68
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r6, #0
	adds r4, #0x68
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	adds r5, r6, #0
	adds r5, #0x88
	movs r3, #0x90
	lsls r3, r3, #8
	movs r0, #2
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x2c
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_Add
	movs r0, #0x64
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	adds r7, r4, #0
	cmp r1, #0
	beq _080CF1D8
	bl VM_GetValue
	ldr r2, _080CF1D4 @ =0x00000454
	adds r1, r6, r2
	strb r0, [r1]
	b _080CF1DE
	.align 2, 0
_080CF1CC: .4byte 0x0000CB05
_080CF1D0: .4byte 0x0000DE23
_080CF1D4: .4byte 0x00000454
_080CF1D8:
	ldr r3, _080CF224 @ =0x00000454
	adds r0, r6, r3
	strb r1, [r0]
_080CF1DE:
	ldr r4, _080CF224 @ =0x00000454
	adds r0, r6, r4
	ldrb r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r6, r2
	movs r4, #0
	strb r1, [r0]
	adds r0, r6, #0
	bl PlayerLink_SetAnimFacing
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r4, [r0]
	ldr r1, _080CF228 @ =0x000002E6
	adds r0, r6, r1
	ldrb r2, [r0]
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r2, _080CF22C @ =0x000002E7
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CF230
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _080CF23C
	.align 2, 0
_080CF224: .4byte 0x00000454
_080CF228: .4byte 0x000002E6
_080CF22C: .4byte 0x000002E7
_080CF230:
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_080CF23C:
	str r1, [r0]
_080CF23E:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
