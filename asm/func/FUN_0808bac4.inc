	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	bl FUN_0808ba64
	ldr r1, _0808BB14 @ =0x03003584
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r0, _0808BB18 @ =0x000009B8
	adds r2, r7, r0
	movs r3, #0xf
_0808BADC:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _0808BADC
	ldr r2, _0808BB1C @ =0x000009DE
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #5
	bls _0808BB08
	b _0808C020
_0808BB08:
	lsls r0, r0, #2
	ldr r1, _0808BB20 @ =_0808BB24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808BB14: .4byte 0x03003584
_0808BB18: .4byte 0x000009B8
_0808BB1C: .4byte 0x000009DE
_0808BB20: .4byte _0808BB24
_0808BB24: @ jump table
	.4byte _0808BB3C @ case 0
	.4byte _0808BB84 @ case 1
	.4byte _0808BC18 @ case 2
	.4byte _0808BD68 @ case 3
	.4byte _0808BE9C @ case 4
	.4byte _0808BBC8 @ case 5
_0808BB3C:
	ldr r0, _0808BB74 @ =0x000024CC
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xb6
	lsls r1, r1, #4
	adds r2, r7, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r2, _0808BB78 @ =0x0000250C
	adds r1, r7, r2
	ldr r3, _0808BB7C @ =0x000009B8
	adds r0, r7, r3
	str r0, [r1]
	ldr r4, _0808BB80 @ =0x000024C4
	adds r0, r7, r4
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r2, #0
	str r2, [sp]
	movs r2, #4
	b _0808BBFE
	.align 2, 0
_0808BB74: .4byte 0x000024CC
_0808BB78: .4byte 0x0000250C
_0808BB7C: .4byte 0x000009B8
_0808BB80: .4byte 0x000024C4
_0808BB84:
	ldr r3, _0808BBBC @ =0x000024CC
	adds r2, r7, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r4, #0xb6
	lsls r4, r4, #4
	adds r2, r7, r4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0808BBC0 @ =0x0000250C
	adds r1, r7, r0
	ldr r2, _0808BBC4 @ =0x000009B8
	adds r0, r7, r2
	str r0, [r1]
	subs r3, #8
	adds r0, r7, r3
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r2, #0
	str r2, [sp]
	movs r2, #0xcb
	b _0808BBFE
	.align 2, 0
_0808BBBC: .4byte 0x000024CC
_0808BBC0: .4byte 0x0000250C
_0808BBC4: .4byte 0x000009B8
_0808BBC8:
	ldr r0, _0808BC08 @ =0x000024CC
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xb6
	lsls r1, r1, #4
	adds r2, r7, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r2, _0808BC0C @ =0x0000250C
	adds r1, r7, r2
	ldr r3, _0808BC10 @ =0x000009B8
	adds r0, r7, r3
	str r0, [r1]
	ldr r4, _0808BC14 @ =0x000024C4
	adds r0, r7, r4
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r7, r2
	adds r2, #0xa2
	movs r3, #0
	str r3, [sp]
_0808BBFE:
	movs r3, #1
	bl MainSprite_SetAnim
	b _0808C020
	.align 2, 0
_0808BC08: .4byte 0x000024CC
_0808BC0C: .4byte 0x0000250C
_0808BC10: .4byte 0x000009B8
_0808BC14: .4byte 0x000024C4
_0808BC18:
	ldr r3, _0808BCA4 @ =0x00000B8C
	adds r4, r7, r3
	ldr r1, _0808BCA8 @ =0x0000DA6D
	adds r0, r4, #0
	bl Video_GetAuxSprite
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r5, r7, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0822a4fc
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	ldr r2, _0808BCAC @ =0x00000B7E
	adds r1, r7, r2
	movs r0, #0x60
	strh r0, [r1]
	ldr r3, _0808BCB0 @ =0x000024CC
	adds r1, r7, r3
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	ldr r0, _0808BCB4 @ =0x00000B98
	adds r1, r7, r0
	ldr r2, _0808BCB8 @ =0x000009B8
	adds r0, r7, r2
	str r0, [r1]
	ldr r3, _0808BCBC @ =0x00000BA8
	adds r6, r7, r3
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r1, [r0]
	str r4, [sp]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #1
	bl AuxAnim_RestartAnim
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r6, #4]
	adds r1, r4, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r4
	cmp r1, r0
	beq _0808BCC0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0808BCC8
	.align 2, 0
_0808BCA4: .4byte 0x00000B8C
_0808BCA8: .4byte 0x0000DA6D
_0808BCAC: .4byte 0x00000B7E
_0808BCB0: .4byte 0x000024CC
_0808BCB4: .4byte 0x00000B98
_0808BCB8: .4byte 0x000009B8
_0808BCBC: .4byte 0x00000BA8
_0808BCC0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0808BCC8:
	str r0, [r5]
	ldrb r0, [r6, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0808BCEC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0808BCF4
_0808BCEC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0808BCF4:
	str r0, [r5]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	ldr r3, _0808BD2C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r4, [r6, #7]
	cmp r0, r4
	bhs _0808BD0C
	b _0808C020
_0808BD0C:
	movs r0, #0
	strh r0, [r6, #0xe]
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0808BD30
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _0808BD26
	ldrb r0, [r6, #5]
_0808BD26:
	subs r0, #1
	strh r0, [r6, #8]
	b _0808BD40
	.align 2, 0
_0808BD2C: .4byte 0x0000FFFF
_0808BD30:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	ands r0, r2
	ldrb r2, [r6, #5]
	cmp r0, r2
	blo _0808BD40
	strh r1, [r6, #8]
_0808BD40:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r6, #6]
	ldrb r1, [r6, #6]
	ldrh r0, [r6, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r6, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808BD62
	b _0808C020
_0808BD62:
	movs r0, #1
	strb r0, [r6, #7]
	b _0808C020
_0808BD68:
	ldr r3, _0808BDF4 @ =0x00000B8C
	adds r4, r7, r3
	ldr r1, _0808BDF8 @ =0x0000D495
	adds r0, r4, #0
	bl Video_GetAuxSprite
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r5, r7, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0822a4fc
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	ldr r2, _0808BDFC @ =0x00000B7E
	adds r1, r7, r2
	movs r2, #0
	movs r0, #0x70
	strh r0, [r1]
	ldr r3, _0808BE00 @ =0x000024CC
	adds r1, r7, r3
	ldr r0, [r1]
	movs r6, #1
	orrs r0, r6
	str r0, [r1]
	ldr r4, _0808BE04 @ =0x00000B98
	adds r1, r7, r4
	ldr r3, _0808BE08 @ =0x000009B8
	adds r0, r7, r3
	str r0, [r1]
	ldr r0, _0808BE0C @ =0x00000BA8
	adds r4, r7, r0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	movs r3, #0xd4
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r1, [r0]
	str r2, [sp]
	adds r0, r4, #0
	movs r3, #4
	bl AuxAnim_RestartAnim
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	adds r1, r6, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r6
	cmp r1, r0
	beq _0808BE10
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0808BE18
	.align 2, 0
_0808BDF4: .4byte 0x00000B8C
_0808BDF8: .4byte 0x0000D495
_0808BDFC: .4byte 0x00000B7E
_0808BE00: .4byte 0x000024CC
_0808BE04: .4byte 0x00000B98
_0808BE08: .4byte 0x000009B8
_0808BE0C: .4byte 0x00000BA8
_0808BE10:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0808BE18:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0808BE3C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0808BE44
_0808BE3C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0808BE44:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0808BE7C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	bhs _0808BE5C
	b _0808C020
_0808BE5C:
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0808BE80
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0808BE76
	ldrb r0, [r4, #5]
_0808BE76:
	subs r0, #1
	strh r0, [r4, #8]
	b _0808BE90
	.align 2, 0
_0808BE7C: .4byte 0x0000FFFF
_0808BE80:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0808BE90
	strh r1, [r4, #8]
_0808BE90:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	b _0808C006
_0808BE9C:
	ldr r3, _0808BF0C @ =0x00000B8C
	adds r5, r7, r3
	ldr r1, _0808BF10 @ =0x00002499
	adds r0, r5, #0
	bl Video_GetAuxSprite
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r4, r7, r0
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822a4fc
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r2, _0808BF14 @ =0x00000B7E
	adds r1, r7, r2
	movs r3, #0
	movs r0, #0x60
	strh r0, [r1]
	ldr r4, _0808BF18 @ =0x000024CC
	adds r2, r7, r4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0808BF1C @ =0x00000B98
	adds r1, r7, r0
	ldr r2, _0808BF20 @ =0x000009B8
	adds r0, r7, r2
	str r0, [r1]
	movs r4, #0x9e
	lsls r4, r4, #4
	adds r0, r7, r4
	ldr r1, [r0]
	ldr r0, _0808BF24 @ =0x00000387
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #5
	bne _0808BF2C
	ldr r4, _0808BF28 @ =0x00000BA8
	adds r0, r7, r4
	movs r4, #0xd5
	lsls r4, r4, #2
	adds r1, r1, r4
	ldr r1, [r1]
	ldrb r2, [r2]
	str r3, [sp]
	movs r3, #4
	bl AuxAnim_RestartAnim
	b _0808BF42
	.align 2, 0
_0808BF0C: .4byte 0x00000B8C
_0808BF10: .4byte 0x00002499
_0808BF14: .4byte 0x00000B7E
_0808BF18: .4byte 0x000024CC
_0808BF1C: .4byte 0x00000B98
_0808BF20: .4byte 0x000009B8
_0808BF24: .4byte 0x00000387
_0808BF28: .4byte 0x00000BA8
_0808BF2C:
	ldr r4, _0808BF78 @ =0x00000BA8
	adds r0, r7, r4
	movs r4, #0xd5
	lsls r4, r4, #2
	adds r1, r1, r4
	ldr r1, [r1]
	ldrb r2, [r2]
	str r3, [sp]
	movs r3, #0
	bl AuxAnim_RestartAnim
_0808BF42:
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r5, r7, r0
	ldr r1, _0808BF78 @ =0x00000BA8
	adds r4, r7, r1
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0808BF7C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0808BF84
	.align 2, 0
_0808BF78: .4byte 0x00000BA8
_0808BF7C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0808BF84:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0808BFA8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0808BFB0
_0808BFA8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0808BFB0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0808BFE8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0808C020
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0808BFEC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0808BFE0
	ldrb r0, [r4, #5]
_0808BFE0:
	subs r0, #1
	strh r0, [r4, #8]
	b _0808BFFC
	.align 2, 0
_0808BFE8: .4byte 0x0000FFFF
_0808BFEC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0808BFFC
	strh r1, [r4, #8]
_0808BFFC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
_0808C006:
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0808C020
	movs r0, #1
	strb r0, [r4, #7]
_0808C020:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
