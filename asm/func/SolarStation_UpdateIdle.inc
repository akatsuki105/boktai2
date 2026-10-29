	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _0809EF98 @ =0x00000252
	adds r0, r4, r2
	movs r5, #0x2e
	ldrsh r1, [r3, r5]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bne _0809F024
	movs r5, #0x2c
	ldrsh r0, [r3, r5]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r2, r0, r1
	cmp r2, #0
	bge _0809EF6A
	rsbs r2, r2, #0
_0809EF6A:
	movs r1, #0x30
	ldrsh r0, [r3, r1]
	movs r5, #0x95
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	cmp r0, #0
	bge _0809EF80
	rsbs r0, r0, #0
_0809EF80:
	cmp r2, #0x80
	bgt _0809F024
	cmp r0, #0x80
	bgt _0809F024
	ldr r1, [r3, #0x1c]
	cmp r1, #1
	beq _0809EF9C
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r4, r2
	b _0809F02A
	.align 2, 0
_0809EF98: .4byte 0x00000252
_0809EF9C:
	movs r5, #0x98
	lsls r5, r5, #2
	adds r0, r4, r5
	strb r1, [r0]
	ldr r0, _0809F018 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _0809EFB8
	ldr r0, _0809F01C @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _0809EFB8
	movs r1, #1
_0809EFB8:
	cmp r1, #0
	bne _0809F02E
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r3, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _0809F02E
	cmp r0, #3
	beq _0809F02E
	cmp r0, #4
	beq _0809F02E
	movs r5, #0xe0
	lsls r5, r5, #2
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F02E
	adds r1, #0x34
	adds r0, r3, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809F02E
	adds r2, #0x24
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #7
	bne _0809F02E
	movs r5, #0x94
	lsls r5, r5, #2
	adds r1, r4, r5
	ldr r2, _0809F020 @ =0x00000262
	adds r0, r4, r2
	ldrh r2, [r0]
	adds r0, r3, #0
	bl FUN_0807a528
	adds r5, #0xe
	adds r1, r4, r5
	movs r0, #1
	b _0809F02C
	.align 2, 0
_0809F018: .4byte 0x03002B8C
_0809F01C: .4byte 0x03002B60
_0809F020: .4byte 0x00000262
_0809F024:
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r4, r0
_0809F02A:
	movs r0, #0
_0809F02C:
	strb r0, [r1]
_0809F02E:
	pop {r4, r5}
	pop {r0}
	bx r0
