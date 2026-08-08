	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xa
	beq _0806B98A
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08064d54
	adds r1, r0, #0
	cmp r1, #0
	beq _0806B974
	ldr r2, _0806B968 @ =0x0000095E
	adds r1, r4, r2
	movs r2, #0
	ldr r0, _0806B96C @ =0x00000127
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r0, r4, r3
	strh r2, [r0]
	ldr r0, _0806B970 @ =0x000003FA
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0806B97A
	.align 2, 0
_0806B968: .4byte 0x0000095E
_0806B96C: .4byte 0x00000127
_0806B970: .4byte 0x000003FA
_0806B974:
	ldr r2, _0806B9A0 @ =0x000003FA
	adds r0, r4, r2
	strb r1, [r0]
_0806B97A:
	ldr r0, _0806B9A4 @ =0x00000306
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0
	bl FUN_08060b84
_0806B98A:
	ldr r3, _0806B9A8 @ =0x0000037D
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #4
	bls _0806B996
	b _0806BC6A
_0806B996:
	lsls r0, r0, #2
	ldr r1, _0806B9AC @ =_0806B9B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806B9A0: .4byte 0x000003FA
_0806B9A4: .4byte 0x00000306
_0806B9A8: .4byte 0x0000037D
_0806B9AC: .4byte _0806B9B0
_0806B9B0: @ jump table
	.4byte _0806B9C4 @ case 0
	.4byte _0806BA90 @ case 1
	.4byte _0806BB00 @ case 2
	.4byte _0806BBE0 @ case 3
	.4byte _0806BC34 @ case 4
_0806B9C4:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r3, r4, r0
	ldrb r0, [r3]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _0806B9F4
	movs r2, #0
	movs r1, #4
	strb r1, [r3]
	ldr r3, _0806B9EC @ =0x000002E6
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _0806B9F0 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	b _0806BA04
	.align 2, 0
_0806B9EC: .4byte 0x000002E6
_0806B9F0: .4byte 0x000002E7
_0806B9F4:
	movs r0, #0
	strb r0, [r3]
	ldr r2, _0806BA58 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _0806BA5C @ =0x000002E7
	adds r1, r4, r3
	strb r0, [r1]
_0806BA04:
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrb r0, [r5]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0806BA58 @ =0x000002E6
	adds r1, r4, r2
	ldrb r0, [r1]
	lsrs r0, r0, #2
	strb r0, [r1]
	ldr r3, _0806BA60 @ =0x000003FA
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806BA7E
	ldr r1, _0806BA64 @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #0xf
	orrs r0, r1
	str r0, [sp, #8]
	ldrb r0, [r5]
	cmp r0, #0
	bne _0806BA68
	movs r0, #0x45
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #7
	add r2, sp, #4
	movs r3, #0x32
	bl FUN_080ac374
	b _0806BA78
	.align 2, 0
_0806BA58: .4byte 0x000002E6
_0806BA5C: .4byte 0x000002E7
_0806BA60: .4byte 0x000003FA
_0806BA64: .4byte 0xFFFF0000
_0806BA68:
	movs r0, #0x45
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #7
	add r2, sp, #4
	movs r3, #0x32
	bl FUN_080ac374
_0806BA78:
	ldr r0, _0806BA8C @ =0x0000039B
	bl PlaySound_082406e0
_0806BA7E:
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #1
	bl FUN_08060b84
	b _0806BC6A
	.align 2, 0
_0806BA8C: .4byte 0x0000039B
_0806BA90:
	ldr r1, _0806BAF0 @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806BAB2
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _0806BAB2
	movs r0, #0x20
	strh r0, [r1]
_0806BAB2:
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r1, r4, r3
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _0806BADA
	b _0806BC6A
_0806BADA:
	ldr r2, _0806BAF0 @ =0x000003FA
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806BAF4
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #2
	bl FUN_08060b84
	b _0806BC6A
	.align 2, 0
_0806BAF0: .4byte 0x000003FA
_0806BAF4:
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #3
	bl FUN_08060b84
	b _0806BC6A
_0806BB00:
	ldr r3, _0806BB20 @ =0x0000037E
	adds r0, r4, r3
	ldrh r0, [r0]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #2
	subs r1, r1, r0
	cmp r2, r1
	bge _0806BB24
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	b _0806BB32
	.align 2, 0
_0806BB20: .4byte 0x0000037E
_0806BB24:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806BB44
	movs r0, #1
_0806BB32:
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _0806BB56
_0806BB44:
	movs r0, #0
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
_0806BB56:
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r3, _0806BB9C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _0806BB72
	movs r0, #0x20
	strh r0, [r1]
_0806BB72:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	ldr r3, _0806BBA0 @ =0x0000037E
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ands r0, r2
	cmp r0, #0x1f
	bls _0806BC6A
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _0806BBA4
	movs r0, #1
	b _0806BBA6
	.align 2, 0
_0806BB9C: .4byte 0x0000FFFF
_0806BBA0: .4byte 0x0000037E
_0806BBA4:
	movs r0, #0
_0806BBA6:
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_08062c3c
	ldr r1, _0806BBD0 @ =0x0000094C
	adds r0, r4, r1
	ldr r1, _0806BBD4 @ =0x0000FFFF
	strh r1, [r0]
	ldr r2, _0806BBD8 @ =0x00000444
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #5
	beq _0806BC22
	cmp r0, #0x22
	beq _0806BC22
	ldr r3, _0806BBDC @ =0x00000446
	adds r1, r4, r3
	movs r0, #0
	strh r0, [r1]
	b _0806BC22
	.align 2, 0
_0806BBD0: .4byte 0x0000094C
_0806BBD4: .4byte 0x0000FFFF
_0806BBD8: .4byte 0x00000444
_0806BBDC: .4byte 0x00000446
_0806BBE0:
	ldr r0, _0806BC30 @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _0806BBF2
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0806BBF2:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0806BC6A
_0806BC22:
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #4
	bl FUN_08060b84
	b _0806BC6A
	.align 2, 0
_0806BC30: .4byte 0x0000037E
_0806BC34:
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r1, r4, r3
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0806BC6A
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_0806BC6A:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
