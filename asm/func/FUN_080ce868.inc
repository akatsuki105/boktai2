	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r6, r4, r0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080CE8FC
	ldr r2, _080CE8EC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0xaa
	orrs r0, r3
	ldr r1, _080CE8F0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, _080CE8F4 @ =0xFFEC0000
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldr r2, _080CE8F8 @ =0x00002101
	adds r1, r4, #0
	adds r1, #0x28
	movs r0, #0x80
	lsls r0, r0, #9
	ldrb r1, [r1]
	lsls r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	movs r0, #2
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #0x32
	movs r3, #0x10
	bl Hitbox_SetAttack
	adds r0, r6, #0
	movs r1, #0
	adds r2, r4, #0
	bl Hitbox_SetHandler
	b _080CEA82
	.align 2, 0
_080CE8EC: .4byte 0xFFFF0000
_080CE8F0: .4byte 0x0000FFFF
_080CE8F4: .4byte 0xFFEC0000
_080CE8F8: .4byte 0x00002101
_080CE8FC:
	ldr r1, _080CE914 @ =0x00000A75
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _080CE908
	b _080CEA82
_080CE908:
	lsls r0, r0, #2
	ldr r1, _080CE918 @ =_080CE91C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080CE914: .4byte 0x00000A75
_080CE918: .4byte _080CE91C
_080CE91C: @ jump table
	.4byte _080CE930 @ case 0
	.4byte _080CE968 @ case 1
	.4byte _080CE99C @ case 2
	.4byte _080CE9D0 @ case 3
	.4byte _080CEA08 @ case 4
_080CE930:
	movs r3, #0
	movs r2, #0x5a
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x32
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r2, sp, #0x14
	strh r3, [r2]
	ldr r0, _080CE95C @ =0x0000FFE7
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	movs r5, #1
	ldr r3, _080CE960 @ =0x00000A7C
	adds r1, r4, r3
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, _080CE964 @ =0x00000A7E
	adds r1, r4, r0
	movs r0, #0x14
	b _080CEA32
	.align 2, 0
_080CE95C: .4byte 0x0000FFE7
_080CE960: .4byte 0x00000A7C
_080CE964: .4byte 0x00000A7E
_080CE968:
	movs r3, #0
	movs r2, #0x3c
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x64
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r2, sp, #0x14
	strh r3, [r2]
	strh r3, [r2, #2]
	strh r3, [r2, #4]
	movs r5, #2
	ldr r3, _080CE994 @ =0x00000A7C
	adds r1, r4, r3
	movs r0, #0x40
	strh r0, [r1]
	ldr r0, _080CE998 @ =0x00000A7E
	adds r1, r4, r0
	movs r0, #0x28
	b _080CEA32
	.align 2, 0
_080CE994: .4byte 0x00000A7C
_080CE998: .4byte 0x00000A7E
_080CE99C:
	movs r3, #0
	movs r2, #0x50
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x46
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r2, sp, #0x14
	strh r3, [r2]
	movs r0, #0x1e
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	movs r5, #4
	ldr r3, _080CE9C8 @ =0x00000A7C
	adds r1, r4, r3
	movs r0, #0x30
	strh r0, [r1]
	ldr r0, _080CE9CC @ =0x00000A7E
	adds r1, r4, r0
	movs r0, #0x28
	b _080CEA32
	.align 2, 0
_080CE9C8: .4byte 0x00000A7C
_080CE9CC: .4byte 0x00000A7E
_080CE9D0:
	movs r3, #0
	movs r2, #0x3c
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x64
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r2, sp, #0x14
	strh r3, [r2]
	ldr r0, _080CE9FC @ =0x0000FFB0
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	movs r5, #8
	ldr r3, _080CEA00 @ =0x00000A7C
	adds r1, r4, r3
	movs r0, #1
	strh r0, [r1]
	ldr r0, _080CEA04 @ =0x00000A7E
	adds r1, r4, r0
	movs r0, #0x14
	b _080CEA32
	.align 2, 0
_080CE9FC: .4byte 0x0000FFB0
_080CEA00: .4byte 0x00000A7C
_080CEA04: .4byte 0x00000A7E
_080CEA08:
	movs r3, #0
	movs r2, #0x3c
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x32
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r2, sp, #0x14
	strh r3, [r2]
	ldr r0, _080CEA8C @ =0x0000FFE7
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	movs r5, #0x10
	ldr r3, _080CEA90 @ =0x00000A7C
	adds r1, r4, r3
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, _080CEA94 @ =0x00000A7E
	adds r1, r4, r0
	movs r0, #0x1e
_080CEA32:
	strh r0, [r1]
	adds r3, r2, #0
	ldr r2, _080CEA98 @ =0x00002101
	adds r1, r4, #0
	adds r1, #0x28
	movs r0, #0x80
	lsls r0, r0, #9
	ldrb r1, [r1]
	lsls r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r2, _080CEA9C @ =0x00000A7A
	adds r0, r4, r2
	ldrh r1, [r0]
	ldr r3, _080CEA90 @ =0x00000A7C
	adds r0, r4, r3
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r3, #2
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r3, r5, #0
	bl Hitbox_SetAttack
	ldr r1, _080CEAA0 @ =FUN_080d1b68
	adds r0, r6, #0
	adds r2, r4, #0
	bl Hitbox_SetHandler
_080CEA82:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CEA8C: .4byte 0x0000FFE7
_080CEA90: .4byte 0x00000A7C
_080CEA94: .4byte 0x00000A7E
_080CEA98: .4byte 0x00002101
_080CEA9C: .4byte 0x00000A7A
_080CEAA0: .4byte FUN_080d1b68
