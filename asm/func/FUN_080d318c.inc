	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D31AE
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D31B2
_080D31AE:
	movs r5, #0x30
	b _080D31B4
_080D31B2:
	movs r5, #0x40
_080D31B4:
	ldr r1, _080D31C8 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D31FC
	cmp r0, #1
	bgt _080D31CC
	cmp r0, #0
	beq _080D31D6
	b _080D3330
	.align 2, 0
_080D31C8: .4byte 0x0000037D
_080D31CC:
	cmp r0, #4
	beq _080D3254
	cmp r0, #5
	beq _080D3290
	b _080D3330
_080D31D6:
	adds r0, r4, #0
	bl FUN_080d1a44
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x1d
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl PlayerLink_PlayAnim
	cmp r0, #0
	bne _080D31FA
	b _080D3330
_080D31FA:
	b _080D330E
_080D31FC:
	adds r0, r4, #0
	bl FUN_080d1a44
	adds r0, r4, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x1e
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl PlayerLink_PlayAnim
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D3244
	adds r0, r4, #0
	bl FUN_080d2c00
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
	bl PlayerLink_SetAction
	b _080D3330
_080D3244:
	ldr r0, _080D3250 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080D3330
	.align 2, 0
_080D3250: .4byte 0x0000037E
_080D3254:
	ldr r2, _080D328C @ =0x000003D1
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x1f
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl PlayerLink_PlayAnim
	adds r0, r4, #0
	bl FUN_080d2ed0
	cmp r0, #0
	beq _080D3330
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl PlayerLink_SetAction
	b _080D3330
	.align 2, 0
_080D328C: .4byte 0x000003D1
_080D3290:
	ldr r2, _080D331C @ =0x000003D1
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D32B2
	ldr r2, _080D3320 @ =0x00000A76
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
_080D32B2:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D32E4
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D32E4
	adds r0, r4, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D32E4
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x2c
	adds r0, r4, #0
	bl FUN_080ccd5c
_080D32E4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x1f
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl PlayerLink_PlayAnim
	cmp r0, #0
	beq _080D3330
	ldr r2, _080D3320 @ =0x00000A76
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080D3324
	movs r0, #0
	strb r0, [r1]
_080D330E:
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl PlayerLink_SetAction
	b _080D3330
	.align 2, 0
_080D331C: .4byte 0x000003D1
_080D3320: .4byte 0x00000A76
_080D3324:
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
_080D3330:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
