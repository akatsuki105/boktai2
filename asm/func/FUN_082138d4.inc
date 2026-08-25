	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0x78
	ldr r0, _08213950 @ =0x0000CB05
	ldr r1, _08213954 @ =0x0000B343
	bl GetFile
	adds r1, r0, #0
	adds r2, r6, #0
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r0, r6, #0
	bl OpenSpriteSetFile
	add r5, sp, #0x14
	movs r4, #0
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _08213958 @ =0x05000002
	bl CpuSet
	ldr r0, _0821395C @ =0x0000FFF8
	strh r0, [r5]
	subs r0, #0x38
	strh r0, [r5, #2]
	adds r0, r7, #0
	adds r0, #0x98
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x94
	movs r3, #0x10
	bl FUN_0822f3fc
	ldr r0, [r6, #0x28]
	movs r1, #1
	orrs r0, r1
	str r0, [r6, #0x28]
	movs r0, #3
	movs r1, #0xa
	movs r2, #0x18
	movs r3, #2
	bl FUN_0804a084
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r7, r5
	str r0, [r1]
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08213950: .4byte 0x0000CB05
_08213954: .4byte 0x0000B343
_08213958: .4byte 0x05000002
_0821395C: .4byte 0x0000FFF8
