	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x18
	movs r7, #0
	ldr r0, _0802287C @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r6, #0
	adds r0, #0x1e
	b _08022968
	.align 2, 0
_0802287C: .4byte 0x03002B4C
_08022880:
	ldr r0, _080228B0 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #7
	bhi _0802295E
	lsls r0, r0, #2
	ldr r1, _080228B4 @ =_080228B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080228B0: .4byte 0x03002B4C
_080228B4: .4byte _080228B8
_080228B8: @ jump table
	.4byte _080228D8 @ case 0
	.4byte _080228E4 @ case 1
	.4byte _080228F0 @ case 2
	.4byte _080228FC @ case 3
	.4byte _08022908 @ case 4
	.4byte _08022914 @ case 5
	.4byte _08022920 @ case 6
	.4byte _08022934 @ case 7
_080228D8:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08022668
	b _0802292A
_080228E4:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080226a8
	b _0802292A
_080228F0:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08022704
	b _0802292A
_080228FC:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08022770
	b _0802292A
_08022908:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080227f4
	b _0802292A
_08022914:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0802284c
	b _0802292A
_08022920:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0802285c
_0802292A:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08022488
	b _0802295E
_08022934:
	ldrh r0, [r4, #8]
	ldr r3, _0802297C @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r0
	str r1, [sp]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _08022980 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	ldrh r1, [r4, #0xc]
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	adds r1, r5, #0
	bl FUN_0805f68c
_0802295E:
	adds r7, #1
	ldr r0, _08022984 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r5, #6
_08022968:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r7, r0
	blt _08022880
	movs r0, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802297C: .4byte 0xFFFF0000
_08022980: .4byte 0x0000FFFF
_08022984: .4byte 0x03002B4C
