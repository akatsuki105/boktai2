	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r0, _080A75F0 @ =0x0000CB05
	ldr r1, _080A75F4 @ =0x0000B343
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _080A75E8
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r4, r5, r0
	adds r1, r4, #0
	adds r0, r2, #0
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldr r2, _080A75F8 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	ldr r1, _080A75FC @ =0x0000FFF8
	orrs r0, r1
	adds r1, #7
	ands r0, r1
	ldr r1, _080A7600 @ =0xFFF80000
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	movs r7, #0xae
	lsls r7, r7, #2
	adds r0, r5, r7
	ldr r3, _080A7604 @ =0x00001091
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0x87
	bl FUN_0822f4d8
	ldr r0, _080A7608 @ =0x03003584
	ldr r0, [r0]
	ldr r3, _080A760C @ =0x00005520
	adds r0, r0, r3
	movs r6, #0xc6
	lsls r6, r6, #2
	adds r4, r5, r6
	ldr r2, _080A7610 @ =0x04000008
	adds r1, r4, #0
	bl CpuSet
	adds r7, #0x3a
	adds r1, r5, r7
	movs r2, #0
	ldr r0, _080A7614 @ =0x000002A9
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	ldr r3, _080A7618 @ =0x00000343
	adds r0, r5, r3
	strb r2, [r0]
_080A75E8:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A75F0: .4byte 0x0000CB05
_080A75F4: .4byte 0x0000B343
_080A75F8: .4byte 0xFFFF0000
_080A75FC: .4byte 0x0000FFF8
_080A7600: .4byte 0xFFF80000
_080A7604: .4byte 0x00001091
_080A7608: .4byte 0x03003584
_080A760C: .4byte 0x00005520
_080A7610: .4byte 0x04000008
_080A7614: .4byte 0x000002A9
_080A7618: .4byte 0x00000343
