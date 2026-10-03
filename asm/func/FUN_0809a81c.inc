	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _0809A8F4 @ =0x000009FC
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0809A8F8 @ =0x03003530
	str r1, [r0]
	ldr r2, _0809A8FC @ =0x03003E78
	ldr r0, _0809A900 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	ldr r1, _0809A904 @ =0xFFFFFDFF
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	movs r1, #0
	bl SetBGCharBaseDirect
	movs r0, #1
	bl GetTilemapBuffer
	adds r1, r0, #0
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r2, _0809A908 @ =0x04000200
	bl CpuSet
	ldr r1, _0809A90C @ =0x03003ED0
	adds r1, #0x30
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r1, _0809A910 @ =0x0400000A
	ldr r4, _0809A914 @ =0x000009B4
	adds r0, r5, r4
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0809A918 @ =0x0300449C
	movs r0, #1
	strh r0, [r1]
	ldr r1, _0809A91C @ =0x030044B4
	ldr r2, _0809A920 @ =0x00003B18
	adds r0, r5, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0809A924 @ =0x030044B0
	ldr r3, _0809A928 @ =0x00003B1A
	adds r0, r5, r3
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _0809A92C @ =0x03004498
	ldr r4, _0809A930 @ =0x00003B1B
	adds r0, r5, r4
	ldrb r0, [r0]
	strb r0, [r1]
	bl TextBox_Close
	bl FUN_08049f84
	ldr r0, _0809A934 @ =0x00004014
	adds r6, r5, r0
	movs r4, #1
_0809A8AE:
	ldm r6!, {r0}
	bl TextPanel_Hide
	subs r4, #1
	cmp r4, #0
	bge _0809A8AE
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r2, _0809A8FC @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, [r5, #0x18]
	ldr r0, [r5, #0x30]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0808a3c4
	movs r1, #0xa3
	lsls r1, r1, #4
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0809A938 @ =0x00000A31
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_0808ce98
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A8F4: .4byte 0x000009FC
_0809A8F8: .4byte 0x03003530
_0809A8FC: .4byte 0x03003E78
_0809A900: .4byte 0xFFFFFEFF
_0809A904: .4byte 0xFFFFFDFF
_0809A908: .4byte 0x04000200
_0809A90C: .4byte 0x03003ED0
_0809A910: .4byte 0x0400000A
_0809A914: .4byte 0x000009B4
_0809A918: .4byte 0x0300449C
_0809A91C: .4byte 0x030044B4
_0809A920: .4byte 0x00003B18
_0809A924: .4byte 0x030044B0
_0809A928: .4byte 0x00003B1A
_0809A92C: .4byte 0x03004498
_0809A930: .4byte 0x00003B1B
_0809A934: .4byte 0x00004014
_0809A938: .4byte 0x00000A31
