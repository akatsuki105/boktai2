	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r6, r5, r0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080643EE
	b _080645F0
_080643EE:
	ldr r2, _08064404 @ =0x00000A75
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _080643FA
	b _08064648
_080643FA:
	lsls r0, r0, #2
	ldr r1, _08064408 @ =_0806440C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08064404: .4byte 0x00000A75
_08064408: .4byte _0806440C
_0806440C: @ jump table
	.4byte _08064420 @ case 0
	.4byte _08064470 @ case 1
	.4byte _080644B0 @ case 2
	.4byte _080644F4 @ case 3
	.4byte _08064544 @ case 4
_08064420:
	ldr r3, _0806445C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x5a
	orrs r0, r2
	ldr r1, _08064460 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x10]
	ldr r0, _08064464 @ =0xFFE70000
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r3
	str r0, [r2, #4]
	movs r4, #1
	ldr r3, _08064468 @ =0x00000A7C
	adds r1, r5, r3
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, _0806446C @ =0x00000A7E
	adds r1, r5, r0
	movs r0, #0xa
	b _0806457E
	.align 2, 0
_0806445C: .4byte 0xFFFF0000
_08064460: .4byte 0x0000FFFF
_08064464: .4byte 0xFFE70000
_08064468: .4byte 0x00000A7C
_0806446C: .4byte 0x00000A7E
_08064470:
	ldr r3, _080644A4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x3c
	orrs r0, r2
	ldr r1, _080644A8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r3
	str r0, [r2, #4]
	movs r4, #2
	ldr r3, _080644AC @ =0x00000A7C
	adds r1, r5, r3
	movs r0, #0x40
	b _08064576
	.align 2, 0
_080644A4: .4byte 0xFFFF0000
_080644A8: .4byte 0x0000FFFF
_080644AC: .4byte 0x00000A7C
_080644B0:
	ldr r3, _080644E8 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x50
	orrs r0, r2
	ldr r1, _080644EC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x8c
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x10]
	movs r0, #0xf0
	lsls r0, r0, #0xd
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r3
	str r0, [r2, #4]
	movs r4, #4
	ldr r3, _080644F0 @ =0x00000A7C
	adds r1, r5, r3
	movs r0, #0x30
	b _08064576
	.align 2, 0
_080644E8: .4byte 0xFFFF0000
_080644EC: .4byte 0x0000FFFF
_080644F0: .4byte 0x00000A7C
_080644F4:
	ldr r3, _08064530 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x3c
	orrs r0, r2
	ldr r1, _08064534 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x10]
	ldr r0, _08064538 @ =0xFFB00000
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r3
	str r0, [r2, #4]
	movs r4, #8
	ldr r3, _0806453C @ =0x00000A7C
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	ldr r0, _08064540 @ =0x00000A7E
	adds r1, r5, r0
	movs r0, #5
	b _0806457E
	.align 2, 0
_08064530: .4byte 0xFFFF0000
_08064534: .4byte 0x0000FFFF
_08064538: .4byte 0xFFB00000
_0806453C: .4byte 0x00000A7C
_08064540: .4byte 0x00000A7E
_08064544:
	ldr r3, _080645D0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x3c
	orrs r0, r2
	ldr r1, _080645D4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x10]
	ldr r0, _080645D8 @ =0xFFE70000
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r3
	str r0, [r2, #4]
	movs r4, #0x10
	ldr r3, _080645DC @ =0x00000A7C
	adds r1, r5, r3
	movs r0, #0x20
_08064576:
	strh r0, [r1]
	ldr r0, _080645E0 @ =0x00000A7E
	adds r1, r5, r0
	movs r0, #0x14
_0806457E:
	strh r0, [r1]
	adds r3, r2, #0
	ldr r2, _080645E4 @ =0x00002101
	adds r1, r5, #0
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
	bl FUN_0823646c
	ldr r2, _080645E8 @ =0x00000A7A
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _080645DC @ =0x00000A7C
	adds r0, r5, r3
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r3, r4, #0
	bl FUN_082364f8
	ldr r1, _080645EC @ =dark_django_0806f990
	adds r0, r6, #0
	adds r2, r5, #0
	bl FUN_0823651c
	b _08064648
	.align 2, 0
_080645D0: .4byte 0xFFFF0000
_080645D4: .4byte 0x0000FFFF
_080645D8: .4byte 0xFFE70000
_080645DC: .4byte 0x00000A7C
_080645E0: .4byte 0x00000A7E
_080645E4: .4byte 0x00002101
_080645E8: .4byte 0x00000A7A
_080645EC: .4byte dark_django_0806f990
_080645F0:
	movs r4, #0
	movs r2, #0xaa
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x32
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r3, sp, #0x14
	strh r4, [r3]
	ldr r0, _08064650 @ =0x0000FFEC
	strh r0, [r3, #2]
	strh r4, [r3, #4]
	ldr r2, _08064654 @ =0x00002101
	adds r1, r5, #0
	adds r1, #0x28
	adds r0, #0x14
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
	bl FUN_0823646c
	movs r0, #2
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #0x32
	movs r3, #0x10
	bl FUN_082364f8
	adds r0, r6, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0823651c
_08064648:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08064650: .4byte 0x0000FFEC
_08064654: .4byte 0x00002101
