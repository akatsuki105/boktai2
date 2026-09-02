	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08070866
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0807086A
_08070866:
	movs r7, #0x30
	b _0807086C
_0807086A:
	movs r7, #0x40
_0807086C:
	ldr r1, _08070884 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #6
	bls _08070878
	b _08070AD4
_08070878:
	lsls r0, r0, #2
	ldr r1, _08070888 @ =_0807088C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08070884: .4byte 0x0000037D
_08070888: .4byte _0807088C
_0807088C: @ jump table
	.4byte _080708A8 @ case 0
	.4byte _080708D8 @ case 1
	.4byte _08070AD4 @ case 2
	.4byte _08070AD4 @ case 3
	.4byte _08070940 @ case 4
	.4byte _08070A14 @ case 5
	.4byte _08070A68 @ case 6
_080708A8:
	adds r0, r5, #0
	bl FUN_0806f780
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x18
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_08060a24
	cmp r0, #0
	bne _080708CC
	b _08070AD4
_080708CC:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08060b84
	b _08070AD4
_080708D8:
	adds r0, r5, #0
	bl FUN_0806f780
	adds r0, r5, #0
	bl FUN_0806f738
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x19
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _0807092C @ =0x0000037E
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #6
	bls _08070930
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08070930
	adds r0, r5, #0
	bl FUN_080701e0
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_08060b84
	b _08070AD4
	.align 2, 0
_0807092C: .4byte 0x0000037E
_08070930:
	ldr r2, _0807093C @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08070AD4
	.align 2, 0
_0807093C: .4byte 0x0000037E
_08070940:
	ldr r0, _0807099C @ =0x000003D1
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r4, r5, r1
	ldrb r0, [r4]
	ldr r2, _080709A0 @ =0x00000A82
	adds r6, r5, r2
	ldrh r1, [r6]
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_08060a24
	ldrb r0, [r4]
	cmp r0, #1
	bne _080709FE
	ldrh r0, [r6]
	cmp r0, #0x1c
	bne _080709A4
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #1
	bne _080709FE
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080709FE
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #0
	bl Player_DarkDjangoSpear_08061970
	b _080709FE
	.align 2, 0
_0807099C: .4byte 0x000003D1
_080709A0: .4byte 0x00000A82
_080709A4:
	cmp r0, #0x1b
	bne _080709D2
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #1
	bne _080709FE
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080709FE
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #1
	bl Player_DarkDjangoSpear_08061970
	b _080709FE
_080709D2:
	cmp r0, #0x1a
	bne _080709FE
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080709FE
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #1
	bne _080709FE
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #2
	bl Player_DarkDjangoSpear_08061970
_080709FE:
	adds r0, r5, #0
	bl FUN_08070604
	cmp r0, #0
	beq _08070AD4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08060b84
	b _08070AD4
_08070A14:
	ldr r2, _08070A60 @ =0x000003D1
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08070A36
	ldr r2, _08070A64 @ =0x00000A76
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_08070A36:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x18
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_08060a24
	cmp r0, #0
	beq _08070AD4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_08060b84
	b _08070AD4
	.align 2, 0
_08070A60: .4byte 0x000003D1
_08070A64: .4byte 0x00000A76
_08070A68:
	ldr r2, _08070AA0 @ =0x000003D1
	adds r0, r5, r2
	movs r2, #0
	strb r2, [r0]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08070A8A
	ldr r0, _08070AA4 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08070A8A:
	ldr r1, _08070AA4 @ =0x00000A76
	adds r4, r5, r1
	ldrb r6, [r4]
	cmp r6, #0
	beq _08070AAC
	strb r2, [r4]
	ldr r1, _08070AA8 @ =0x0000037D
	adds r0, r5, r1
	strb r2, [r0]
	b _08070AD4
	.align 2, 0
_08070AA0: .4byte 0x000003D1
_08070AA4: .4byte 0x00000A76
_08070AA8: .4byte 0x0000037D
_08070AAC:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x19
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_08060a24
	cmp r0, #0
	beq _08070AD4
	strb r6, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08070AD4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
