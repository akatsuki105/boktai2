	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r1, _080ECA94 @ =0x000001DF
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _080ECB0E
	movs r1, #8
	ldr r0, [r4, #0x2c]
	ands r0, r1
	cmp r0, #0
	beq _080ECA98
	movs r0, #1
	b _080ECA9A
	.align 2, 0
_080ECA94: .4byte 0x000001DF
_080ECA98:
	movs r0, #0
_080ECA9A:
	cmp r0, #0
	bne _080ECABC
	bl FUN_080db520
	adds r2, r0, #0
	str r2, [r4, #0x34]
	cmp r2, #0
	bne _080ECAAC
	b _080ECBDC
_080ECAAC:
	movs r1, #8
	ldr r0, [r4, #0x2c]
	orrs r0, r1
	str r0, [r4, #0x2c]
	ldrh r1, [r2, #0x10]
	adds r0, r4, #0
	adds r0, #0x54
	strh r1, [r0]
_080ECABC:
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r6, r0
	ldr r0, [r4, #0x34]
	str r0, [r1]
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #1
	bne _080ECB3E
	movs r1, #0x10
	ldr r0, [r4, #0x2c]
	ands r0, r1
	cmp r0, #0
	beq _080ECAE0
	movs r0, #1
	b _080ECAE2
_080ECAE0:
	movs r0, #0
_080ECAE2:
	cmp r0, #0
	bne _080ECB02
	bl FUN_081e8d0c
	adds r2, r0, #0
	str r2, [r4, #0x38]
	cmp r2, #0
	beq _080ECBDC
	movs r0, #0x10
	ldr r1, [r4, #0x2c]
	orrs r1, r0
	str r1, [r4, #0x2c]
	ldrh r0, [r2, #0x10]
	adds r1, r4, #0
	adds r1, #0x56
	strh r0, [r1]
_080ECB02:
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r6, r0
	ldr r0, [r4, #0x38]
	str r0, [r1]
	b _080ECB3E
_080ECB0E:
	movs r1, #0x20
	ldr r0, [r4, #0x2c]
	ands r0, r1
	cmp r0, #0
	beq _080ECB1C
	movs r0, #1
	b _080ECB1E
_080ECB1C:
	movs r0, #0
_080ECB1E:
	cmp r0, #0
	bne _080ECB3E
	bl FUN_080da848
	adds r2, r0, #0
	str r2, [r4, #0x3c]
	cmp r2, #0
	beq _080ECBDC
	movs r1, #0x20
	ldr r0, [r4, #0x2c]
	orrs r0, r1
	str r0, [r4, #0x2c]
	ldrh r1, [r2, #0x10]
	adds r0, r4, #0
	adds r0, #0x58
	strh r1, [r0]
_080ECB3E:
	ldr r1, _080ECB68 @ =0x000001DF
	adds r5, r6, r1
	ldrb r0, [r5]
	cmp r0, #3
	bne _080ECB50
	movs r0, #0
	movs r1, #0
	bl FUN_080dbe54
_080ECB50:
	ldrb r0, [r5]
	cmp r0, #0xe
	bne _080ECBDC
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r4, #0x2c]
	ands r0, r1
	cmp r0, #0
	beq _080ECB6C
	movs r0, #1
	b _080ECB6E
	.align 2, 0
_080ECB68: .4byte 0x000001DF
_080ECB6C:
	movs r0, #0
_080ECB6E:
	cmp r0, #0
	bne _080ECB94
	movs r0, #0
	movs r1, #0
	bl FUN_081ea120
	adds r2, r0, #0
	str r2, [r4, #0x4c]
	cmp r2, #0
	beq _080ECBDC
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r4, #0x2c]
	orrs r0, r1
	str r0, [r4, #0x2c]
	ldrh r1, [r2, #0x10]
	adds r0, r4, #0
	adds r0, #0x60
	strh r1, [r0]
_080ECB94:
	movs r0, #0x99
	lsls r0, r0, #2
	adds r1, r6, r0
	ldr r0, [r4, #0x4c]
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x2c]
	ands r0, r1
	cmp r0, #0
	beq _080ECBAE
	movs r0, #1
	b _080ECBB0
_080ECBAE:
	movs r0, #0
_080ECBB0:
	cmp r0, #0
	bne _080ECBD2
	bl FUN_081ea820
	adds r2, r0, #0
	str r2, [r4, #0x50]
	cmp r2, #0
	beq _080ECBDC
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r1, [r4, #0x2c]
	orrs r1, r0
	str r1, [r4, #0x2c]
	ldrh r0, [r2, #0x10]
	adds r1, r4, #0
	adds r1, #0x62
	strh r0, [r1]
_080ECBD2:
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r6, r0
	ldr r0, [r4, #0x50]
	str r0, [r1]
_080ECBDC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
