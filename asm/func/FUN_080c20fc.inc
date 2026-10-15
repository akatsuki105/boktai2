	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, [r7, #0x40]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x40]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0xd
	bhi _080C21DC
	lsls r0, r0, #2
	ldr r1, _080C2124 @ =_080C2128
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080C2124: .4byte _080C2128
_080C2128: @ jump table
	.4byte _080C2160 @ case 0
	.4byte _080C216A @ case 1
	.4byte _080C2176 @ case 2
	.4byte _080C2182 @ case 3
	.4byte _080C2182 @ case 4
	.4byte _080C218E @ case 5
	.4byte _080C219A @ case 6
	.4byte _080C21A6 @ case 7
	.4byte _080C21A6 @ case 8
	.4byte _080C21B2 @ case 9
	.4byte _080C21B2 @ case 10
	.4byte _080C21B2 @ case 11
	.4byte _080C21BE @ case 12
	.4byte _080C21CA @ case 13
_080C2160:
	ldr r0, [r7, #0x40]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x40]
	b _080C21E2
_080C216A:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0xf
	b _080C21D4
_080C2176:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x10
	b _080C21D4
_080C2182:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x11
	b _080C21D4
_080C218E:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x12
	b _080C21D4
_080C219A:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x13
	b _080C21D4
_080C21A6:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x14
	b _080C21D4
_080C21B2:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x15
	b _080C21D4
_080C21BE:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x16
	b _080C21D4
_080C21CA:
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0x17
_080C21D4:
	movs r3, #1
	bl MainSprite_SetPose
	b _080C21E2
_080C21DC:
	movs r0, #1
	orrs r1, r0
	str r1, [r7, #0x40]
_080C21E2:
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0xc
	bls _080C21F0
	b _080C24BC
_080C21F0:
	lsls r0, r0, #2
	ldr r1, _080C21FC @ =_080C2200
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080C21FC: .4byte _080C2200
_080C2200: @ jump table
	.4byte _080C2234 @ case 0
	.4byte _080C22B0 @ case 1
	.4byte _080C23B4 @ case 2
	.4byte _080C2430 @ case 3
	.4byte _080C2338 @ case 4
	.4byte _080C24BC @ case 5
	.4byte _080C24BC @ case 6
	.4byte _080C24BC @ case 7
	.4byte _080C24BC @ case 8
	.4byte _080C23B4 @ case 9
	.4byte _080C24BC @ case 10
	.4byte _080C24BC @ case 11
	.4byte _080C2338 @ case 12
_080C2234:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080C22AC @ =FUN_080c1b08
	b _080C24F8
	.align 2, 0
_080C22AC: .4byte FUN_080c1b08
_080C22B0:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl MainSprite_SetAnim
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl MainSprite_SetAnim
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetPose
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080C2334 @ =FUN_080c1b08
	b _080C24F8
	.align 2, 0
_080C2334: .4byte FUN_080c1b08
_080C2338:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #1
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl MainSprite_SetAnim
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080C23B0 @ =FUN_080c1b08
	b _080C24F8
	.align 2, 0
_080C23B0: .4byte FUN_080c1b08
_080C23B4:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x98
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xf8
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl MainSprite_SetAnim
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #3
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080C242C @ =FUN_080c1b08
	b _080C24F8
	.align 2, 0
_080C242C: .4byte FUN_080c1b08
_080C2430:
	adds r2, r7, #0
	adds r2, #0xa0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	adds r0, #0x98
	adds r5, r7, #0
	adds r5, #0x18
	movs r6, #0
	str r6, [sp]
	adds r1, r5, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	adds r1, r7, #0
	adds r1, #0xb8
	movs r0, #0x3c
	strh r0, [r1]
	adds r1, #2
	ldr r0, _080C24B4 @ =0x0000FFE2
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r1, r5, #0
	movs r2, #1
	movs r3, #1
	bl MainSprite_SetPose
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, _080C24B8 @ =0x0000FFBF
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x28
	strh r0, [r1]
	subs r2, #0x18
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r7, r1
	str r6, [r0]
	b _080C24FA
	.align 2, 0
_080C24B4: .4byte 0x0000FFE2
_080C24B8: .4byte 0x0000FFBF
_080C24BC:
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	bl FUN_080c1f5c
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0
_080C24F8:
	str r0, [r1]
_080C24FA:
	movs r0, #0x88
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
