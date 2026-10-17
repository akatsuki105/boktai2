	push {r4, r5, r6, lr}
	sub sp, #0x38
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D3F38
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0
	bl PlayerLink_SetAction
_080D3F38:
	ldr r2, _080D3F50 @ =0x0000037D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #8
	bls _080D3F44
	b _080D4462
_080D3F44:
	lsls r0, r0, #2
	ldr r1, _080D3F54 @ =_080D3F58
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D3F50: .4byte 0x0000037D
_080D3F54: .4byte _080D3F58
_080D3F58: @ jump table
	.4byte _080D3F7C @ case 0
	.4byte _080D3FA6 @ case 1
	.4byte _080D405E @ case 2
	.4byte _080D4462 @ case 3
	.4byte _080D410C @ case 4
	.4byte _080D419C @ case 5
	.4byte _080D41F8 @ case 6
	.4byte _080D4274 @ case 7
	.4byte _080D42B0 @ case 8
_080D3F7C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	cmp r0, #0
	bne _080D3F9A
	b _080D4462
_080D3F9A:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl PlayerLink_SetAction
	b _080D4462
_080D3FA6:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r0, _080D3FF4 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bhi _080D3FD8
	b _080D4462
_080D3FD8:
	ldr r2, _080D3FF8 @ =0x00000A8F
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #9
	bhi _080D3FFC
	ldr r0, [r5, #0x18]
	movs r1, #0xd5
	b _080D40A6
	.align 2, 0
_080D3FF4: .4byte 0x0000037E
_080D3FF8: .4byte 0x00000A8F
_080D3FFC:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D4028
	ldr r0, [r5, #0x18]
	ldr r1, _080D4024 @ =0x00000203
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl PlayerLink_SetAction
	b _080D4032
	.align 2, 0
_080D4024: .4byte 0x00000203
_080D4028:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	bl PlayerLink_SetAction
_080D4032:
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x32
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	movs r0, #0x1e
	str r0, [sp, #0x10]
	movs r0, #5
	str r0, [sp, #0x14]
	movs r0, #0xa
	str r0, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #0xe6
	movs r2, #0xaa
	movs r3, #0
	bl Entity08080be8_Create
	b _080D4462
_080D405E:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r2, _080D40B8 @ =0x0000037E
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #6
	bne _080D4090
	ldr r0, [r5, #0x18]
	movs r1, #0xfc
	lsls r1, r1, #1
	bl Sound_PlayForPlayer
_080D4090:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D40C0
	ldr r0, [r5, #0x18]
	ldr r1, _080D40BC @ =0x00000203
_080D40A6:
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl PlayerLink_SetAction
	b _080D4462
	.align 2, 0
_080D40B8: .4byte 0x0000037E
_080D40BC: .4byte 0x00000203
_080D40C0:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _080D40D0
	b _080D4462
_080D40D0:
	ldr r2, _080D4100 @ =0x00000A8F
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080D4104 @ =0x0000095E
	adds r1, r5, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x24
	strh r0, [r1]
	ldr r0, [r5, #0x18]
	ldr r1, _080D4108 @ =0x000001F9
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl PlayerLink_SetAction
	b _080D4462
	.align 2, 0
_080D4100: .4byte 0x00000A8F
_080D4104: .4byte 0x0000095E
_080D4108: .4byte 0x000001F9
_080D410C:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080D4140
	b _080D4462
_080D4140:
	ldr r0, [r5, #0x18]
	ldr r1, _080D4190 @ =0x000002E9
	bl Sound_PlayForPlayer
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r2, _080D4194 @ =0x00000A8A
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080d1b04
	adds r1, r0, #0
	movs r2, #0xa1
	lsls r2, r2, #4
	adds r0, r5, r2
	str r4, [sp]
	movs r2, #0x1e
	str r2, [sp, #4]
	movs r2, #0x20
	movs r3, #0x10
	bl Hitbox_SetAttack
	ldr r0, [r5, #0x18]
	ldr r1, _080D4198 @ =0x00000202
	bl Sound_PlayForPlayer
	adds r0, r5, #0
	movs r1, #3
	movs r2, #8
	bl PlayerLink_SetAction
	b _080D4462
	.align 2, 0
_080D4190: .4byte 0x000002E9
_080D4194: .4byte 0x00000A8A
_080D4198: .4byte 0x00000202
_080D419C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x25
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D41CE
	ldr r0, _080D41F0 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D41CE:
	ldr r2, _080D41F4 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _080D41E2
	b _080D4462
_080D41E2:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl PlayerLink_SetAction
	b _080D4462
	.align 2, 0
_080D41F0: .4byte 0x00000A76
_080D41F4: .4byte 0x0000037E
_080D41F8:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D422A
	ldr r0, _080D4244 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D422A:
	ldr r1, _080D4244 @ =0x00000A76
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D424C
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080D4248 @ =0x0000037D
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _080D4462
	.align 2, 0
_080D4244: .4byte 0x00000A76
_080D4248: .4byte 0x0000037D
_080D424C:
	ldr r0, _080D4270 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _080D4260
	b _080D4462
_080D4260:
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #7
	bl PlayerLink_SetAction
	b _080D4462
	.align 2, 0
_080D4270: .4byte 0x0000037E
_080D4274:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r2, _080D42AC @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _080D42A0
	b _080D4462
_080D42A0:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
	b _080D4462
	.align 2, 0
_080D42AC: .4byte 0x0000037E
_080D42B0:
	ldr r1, _080D4358 @ =0x000003D1
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_080d19fc
	cmp r0, #0
	beq _080D42CA
	adds r0, r5, #0
	movs r1, #6
	bl FUN_080cc268
_080D42CA:
	ldr r2, _080D435C @ =0x0000037E
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r3, #3
	ands r3, r0
	adds r6, r5, #0
	adds r6, #0x2c
	cmp r3, #0
	bne _080D4310
	ldr r1, _080D4360 @ =0xFFFF0000
	ldr r2, _080D4364 @ =0x0000FFFF
	str r3, [sp, #0x20]
	ldr r0, [sp, #0x24]
	ands r0, r1
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r1
	movs r3, #0x20
	orrs r0, r3
	ands r0, r2
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r1
	orrs r0, r3
	str r0, [r2, #4]
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	add r1, sp, #0x20
	movs r3, #1
	bl FUN_080dbcec
_080D4310:
	ldr r0, _080D4368 @ =0x00000A8A
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4]
	ldrh r1, [r4]
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_080cce0c
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	ldrh r1, [r4]
	movs r0, #0xd0
	lsls r0, r0, #1
	subs r6, r0, r1
	movs r1, #0xff
	ands r6, r1
	ldr r2, _080D436C @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4370
	asrs r1, r0, #0xc
	b _080D4376
	.align 2, 0
_080D4358: .4byte 0x000003D1
_080D435C: .4byte 0x0000037E
_080D4360: .4byte 0xFFFF0000
_080D4364: .4byte 0x0000FFFF
_080D4368: .4byte 0x00000A8A
_080D436C: .4byte gSineTable
_080D4370:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D4376:
	add r3, sp, #0x30
	ldrh r0, [r3]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D43AC @ =0xFFFF0000
	ldr r2, [sp, #0x30]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0xe6
	lsls r1, r1, #0x10
	ldr r0, _080D43B0 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x30]
	ldr r1, _080D43B4 @ =gSineTable
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _080D43B8
	asrs r0, r0, #0xc
	b _080D43BE
	.align 2, 0
_080D43AC: .4byte 0xFFFF0000
_080D43B0: .4byte 0x0000FFFF
_080D43B4: .4byte gSineTable
_080D43B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D43BE:
	ldrh r1, [r3, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D4474 @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _080D4478 @ =0x00000A52
	adds r0, r5, r1
	strb r6, [r0]
	adds r0, r4, #0
	bl Hitbox_Register
	ldr r2, _080D447C @ =0x00000A8A
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r0, _080D4480 @ =0x0000010F
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r5, #0
	bl PlayerLink_SetAnimFacing
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x25
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	ldr r2, _080D4484 @ =0x0000037E
	adds r4, r5, r2
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _080D443A
	ldr r0, [r5, #0x18]
	movs r1, #0x81
	lsls r1, r1, #2
	bl Sound_PlayForPlayer
_080D443A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080D4488 @ =0x00000A8F
	adds r1, r5, r2
	ldrb r1, [r1]
	lsls r1, r1, #5
	cmp r0, r1
	blt _080D4462
	ldr r0, [r5, #0x18]
	ldr r1, _080D448C @ =0x00000202
	bl FUN_080cc410
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl PlayerLink_SetAction
_080D4462:
	ldr r0, _080D4490 @ =0x00000951
	adds r1, r5, r0
	movs r0, #9
	strb r0, [r1]
	add sp, #0x38
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D4474: .4byte 0xFFFF0000
_080D4478: .4byte 0x00000A52
_080D447C: .4byte 0x00000A8A
_080D4480: .4byte 0x0000010F
_080D4484: .4byte 0x0000037E
_080D4488: .4byte 0x00000A8F
_080D448C: .4byte 0x00000202
_080D4490: .4byte 0x00000951
